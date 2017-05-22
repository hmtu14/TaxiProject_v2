#pragma once
#include "Graph.h"

double realDistance(Node*& u, Node*& v)
{
	double dlong = abs(u->coord.Latitude - v->coord.Latitude);
	double cosD = (sin(u->coord.Longitude)*sin(v->coord.Longitude) + cos(u->coord.Longitude)*cos(v->coord.Longitude)*cos(dlong));
	double D = acos(cosD);
	return 1.852*D*60;
}

Graph::Graph(string nodefile, string edgefile)
{
	ifstream nFile(nodefile);
	ifstream eFile(edgefile);

	string line;
	
	//Read Node File
	getline(nFile, line);
	m_NodeList.push_back(new Node());
	while (getline(nFile, line))
	{
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		int id;
		double lat, lng;
		ss >> id >> lat >> lng;
		Node* u = new Node(id, lat, lng);
		m_NodeList.push_back(u);
	}

	// Read Edge File
	m_AdjList.resize(m_NodeList.size() + 5);
	getline(eFile, line);
	m_EdgeList.push_back(new Edge());
	int edgeId = 1;
	while (getline(eFile, line))
	{
		replace(line.begin(), line.end(), ',', ' ');
		stringstream ss(line);
		int pos, idStart, idEnd, status;
		ss >> pos >> idStart >> idEnd >> status;
		Node* u = m_NodeList[idStart];
		Node* v = m_NodeList[idEnd];
		addEdge(edgeId, u, v);
		++edgeId;
		if (status == 0) {
			addEdge(edgeId, v, u);
			++edgeId;
		}
	}
	nFile.close();
	eFile.close();
}


void Graph::addEdge(int ide, Node*& u, Node*& v)
{
	Edge* edge = new Edge(u, v);
	edge->edgeID = ide;
	edge->weight = realDistance(u, v);
	edge->time = DateTime(edge->weight * 3600 / 40 );
	m_EdgeList.push_back(edge);
	m_AdjList[u->nodeID].push_back(edge);
}

/*
	Hàm tính xác suât khi đưa vào một Route và thời điểm hiện tại
*/
double Graph::calculateProbability(vector<int> edgeList, ParkingPlace parking, DateTime currentTime)
{
	vector<Edge*> Route;
	for (int i = 0; i < edgeList.size(); ++i) {
		Route.push_back(m_EdgeList[edgeList[i]]);
	}
	int N = Route.size();
	int layer = 0;
	buildStatusTree(root,Route, layer,currentTime);
	traversalTree(root);
	vector<double> Probs;
	vector<Status*> Path;
	m_CurPr = 1;
	traversalTreeCalculate(root, parking, Probs, Path);
	double Pr = 0;
	for (int i = 0; i < Probs.size(); ++i) {
		Pr += Probs[i];
	}
	return Pr;
}

void Graph::initTrajectory()
{
	for (int tt = 20151019; tt < 20151020; tt++) {
		for (int t = 37; t < 337; t++) {
			Trajectory curTrajectory;
			string filename = ".\\data_trajectory\\" + to_string(tt) + "\\" + to_string(t) + ".csv";
			ifstream file(filename);
			string id;
			string status;
			string date;
			string lat;
			string lng;
			string edgeID;
			string tmp;
			while ( file.good())
			{
				getline(file, id, ',');
				getline(file, status, ',');
				getline(file, date, ',');
				getline(file, lat, ',');
				getline(file, lng, ',');
				getline(file, edgeID, ',');
				getline(file, tmp, ',');
				getline(file, tmp, ',');
				getline(file, tmp, ',');
				getline(file, tmp);
				bool free = true;
				if (id == "") break;
				if (status == "1") free = false;
				GPS cur = GPS(stoi(id), Coord(stod(lat), stod(lng)), free, DateTime(), stoi(edgeID));
				curTrajectory.lstGPS.push_back(cur);
			}
			m_Trajectory.push_back(curTrajectory);
		}
	}
}



/*
	Duyệt cây để tính xác suất, parking place được xem như đỉnh cuối của cạnh cuối cùng
*/
void Graph::traversalTreeCalculate(Status* root, ParkingPlace parking, vector<double>& Probs, vector<Status*>& Path)
{

	if (root == NULL)
	{
		// On Route
		for (int i = 0; i < Path.size(); ++i) {
		m_CurPr *= probabilityOnRoute(Path[i]);
		}
		// On Parking Place
		m_CurPr *= probabilityOnParking(parking, root->pParent->endTime);
		Probs.push_back(m_CurPr);
		return;
	}
	else
	{
		Path.push_back(root);
		traversalTreeCalculate(root->pLeft, parking, Probs, Path);
		Path.pop_back();

		Path.push_back(root);
		traversalTreeCalculate(root->pRight,parking, Probs, Path);
		Path.pop_back();
	}
}



/*
	Duyệt các đường đi từ gốc đến lá của cây để xây dựng nhãn thời gian cho các node
*/
void Graph::traversalTree(Status*& root)
{
	if (root == NULL) 
	{
		return;
	}
	else {
		if (root->decisionPrev == 1) {
			Edge* road = m_EdgeList[root->edgeID];
			root->startTime = root->pParent->endTime;
			root->endTime = root->startTime + road->time;
		}
		if (root->decisionPrev == 2) {
			Edge* road = m_EdgeList[root->edgeID];
			root->startTime = root->pParent->endTime;
			root->endTime = root->startTime + road->time + road->time + road->time + DateTime(CROSS_TIME_ROADSEGMENT);
		}
	}
	traversalTree(root->pLeft);
	traversalTree(root->pRight);
}

/*
	Hàm xây dựng khung cây tính xác suất
	Cây ở đây là 1 cây nhị phân cân bằng hoàn toàn
	Mỗi node (Status) ---> Left : quyết định tiếp theo là đón khách khi đi tới
					  ---> Right : quyết định tiếp theo là đón khánh khi đi lùi sau 4'
*/
void Graph::buildStatusTree(Status*& root,vector<Edge*> Route,  int layer, DateTime currentTime)
{
	if (layer == 0) {
		root = new Status;
		root->startTime = currentTime;
		root->endTime = currentTime;
		root->edgeID = -1;
		root->decisionPrev = 0;
	}
	if (layer == Route.size()) {
		Status* leftNode = new Status;
		leftNode = NULL;
		Status* rightNode = new Status;
		rightNode = NULL;
		root->pLeft = leftNode;
		root->pRight = rightNode;
		return;
	}
	Status* leftNode = new Status;
	leftNode->edgeID = Route[layer]->edgeID;
	leftNode->decisionPrev = 1;
	Status* rightNode = new Status;
	rightNode->edgeID = Route[layer]->edgeID;
	rightNode->decisionPrev = 2;
	root->pLeft = leftNode;
	root->pRight = rightNode;
	leftNode->pParent = root;
	rightNode->pParent = root;
	layer = layer + 1;
	buildStatusTree(root->pLeft, Route, layer, currentTime);
	buildStatusTree(root->pRight, Route, layer, currentTime);
	layer = layer - 1;
}


struct CompareTimeGPS
{
	bool operator()(const GPS& element, DateTime time) {
		return element.currentTime > time;
	}
	bool operator()(const GPS& element1, const GPS& element2)
	{
		return element1.currentTime > element2.currentTime;
	}
	bool operator()(DateTime time, GPS& element) {
		return time > element.currentTime;
	}
	bool operator()(DateTime time1, DateTime time2) {
		return time1 > time2;
	}

};

double Graph::probabilityOnRoute(Status* status)
{
	Edge* edge = m_EdgeList[status->edgeID];
	int countC = 0;
	int countCO = 0;
	for (int i = 0; i < m_Trajectory.size(); ++i) {
		vector<GPS> lstGPS = m_Trajectory[i].lstGPS; // Each Trajectory
		int kBegin = (status->startTime.getSecond() - DELTA_TIME) / TAU_TIME;
		int kEnd = (status->endTime.getSecond() - DELTA_TIME) / TAU_TIME;
		for (; kBegin <= kEnd; ++kBegin) { //Each Interval
			//Interval
			DateTime s = (kBegin - 1)*TAU_TIME; 
			DateTime t = kBegin*TAU_TIME;
			//Binary Search
			vector<GPS>::iterator low = std::lower_bound(lstGPS.begin(), lstGPS.end(), s, CompareTimeGPS());
			vector<GPS>::iterator up = std::upper_bound(lstGPS.begin(), lstGPS.end(), t, CompareTimeGPS());
			int l = low - lstGPS.begin();
			int u = up - lstGPS.end();
			//Count in range [l, u]
			for (; l <= u; ++u) {
				if (lstGPS[l].edgeID == edge->edgeID) {
					int flag = true;
					if (flag && lstGPS[l].free) {
						flag = false;
						countC++;
					}
					if (!flag && !lstGPS[l].free) {
						countCO++;
						break;
					}
				}
			}
		}
	}
	return (double)countC / countCO;
}

int Graph::findCenterParkingPlace(ParkingPlace parking)
{
	Coord center = Coord((parking.topleft.Latitude + parking.btmright.Latitude) / 2, (parking.topleft.Longitude + parking.btmright.Longitude) / 2);
	double minDis = 10000;
	int res = 0;
	for (auto point : m_NodeList) {
		if (center.Distance(point->coord) < minDis) {
			res = point->nodeID;
			minDis = center.Distance(point->coord);
		}
	}
	return res;
}

double Graph::probabilityOnParking(ParkingPlace parking, DateTime currentTime)
{
	DateTime ta = currentTime;
	DateTime tb = currentTime + DateTime(WAIT_TIME_PARKINGPLACE);
	int countPO = 0;
	int countPC = 0;
	for (int i = 0; i < m_Trajectory.size(); ++i) {
		vector<GPS> lstGPS = m_Trajectory[i].lstGPS; // Each Trajectory
		int kBegin = (ta.getSecond() - DELTA_TIME) / TAU_TIME;
		int kEnd = (tb.getSecond() - DELTA_TIME) / TAU_TIME;
		for (; kBegin <= kEnd; ++kBegin) { //Each Interval
											//Interval
			DateTime s = (kBegin - 1)*TAU_TIME;
			DateTime t = kBegin*TAU_TIME;
			//Binary Search
			vector<GPS>::iterator low = std::lower_bound(lstGPS.begin(), lstGPS.end(), s, CompareTimeGPS());
			vector<GPS>::iterator up = std::upper_bound(lstGPS.begin(), lstGPS.end(), t, CompareTimeGPS());
			int l = low - lstGPS.begin();
			int u = up - lstGPS.end();
			//Count in range [l, u]
			for (; l <= u; ++u) {
				if (/*trong parking place*/true) {
					int flag = true;
					if (flag && lstGPS[l].free) {
						flag = false;
						//countC++;
					}
					if (!flag && !lstGPS[l].free) {
						//countCO++;
						break;
					}
				}
			}
		}
}

	return 1;
}