#include "Coord.h"
#include "cmath"


#define earthRadiusKm 6371.0
#define M_PI 3.14159265358979323846

double deg2rad(double deg) {
	return (deg * M_PI / 180);
}

double rad2deg(double rad) {
	return (rad * 180 / M_PI);
}

double distanceEarth(double lat1d, double lon1d, double lat2d, double lon2d) {
	double lat1r, lon1r, lat2r, lon2r, u, v;
	lat1r = deg2rad(lat1d);
	lon1r = deg2rad(lon1d);
	lat2r = deg2rad(lat2d);
	lon2r = deg2rad(lon2d);
	u = sin((lat2r - lat1r) / 2);
	v = sin((lon2r - lon1r) / 2);
	return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

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
	return distanceEarth(this->lat, this->lng, nCoord.lat, nCoord.lng); 
}

Coord::~Coord()
{
}
