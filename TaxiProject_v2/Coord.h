#pragma once
class Coord {
private:
	double lat;
	double lng;
public:

	Coord();
	Coord(double lat__, double lng__);
	//Tinh khoang cach
	double Distance(Coord nCoord);
	~Coord();
};