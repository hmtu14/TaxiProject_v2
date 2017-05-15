#include "ParkingPlace.h"


ParkingPlace::ParkingPlace(vector<Coord> &lstCoord__) {
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

Coord TopLeftCoord(vector<Coord> S)
{
	double lat_min = S[0].lat; 
	for (int i = 0; i < S.size(); i++)
		lat_min = min(lat_min, S[i].lat); 

	double lng_min = 0; 
	for (int i = 0; i < S.size(); i++)
		if (S[i].lat == lat_min)
		{
			if (lng_min == 0) lng_min = S[i].lng;
			else
				if (S[i].lng < lng_min)
					lng_min = S[i].lng;
		}
	
	return Coord(lat_min, lng_min); 
}


Coord BottomRightCoord(vector<Coord> S)
{
	double lat_max = S[0].lat;
	for (int i = 0; i < S.size(); i++)
		lat_max = max(lat_max, S[i].lat);

	double lng_max = 0;
	for (int i = 0; i < S.size(); i++)
		if (S[i].lat == lat_max)
		{
			if (lng_max == 0) lng_max = S[i].lng;
			else
				if (S[i].lng > lng_max)
					lng_max = S[i].lng;
		}

	return Coord(lat_max, lng_max);
}

bool ParkingPlace::inParking(Coord x)
{
	//if (x.lat < this->topleft.lat || x.lng < this->topleft.lng)
	//	return false; 
	//if (x.lat > this->btmright.lat || x.lng > this->btmright.lng)
	//	return false;
	//Coord TopLeft = TopLeftCoord(this->lstCoord);
	//Coord BottomRight = BottomRightCoord(this->lstCoord); 
	//if (x.lat < TopLeft.lat || x.lng < TopLeft.lng)
	//	return false;
	//if (x.lat > BottomRight.lat || x.lng > BottomRight.lng)
	//	return false;
	return true; 
}


ParkingPlace::~ParkingPlace()
{
}
