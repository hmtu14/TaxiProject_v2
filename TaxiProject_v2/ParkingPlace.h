#pragma once
#include <vector>
#include "Coord.h"
#include <cmath>
#include <algorithm>
using namespace std;

class ParkingPlace
{
public:
	Coord topleft;
	Coord btmright;
public:
	ParkingPlace(vector<Coord> &lstCoord__);
	ParkingPlace();
	//kiem tra 1 coord co trong ParkingPlace k
	bool inParking(Coord co__);
	//friend Coord BottomRightCoord(vector<Coord>);
	//friend Coord TopLeftCoord(vector<Coord>);


	~ParkingPlace();
};

