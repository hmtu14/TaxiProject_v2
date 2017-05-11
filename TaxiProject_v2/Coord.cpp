#include "Coord.h"

Coord::Coord(double lat__, double lng__) {
	lat = lat__;
	lng = lng__;
}

Coord::Coord()
{
}

double Sqr(double x)
{
	return x * x; 
}


double Coord::Distance(Coord nCoord)
{
	return 0;
}

Coord::~Coord()
{
}
