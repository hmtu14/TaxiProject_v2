#pragma once
#include <string>
#include <cmath>
using namespace std;
struct DateTime
{
	int second, minute, hour, day, month, year;
	DateTime() {};
	DateTime(int second_, int minute_, int hour_) : second(second_), minute(minute_), hour(hour_), day(0), month(0), year(0) {};
	DateTime(int second_, int minute_, int hour_, int day_, int month_, int year_):second(second_), minute(minute_), hour(hour_), day(day_), month(month_), year(year_) {};
	DateTime(int second_) :second(second_), minute(0), hour(0), day(0) {};
	DateTime(string date) {
		year = stoi(date.substr(0, 4));
		month = stoi(date.substr(5, 2));
		day = stoi(date.substr(8, 2));
		hour = stoi(date.substr(11, 2));
		minute = stoi(date.substr(14, 2));
		second = stoi(date.substr(17, 2));
	}
	int getCumMinute()
	{
		return second / 60 + hour * 60 + minute;
	}
	int getSecond() {
		return 3600 * hour + 60 * minute + second;
	}

	DateTime operator+(DateTime time) 
	{
		DateTime res;
		res.day = day; res.month = month; res.year = year;
		res.second = (second + time.second) % 60;
		int r_second = (second + time.second) / 60;
		res.minute = (minute + time.minute + r_second) % 60;
		int r_min = (minute + time.minute + r_second) / 60;
		res.hour = hour + time.hour + r_min;
		if (res.hour > 24) {
			res.hour = 23;
			res.second = 59;
			res.minute = 59;
		}
		return res;
	}

	bool operator==(DateTime time) {
		return (second == time.second && minute == time.minute && hour == time.hour);
	}

	bool operator>(DateTime time) const{
		if (hour > time.hour) 
			return true;
		if (minute > time.minute)
			return true;
		if (second > time.second)
			return true;
		return false;
	}
	
	bool operator>=(DateTime time) {
		if (*this == time || *this > time)
			return true;
		return false;
	}

	bool operator<(DateTime time) {
		return !(*this >= time);
	}

	bool operator<=(DateTime time) {
		return !(*this > time);
	}



};