#include "ParkingPlace.h"

ParkingPlace::ParkingPlace(vector<Coord> lstCoord__) {
	lstCoord = lstCoord__;
	double xmin = lstCoord__[0].lat;
	double ymin = lstCoord__[0].lng;
	double xmax = lstCoord__[0].lat;
	double ymax = lstCoord__[0].lng;
	for (auto point : lstCoord__) {
		if (point.lat < xmin) xmin = point.lat;
		if (point.lat > xmax) xmax = point.lat;
		if (point.lng < ymin) ymin = point.lng;
		if (point.lng < ymax) ymax = point.lng;
	}
	topleft = Coord(xmin, ymax);
	btmright = Coord(xmax, ymin);
}

ParkingPlace::ParkingPlace()
{
}

bool ParkingPlace::inParking(Coord co__)
{
	return false;
}


ParkingPlace::~ParkingPlace()
{
}
