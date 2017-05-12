#include "Taxi.h"


Taxi::Taxi()
{
}


Taxi::Taxi(int id__, Coord mCoord__, bool free__, DateTime time__)
{
	id = id__;
	m_Coord = mCoord__;
	free = free__;
	m_time = time__;
}

Coord Taxi::getCoord()
{
	return m_Coord;
}

Taxi::~Taxi()
{
}
