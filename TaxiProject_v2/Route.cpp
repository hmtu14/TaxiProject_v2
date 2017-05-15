#include "Route.h"



Route::Route()
{
}

Route::Route(vector<RoadSegment*> &lstRoad__, ParkingPlace* &desParking__)
{
	lstRoad = lstRoad__;
	desParking = desParking__;
}

double Route::calProb(DateTime t)
{
	return 0.0;
}


Route::~Route()
{
	for (int i = 0; i < lstRoad.size(); ++i) {
		delete lstRoad[i];
	}
	lstRoad.clear();
	delete desParking;
}
