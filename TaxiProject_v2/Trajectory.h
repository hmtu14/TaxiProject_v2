#pragma once
#include <vector>
#include "Taxi.h"

const int gSize = 100; //Chia grid ra thanh gSizexgSize
using namespace std;
class Trajectory
{
private:
	vector<Taxi> lstTaxi;
	enum day
	{
		Mo,
		Tu,
		We,
		Th,
		Fr,
		Sa,
		Su
	};
public:
	Trajectory();
	vector<vector<int>> toVec(DateTime t, int timestamp, Coord top, Coord btm); //ham tra ve matrix bieu do bat khach trong ngay tu 0h -> t, timestamp tinh = phut
	~Trajectory();
};

