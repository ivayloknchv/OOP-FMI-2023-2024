#include <iostream>
#pragma once

class Time
{
private:

	int hours = 0;
	int minutes = 0;
	int seconds = 0;

	void printHours() const;

	void printMinutes() const;

	void printSeconds() const;

public:

	Time() = default;

	Time(int hours, int minutes, int seconds);

	void setHours(int hours);

	void setMinutes(int minutes);

	void setSeconds(int seconds);

	int getHours() const;

	int getMinutes() const;

	int getSeconds() const;

	void printTime() const;

	int TransformIntoSeconds() const;
};