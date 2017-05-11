#include "Coord.h"

Coord::Coord(double lat__, double lng__) {
	lat = lat__;
	lng = lng__;
}

Coord::Coord()
{
}


double Coord::Distance(Coord nCoord)
{
	v1 = (lat - nCoord.lat) ** 2
	v2 = (lng - nCoord.lng) ** 2
	return math.sqrt(v1 + v2); 
}

Coord::~Coord()
{
}
