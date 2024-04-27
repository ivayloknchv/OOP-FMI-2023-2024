#pragma once
#include "Ticket.h"

class GroupTicket: public Ticket
{
	double calculateDiscount(double price) const;

public:

	GroupTicket(const char* name, double price);
};

