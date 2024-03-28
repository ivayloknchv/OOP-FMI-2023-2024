#include "Time.h"
#include <iostream>

unsigned Time::getSecondsFromMidnight() const
{
	return hours * 3600 + minutes * 60 + seconds;
}

Time::Time(unsigned secs)
{
	setHours(secs / 3600);
	setMinutes((secs % 3600) / 60);
	setSeconds((secs % 3600) % 60);
}

Time::Time(unsigned hours, unsigned minutes, unsigned seconds)
{
	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}

void Time::setHours(unsigned hours)
{
	if (hours < 0 || hours  > 23)
	{
		return;
	}

	this->hours = hours;
}

void Time::setMinutes(unsigned minutes)
{
	if (minutes < 0 || minutes > 59)
	{
		return;
	}
	this->minutes = minutes;
}

void Time::setSeconds(unsigned seconds)
{
	if (seconds < 0 || seconds > 59)
	{
		return;
	}

	this->seconds = seconds;
}

Time Time::getTimeToMidnight() const
{
	unsigned secsFromMidnight = getSecondsFromMidnight();
	unsigned totalSecsInDay = 24 * 3600;
	return Time(totalSecsInDay - secsFromMidnight);
}

void Time::addSec()
{
	seconds += 1;

	if (seconds > 59)
	{
		seconds = 0;
		minutes += 1;

		if (minutes > 59)
		{
			minutes = 0;
			hours += 1;

			if (hours > 23)
			{
				hours = 0;
			}
		}
	}
}

bool Time::CompareTimes(const Time& other) const
{
	return getSecondsFromMidnight() < other.getSecondsFromMidnight();
}

bool Time::isDinnerTime() const
{
	Time lowerBound(20, 30, 0);
	Time upperBound(22, 0, 0);

	return CompareTimes(upperBound) && !CompareTimes(lowerBound);
}

Time Time::getTimeDiff(const Time& other) const
{
	unsigned myTime = getSecondsFromMidnight();
	unsigned otherTime = other.getSecondsFromMidnight();

	unsigned diff = myTime - otherTime;

	if (diff < 0)
	{
		diff *= -1;
	}

	return Time(diff);
}

void Time::printTime() const
{
	if (hours < 10)
	{
		std::cout << 0 << hours << ":";
	}

	else
	{
		std::cout<< hours << ":";
	}

	if (minutes < 10)
	{
		std::cout << 0 << minutes << ":";
	}

	else
	{
		std::cout << minutes << ":";
	}

	if (seconds < 10)
	{
		std::cout << 0 << seconds << std::endl;
	}

	else
	{
		std::cout << seconds << std::endl;
	}
}

