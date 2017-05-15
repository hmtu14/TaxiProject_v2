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
	int roadID; //id cua road segment hien tai


public:
	Taxi();
	Taxi(int id__, Coord &mCoord__, bool free__, DateTime &time__, int roadID__);

	//getter setter
	Coord getCoord();
	DateTime getTime();
	int getRoadID();
	~Taxi();
};

