#pragma once
#include "init.h"
#include "Coord.h"

class Guess
{
private:
	int type; // 0 = khach vay, 1 = khach tong dai
	time_t s_time;
	time_t e_time;
	Coord s_coord;
	Coord t_coord;

public:
	Guess();
	~Guess();
};

