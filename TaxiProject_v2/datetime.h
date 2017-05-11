#pragma once

class DateTime
{
public:
	int second, minute, hour, day, month, year;
	DateTime(int, int, int, int, int, int);
	int getCumMinute();
	DateTime();
	~DateTime();
};	