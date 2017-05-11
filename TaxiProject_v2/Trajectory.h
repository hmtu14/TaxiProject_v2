#pragma once
#include <vector>
#include "Taxi.h"
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
	vector<vector<int>> toVec(datetime t, int timestamp); //ham tra ve matrix bieu do bat khach trong ngay tu 0h -> t, timestamp tinh = phut
	~Trajectory();
};

