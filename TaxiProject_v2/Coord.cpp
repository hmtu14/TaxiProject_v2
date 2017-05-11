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
	v1 = Sqr(lat - nCoord.lat)
	v2 = Sqr(lng - nCoord.lng)
	return sqrt(v1 + v2); 
}

Coord::~Coord()
{
}
