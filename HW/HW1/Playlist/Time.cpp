#include "Time.h"

void Time::printHours() const
{
	if (hours < 10)
	{
		std::cout << 0 << hours << ':';
	}
	else
	{
		std::cout << hours << ':';
	}
}

void Time::printMinutes() const
{
	if (minutes < 10)
	{
		std::cout << 0 << minutes << ':';
	}
	else
	{
		std::cout << minutes << ':';
	}
}

void Time::printSeconds() const
{
	if (seconds < 10)
	{
		std::cout << 0 << seconds;
	}
	else
	{
		std::cout << seconds;
	}
}

Time::Time(int hours, int minutes, int seconds)
{
	setHours(hours);
	setMinutes(minutes);
	setSeconds(seconds);
}

void Time::setHours(int hours)
{
	if (hours < 0 || hours>23)
	{
		return;
	}
	this->hours = hours;
}

void Time::setMinutes(int minutes)
{
	if (minutes < 0 || minutes>60)
	{
		return;
	}
	this->minutes = minutes;
}

void Time::setSeconds(int seconds)
{
	if (seconds < 0 || seconds>59)
	{
		return;
	}

	this->seconds = seconds;
}

int Time::getHours() const
{
	return hours;
}

int Time::getMinutes() const
{
	return minutes;
}

int Time::getSeconds() const
{
	return seconds;
}

void Time::printTime() const
{
	printHours();
	printMinutes();
	printSeconds();
}

int Time::TransformIntoSeconds() const
{
	return 3600 * hours + 60 * minutes + seconds;
}