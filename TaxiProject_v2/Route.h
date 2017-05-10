#pragma once
#include "RoadSegment.h"
#include "ParkingPlace.h"

class Route
{
private:
	vector<RoadSegment> lstRoad;
	ParkingPlace desParking;
public:
	Route();
	Route(vector<RoadSegment> lstRoad__, ParkingPlace desParking__);
	~Route();
};

