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

Coord TopLeftCoord(vector<Coord> S)
{
	double lat_min = S[0].Latitude; 
	for (int i = 0; i < S.size(); i++)
		lat_min = min(lat_min, S[i].Latitude); 

	double lng_min = 0; 
	for (int i = 0; i < S.size(); i++)
		if (S[i].Latitude == lat_min)
		{
			if (lng_min == 0) lng_min = S[i].Longitude;
			else
				if (S[i].Longitude < lng_min)
					lng_min = S[i].Longitude;
		}
	
	return Coord(lat_min, lng_min); 
}


Coord BottomRightCoord(vector<Coord> S)
{
	double lat_max = S[0].Latitude;
	for (int i = 0; i < S.size(); i++)
		lat_max = max(lat_max, S[i].Latitude);

	double lng_max = 0;
	for (int i = 0; i < S.size(); i++)
		if (S[i].Latitude == lat_max)
		{
			if (lng_max == 0) lng_max = S[i].Longitude;
			else
				if (S[i].Longitude > lng_max)
					lng_max = S[i].Longitude;
		}

	return Coord(lat_max, lng_max);
}

bool ParkingPlace::inParking(Coord x)
{
	//if (x.Latitude < this->topleft.Latitude || x.Longitude < this->topleft.Longitude)
	//	return false; 
	//if (x.Latitude > this->btmright.Latitude || x.Longitude > this->btmright.Longitude)
	//	return false;
	//Coord TopLeft = TopLeftCoord(this->lstCoord);
	//Coord BottomRight = BottomRightCoord(this->lstCoord); 
	//if (x.Latitude < TopLeft.Latitude || x.Longitude < TopLeft.Longitude)
	//	return false;
	//if (x.Latitude > BottomRight.Latitude || x.Longitude > BottomRight.Longitude)
	//	return false;
	return true; 
}


ParkingPlace::~ParkingPlace()
{
}
