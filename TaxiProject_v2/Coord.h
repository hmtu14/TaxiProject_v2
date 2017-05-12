#pragma once
class Coord {
	
public:
	double lat;
	double lng;
	Coord();
	Coord(double lat__, double lng__);
	//Tinh khoang cach
	double Distance(Coord nCoord);
	~Coord();
};