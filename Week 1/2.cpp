#include <iostream>

const int MAX_SIZE = 16;

enum class DayOfWeek{
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

struct Event {
	char eventName[MAX_SIZE];
	DayOfWeek day;
	int duration;
};

void printDay(const DayOfWeek& day)
{
	switch (day)
	{
	case DayOfWeek::MONDAY: std::cout << "Monday" << std::endl; break;
	case DayOfWeek::TUESDAY: std::cout << "Tuesday" << std::endl; break;
	case DayOfWeek::WEDNESDAY: std::cout << "Wednesday" << std::endl; break;
	case DayOfWeek::THURSDAY: std::cout << "Thursday" << std::endl; break;
	case DayOfWeek::FRIDAY: std::cout << "Friday" << std::endl; break;
	case DayOfWeek::SATURDAY: std::cout << "Saturday" << std::endl; break;
	case DayOfWeek::SUNDAY: std::cout << "Sunday" << std::endl; break;
	default: std::cout << "Invalid day!" << std::endl; break;
	}
}

void printEventInfo(const Event& ev)
{
	std::cout << "Event name: " << ev.eventName<<std::endl;
	std::cout << "Event day: ";
	printDay(ev.day);
	std::cout << "Event duration: " << ev.duration << " hours" << std::endl;

}

void printEventsOn(DayOfWeek day, const Event* events, int size)
{
	if (!events)
	{
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if (events[i].day == day)
		{
			printEventInfo(events[i]);
		}
	}
}

bool validate(int& begin, int& end)
{
	if (begin < end)
	{
		if (begin > 0 && end > 0)
		{
			return true;
		}
	}
	return false;
}

void printEventsOnInterval(DayOfWeek day, const Event* events, int size, int begin, int end)
{
	if (!events)
	{
		return;
	}

	if (!validate(begin, end))
	{
		std::cout << "Invalid interval!" << std::endl;
		return;
	}

	for (int i = 0; i < size; i++)
	{
		if ((events[i].day == day) && (events[i].duration>=begin && events[i].duration<=end))
		{
			printEventInfo(events[i]);
		}
	}
}
int main()
{
	Event ev1 = { "party1", DayOfWeek::WEDNESDAY,12 };
	Event ev2 = { "party2", DayOfWeek::FRIDAY,10 };
	Event events[2] = { ev1,ev2 };
	printEventsOn(DayOfWeek::WEDNESDAY, events, 2);
	printEventsOnInterval(DayOfWeek::WEDNESDAY, events, 2,9,13);
	return 0;
}