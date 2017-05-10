#pragma once
#include "Coord.h"

class RoadSegment
{
private:
	Coord sCoord;
	Coord eCoord;
	int id;
public:
	RoadSegment();
	RoadSegment(int id__, Coord sCoord__, Coord eCoord__);
	~RoadSegment();
};

