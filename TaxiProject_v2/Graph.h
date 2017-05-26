#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
#include <queue>
#include "Trajectory.h"
#include "Coord.h"
#include "ParkingPlace.h"
using namespace std;
#define WAIT_TIME_PARKINGPLACE (10*60)
#define CROSS_TIME_ROADSEGMENT (4*60)
#define DELTA_TIME (10*60)
#define TAU_TIME (DELTA_TIME/2)


struct Node
{
	int nodeID;
	Coord coord;
	Node() {};
	Node(int id, double Latitude, double Longitude)
	{
		nodeID = id;
		coord.Latitude = Latitude;
		coord.Longitude = Longitude;
	}
};


struct Edge
{
	int edgeID;
	Node* u;
	Node* v;
	double weight;
	DateTime time;
	Edge() {};
	Edge(Node* uu, Node* vv) : u(uu), v(vv) {};
	Edge(Node* uu, Node* vv, double w) : u(uu), v(vv), weight(w) {};
};



/*
Calculate probability
*/
struct Status {
	int edgeID; //edgeID hiện tại
	int decisionPrev; // 1 : forward ----- 2:backward ---- 0: root
	DateTime startTime; // Thời gian bắt đầu edgeID
	DateTime endTime; // Thời gian kết thúc edgeID 
	Status* pLeft;
	Status* pRight;
	Status* pParent;
	double Pr;
};


class Graph
{
private:
	vector<vector<Edge*>> m_AdjList;
	vector<Node*> m_NodeList;
	vector<Edge*> m_EdgeList;
	Status* root;
	vector<Trajectory> m_Trajectory;
	vector<ParkingPlace> m_Parking;
private:
	double m_PrS;
public:
	Graph() {};
	Graph(string nodefile, string edgefile);
	double calculateProbability(vector<int> Route,ParkingPlace parking, DateTime currentTime);
	void initTrajectory();

public:
	void addEdge(int ide, Node*& u,Node*& v);
	void buildStatusTree(Status*& root,vector<Edge*> Route, int layer, DateTime currentTime); //Xây dựng khung cây
	void traversalTree(Status*& root); // Gán nhãn thời gian cho cây
	void traversalTreeCalculate(Status*& root,ParkingPlace parking); // Xác suất bắt được khách khi thực hiện hành động đi đến một parking place
	double probabilityOnRoute(Status* status); //Xác suất bắt được khách ở Route
	double probabilityOnParking(ParkingPlace parking, DateTime currentTime); //Xác suất bắt được khách tại Parking Place
	int findCenterParkingPlace(ParkingPlace parking); //Trả về id node trung tâm của parking place
	vector<int> findParkingForRecommender(Coord currentPos, int k); //Trả về vector id node trung tâm của k parking gần nhất
	int findNearestNode(Coord currentPos); //Trả về Id của node gần với vị trí hiện tại nhất
	pair<double, vector<int>> Dijkstra(int s, int t);
	
};