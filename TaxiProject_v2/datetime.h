#pragma once

class DateTime
{
private:
	int second, minute, hour, day, month, year; 
public:
	DateTime(int, int, int, int, int, int);
	int getCumMinute(); 
	~DateTime();
};	