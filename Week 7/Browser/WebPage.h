#pragma once
#include <iostream>

namespace Constants
{
	constexpr int DEFAULT_ADDRESS = 30;
	constexpr int DEAFULT_IP = 20;
}

class WebPage
{
private:
	char* address = nullptr;
	char* ip = nullptr;

	void copyFrom(const WebPage& other);
	void free();

public:

	WebPage();
	WebPage(const WebPage& other);
	WebPage& operator=(const WebPage& other);
	~WebPage();

	WebPage(const char* newAddress, const char* newIp);
	void setAddress(const char* newAddress);
	void setIP(const char* newIp);

	const char* getAddress() const;
	const char* getIp() const;

	friend std::ostream& operator<<(std::ostream& os, const WebPage& page);
	friend std::istream& operator>>(std::istream& is, WebPage& page);
};