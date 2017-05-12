#include "Taxi.h"


Taxi::Taxi()
{
}


Taxi::Taxi(int id__, Coord mCoord__, bool free__, DateTime time__, int roadID__)
{
	id = id__;
	m_Coord = mCoord__;
	free = free__;
	m_time = time__;
	roadID = roadID__;
}

Coord Taxi::getCoord()
{
	return m_Coord;
}

DateTime Taxi::getTime()
{
	return m_time;
}

int Taxi::getRoadID()
{
	return roadID;
}

Taxi::~Taxi()
{
}
