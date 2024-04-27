#pragma once
#include "Ticket.h"

class StudentTicket : public Ticket
{
	double calculateDiscount(double price) const;
public:

	StudentTicket(const char* name, double price);
	
};

