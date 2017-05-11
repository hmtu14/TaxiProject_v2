#pragma once
#include "datetime.h"
#include "Coord.h"
#include <vector>
using namespace std;

class Guess
{
private:
	int type; // 0 = khach vay, 1 = khach tong dai
	DateTime s_time;
	DateTime e_time;
	vector<Coord> lstCoord;

public:
	Guess();
	~Guess();
};

