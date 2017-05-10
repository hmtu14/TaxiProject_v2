#pragma once
#include "Coord.h"

class Taxi
{
private:
	int id;
	Coord m_Coord;
public:
	Taxi();
	Taxi(int id__, Coord mCoord__);
	~Taxi();
};

