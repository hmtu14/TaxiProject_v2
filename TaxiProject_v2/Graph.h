#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <cmath>
#include <stack>
#include "Trajectory.h"
#include "Coord.h"
#include "ParkingPlace.h"
using namespace std;
#define WAIT_TIME_PARKINGPLACE 10*60
#define CROSS_TIME_ROADSEGMENT 4*60
#define DELTA_TIME 15*60
#define TAU_TIME DELTA_TIME/3


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
};


class Graph
{
private:
	vector<vector<Edge*>> m_AdjList;
	vector<Node*> m_NodeList;
	vector<Edge*> m_EdgeList;
	Status* root;
	vector<Trajectory> m_Trajectory;
private:
	double m_CurPr;
public:
	Graph() {};
	Graph(string nodefile, string edgefile);
	double calculateProbability(vector<int> Route,ParkingPlace parking, DateTime currentTime);

public:
	void addEdge(int ide, Node*& u,Node*& v);
	void buildStatusTree(Status*& root,vector<Edge*> Route, int layer, DateTime currentTime);
	void traversalTree(Status*& root);
	void traversalTreeCalculate(Status* root,ParkingPlace parking, vector<double>& Probs, vector<Status*>& Path);
	double probabilityOnRoute(Status* status);
	double probabilityOnParking(ParkingPlace parking, DateTime currentTime);
	int findCenterParkingPlace(ParkingPlace parking);


};