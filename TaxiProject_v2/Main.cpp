#include <iostream>
#include <fstream>
#include <vector>
#include "Trajectory.h"
#include "Graph.h"
#include <string>
using namespace std;


int main() {
	Graph G(".\\data_graph\\nodes.csv", ".\\data_graph\\edges.csv");
	G.initTrajectory();
	cout << "Doc xong du lieu!" << endl;
	vector<int> edge;
	edge.push_back(1);
	edge.push_back(2);
	edge.push_back(3);
	ParkingPlace p;
	G.calculateProbability(edge, p, DateTime(0, 30, 12));
	cout << "Tinh xong xac suat!" << endl;



}