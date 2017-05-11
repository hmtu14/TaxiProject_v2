#pragma once
#include "datetime.h"
#include "Coord.h"

class Guess
{
private:
	int type; // 0 = khach vay, 1 = khach tong dai
	DateTime s_time;
	DateTime e_time;
	Coord s_coord;
	Coord t_coord;

public:
	Guess();
	~Guess();
};

