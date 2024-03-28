#pragma once

class Time
{
	unsigned hours = 0;
	unsigned minutes = 0;
	unsigned seconds = 0;

	unsigned getSecondsFromMidnight() const;

	Time(unsigned secs);

public:

	Time() = default;

	Time(unsigned hours, unsigned minutes, unsigned seconds);

	void setHours(unsigned hours);

	void setMinutes(unsigned minutes);

	void setSeconds(unsigned seconds);

	Time getTimeToMidnight() const;

	void addSec();

	bool CompareTimes(const Time& other) const;

	bool isDinnerTime() const;

	Time getTimeDiff(const Time& other) const;

	void printTime() const;
};