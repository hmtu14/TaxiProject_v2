#pragma once

class DateTime
{
public:
	int second, minute, hour, day, month, year;
	DateTime(int second_, int minute_, int hour_, int day_, int month_, int year_);
	int getCumMinute();
	DateTime();
	~DateTime();
};	