#include "Taxi.h"


Taxi::Taxi()
{
}

Taxi::Taxi(int id__, Coord mCoord__, bool free__, datetime time__)
{
	id = id__;
	m_Coord = mCoord__;
	free = free__;
	m_time = time__;
}

Taxi::~Taxi()
{
}
