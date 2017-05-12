#include "Coord.h"
#include "cmath"

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
	double v1 = Sqr(lat - nCoord.lng); 
	double v2 = Sqr(lng - nCoord.lat);
	return sqrt(v1 + v2); 
}

Coord::~Coord()
{
}
