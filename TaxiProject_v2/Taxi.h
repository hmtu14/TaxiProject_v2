#pragma once
#include "Coord.h"
#include "init.h"
class Taxi
{
private:
	int id;
	Coord m_Coord;
	bool free; // free = true khong co khach, false = co khach
	time_t m_time;
public:
	Taxi();
	Taxi(int id__, Coord mCoord__, bool free__, time_t time__);
	~Taxi();
};

