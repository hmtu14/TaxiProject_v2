#pragma once
#include "Coord.h"
#include "datetime.h"
#include "Trajectory.h"

class RoadSegment
{
private:
	Coord sCoord;
	Coord eCoord;
	int id;
public:
	RoadSegment();
	RoadSegment(int id__, Coord &sCoord__, Coord &eCoord__);

	void countTaxi(DateTime t,const vector<Trajectory> &lstTracjectory, int& allCount, int& oCount);
	~RoadSegment();
};

