#pragma once
#include "Coord.h"
#include "datetime.h"


struct GPS
{
	int id;
	Coord coord;
	bool free;
	DateTime currentTime;
	int edgeID;
	GPS() {};
	GPS(int id_, Coord coord_, bool free_, DateTime time_, int edgeID_) :
		id(id_), coord(coord_), free(free_), currentTime(time_), edgeID(edgeID_) {};
};

