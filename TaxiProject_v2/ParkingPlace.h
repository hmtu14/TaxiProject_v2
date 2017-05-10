#pragma once
#include <vector>
#include "Coord.h"
using namespace std;

class ParkingPlace
{
private:
	vector<Coord> lstCoord;
	Coord topleft;
	Coord btmright;
public:
	ParkingPlace(vector<Coord> lstCoord__);
	ParkingPlace();
	//kiem tra 1 coord co trong ParkingPlace k
	bool inParking(Coord co__);

	~ParkingPlace();
};

