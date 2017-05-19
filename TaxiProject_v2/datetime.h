#pragma once
struct DateTime
{
	int second, minute, hour, day, month, year;
	DateTime() {};
	DateTime(int second_, int minute_, int hour_) : second(second_), minute(minute_), hour(hour_), day(-1), month(-1), year(-1) {};
	DateTime(int second_, int minute_, int hour_, int day_, int month_, int year_):second(second_), minute(minute_), hour(hour_), day(day_), month(month_), year(year_) {};
	int getCumMinute()
	{
		return second / 60 + hour * 60 + minute;
	}

	DateTime operator+(DateTime time) 
	{
		DateTime res;
		res.day = day; res.month = month; res.year = year;
		res.second = (second + time.second)% 60;
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

	bool operator>(DateTime time) {
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