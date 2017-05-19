#pragma once
#include <cmath>
struct Coord
{
	double	Latitude;
	double Longitude;
	Coord() {};
	Coord(double lat, double lng) :Latitude(lat), Longitude(lng) {};
	double Distance(Coord coor_) {
		double dlong = abs(this->Latitude - coor_.Latitude);
		double cosD = (sin(this->Longitude)*sin(coor_.Longitude) + cos(this->Longitude)*cos(coor_.Longitude)*cos(dlong));
		double D = acos(cosD);
		return 1.852*D;
	}
};