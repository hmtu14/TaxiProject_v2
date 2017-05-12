#include "RoadSegment.h"



RoadSegment::RoadSegment()
{
}

RoadSegment::RoadSegment(int id__, Coord sCoord__, Coord eCoord__)
{
	id = id__;
	sCoord = sCoord__;
	eCoord = eCoord__;
}

void RoadSegment::countTaxi(DateTime t, vector<Trajectory> lstTracjectory, int & allCount, int & oCount)
{
	for (auto Tracjec : lstTracjectory) {
		for (auto Taxi : Tracjec.getlstTaxi()) {

		}
	}
}

RoadSegment::~RoadSegment()
{
}
