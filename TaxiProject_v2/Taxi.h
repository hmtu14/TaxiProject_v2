#pragma once
#include "Coord.h"
#include "datetime.h"
class Taxi
{
private:
	int id;
	Coord m_Coord;
	bool free; // free = true khong co khach, false = co khach
	DateTime m_time;
public:
	Taxi();
	Taxi(int id__, Coord mCoord__, bool free__, DateTime time__);

	//getter setter
	Coord getCoord();
	~Taxi();
};

