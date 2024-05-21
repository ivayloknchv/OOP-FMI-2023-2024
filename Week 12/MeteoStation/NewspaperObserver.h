#pragma once
#include "Observer.h"

class NewspaperObserver : public Observer
{
public:

	NewspaperObserver(const char* name, const char* city, double temperature);

	void update(const char* city, double temperature) override;

	Observer* clone() const override;

	void printMeteo() const override;
};

