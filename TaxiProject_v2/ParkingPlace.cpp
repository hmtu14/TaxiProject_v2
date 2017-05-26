#include "ParkingPlace.h"


ParkingPlace::ParkingPlace(vector<Coord> &lstCoord__) {
	double xmin = lstCoord__[0].Latitude;
	double ymin = lstCoord__[0].Longitude;
	double xmax = lstCoord__[0].Latitude;
	double ymax = lstCoord__[0].Longitude;
	for (auto point : lstCoord__) {
		if (point.Latitude < xmin) xmin = point.Latitude;
		if (point.Latitude > xmax) xmax = point.Latitude;
		if (point.Longitude < ymin) ymin = point.Longitude;
		if (point.Longitude < ymax) ymax = point.Longitude;
	}
	topleft = Coord(xmin, ymax);
	btmright = Coord(xmax, ymin);
}

ParkingPlace::ParkingPlace()
{
}

bool ParkingPlace::inParking(Coord x)
{
	if (x.Latitude < this->topleft.Latitude || x.Longitude < this->topleft.Longitude)
		return false; 
	if (x.Latitude > this->btmright.Latitude || x.Longitude > this->btmright.Longitude)
		return false;

	return true; 
}


ParkingPlace::~ParkingPlace()
{
}
