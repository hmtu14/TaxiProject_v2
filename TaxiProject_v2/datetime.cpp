#include "datetime.h"

DateTime::DateTime(int second_, int minute_, int hour_, int day_, int month_, int year_)
{
	second = second_;
	minute = minute_;
	hour = hour_;
	day = day_;
	month = month_;
	year = year_;
}

int DateTime::getCumMinute()
{
	return second / 60 + hour * 60 + minute;
}

DateTime::DateTime()
{
}

DateTime::~DateTime()
{

}

