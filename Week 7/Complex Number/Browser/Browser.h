#include "WebPage.h"
#pragma once

namespace ConstantsBrowser
{
	constexpr int DEFAULT_CAPACITY=10;
}

class Browser
{
private:
	WebPage* pages = nullptr;
	int maxCapacity = 0;
	int currentCount = 0;

	void resize();
	void add(const WebPage& page);
	void remove(int idx);

	void copyFrom(const Browser& other);
	void free();
public:

	Browser();
	Browser(const Browser& other);
	Browser& operator=(const Browser& other);
	~Browser();

	void addPage(const WebPage& page);
	void removePage(int idx);

	Browser& operator +=(const WebPage& page);
	Browser& operator -=(int idx);

	void print() const;
};