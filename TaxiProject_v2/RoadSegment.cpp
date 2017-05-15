#include "RoadSegment.h"

const int TTHRESHOLD = 15;


RoadSegment::RoadSegment()
{
}

RoadSegment::RoadSegment(int id__, Coord & sCoord__, Coord & eCoord__)
{
	id = id__;
	sCoord = sCoord__;
	eCoord = eCoord__;
}

void RoadSegment::countTaxi(DateTime t,const vector<Trajectory> &lstTracjectory, int & allCount, int & oCount)
{
	allCount = 0;
	oCount = 0;
	for (auto Tracjec : lstTracjectory) {
		for (auto Taxi : *Tracjec.getlstTaxi()) {
			if (Taxi.getTime().getCumMinute() > t.getCumMinute() + TTHRESHOLD) break;
			if (Taxi.getTime().getCumMinute() < t.getCumMinute() + TTHRESHOLD) continue;
			if (Taxi.getRoadID() == id) {
				allCount++;
			}
		}
	}
}

RoadSegment::~RoadSegment()
{
}
