#pragma once
#include <vector>
#include "Taxi.h"
#include <algorithm>
#include <string>

const int gSize = 100; //Chia grid ra thanh gSize x gSize
using namespace std;

class Trajectory
{
	friend class cmpTrajectory; 
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

	vector<vector<int>> toVec(DateTime t, int timestamp, Coord &top, Coord &btm); //ham tra ve matrix bieu do bat khach trong ngay tu 0h -> t, timestamp tinh = phut
	double vecDistance(DateTime t, int timestamp, Coord	top, Coord btm ,Trajectory &nTracjec); // check vi sao them const o day k duoc

	//ham findSimilar can viet lai
	vector<Trajectory> findSimilar(DateTime t, int timestamp, Coord top, Coord btm,const vector<Trajectory> &lstTracjectory);

	//getter
	vector<Taxi>* getlstTaxi();
	~Trajectory();
};


class cmpTrajectory
{
	DateTime t;
	int timestamp;
	Coord top, btm;
	Trajectory x;
public:
	cmpTrajectory(Trajectory x_, DateTime t_, int timestamp_, Coord top_, Coord btm_)
	{
		x = x_;
		t = t_;
		timestamp = timestamp_;
		top = top_;
		btm = btm_;
	}
	bool operator()(Trajectory a, Trajectory b)
	{
		return x.vecDistance(t, timestamp, top, btm, a) < x.vecDistance(t, timestamp, top, btm, b);
	}
};
