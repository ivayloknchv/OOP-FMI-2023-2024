#include "WebPage.h"
#include <iostream>
#include <cstring>

#pragma warning (disable : 4996)




void WebPage::copyFrom(const WebPage& other)
{
	address = new char[strlen(other.address) + 1]{};
	strcpy(address, other.address);

	ip = new char[strlen(other.ip) + 1]{};
	strcpy(ip, other.ip);
}

void WebPage::free()
{
	delete[] address;
	delete[] ip;

	address = nullptr;
	ip = nullptr;
}

WebPage::WebPage() 
{
	address = new char[Constants::DEFAULT_ADDRESS]{};
	ip = new char[Constants::DEAFULT_IP]{};
}

WebPage::WebPage(const WebPage & other)
{
	copyFrom(other);
}

WebPage& WebPage::operator=(const WebPage& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

WebPage::~WebPage()
{
	free();
}

WebPage::WebPage(const char* newAddress, const char* newIp)
{
	setAddress(newAddress);
	setIP(newIp);
}

void WebPage::setAddress(const char* newAddress)
{
	if (!newAddress || newAddress==address)
	{
		return;
	}

	delete[] address;

	address = new char[strlen(newAddress) + 1]{};

	strcpy(address, newAddress);
}

void WebPage::setIP(const char* newIp)
{
	if (!newIp || newIp == ip)
	{
		return;
	}

	delete[] ip;

	ip = new char[strlen(newIp) + 1]{};

	strcpy(ip, newIp);
}

const char* WebPage::getAddress() const
{
	return address;
}

const char* WebPage::getIp() const
{
	return ip;
}

std::ostream& operator<<(std::ostream& os, const WebPage& page)
{
	return os << page.address << ' '<<page.ip << std::endl;
}

std::istream& operator>>(std::istream& is, WebPage& page)
{
	return is >> page.address >> page.ip;
}
