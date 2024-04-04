#include "Browser.h"

void Browser::resize()
{
	WebPage* copy = new WebPage[2 * maxCapacity];

	for (int i = 0; i < currentCount; i++)
	{
		copy[i] = pages[i];
	}

	delete[] pages;
	pages = copy;

	maxCapacity *= 2;

	copy = nullptr;
}

void Browser::add(const WebPage& page)
{
	if (currentCount == maxCapacity)
	{
		resize();
	}

	pages[currentCount++] = page;
}

void Browser::remove(int idx)
{
	if (idx >= 0 && idx < currentCount)
	{
		std::swap(pages[idx], pages[currentCount - 1]);
		currentCount--;
	}
}

void Browser::addPage(const WebPage& page)
{
	add(page);
}

void Browser::removePage(int idx)
{
	remove(idx);
}

void Browser::copyFrom(const Browser& other)
{
	pages = new WebPage[other.maxCapacity];

	maxCapacity = other.maxCapacity;
	currentCount = other.currentCount;

	for (int i = 0; i < currentCount; i++)
	{
		pages[i] = other.pages[i];
	}
}

void Browser::free()
{
	delete[] pages;
	pages = nullptr;

	maxCapacity = 0;
	currentCount = 0;
}

Browser::Browser()
{
	pages = new WebPage[ConstantsBrowser::DEFAULT_CAPACITY];
	maxCapacity = ConstantsBrowser::DEFAULT_CAPACITY;
}

Browser::Browser(const Browser& other)
{
	copyFrom(other);
}

Browser& Browser::operator=(const Browser& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Browser::~Browser()
{
	free();
}


Browser& Browser::operator+=(const WebPage& page)
{
	add(page);

	return *this;
}

Browser& Browser::operator-=(int idx)
{
	remove(idx);

	return *this;
}

void Browser::print() const
{
	for (int i = 0; i < currentCount; i++)
	{
		std::cout << i + 1 << ") " << pages[i];
	}
}
