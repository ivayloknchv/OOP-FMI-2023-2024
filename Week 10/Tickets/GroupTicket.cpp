#include "GroupTicket.h"

double GroupTicket::calculateDiscount(double price) const
{
    return 0.8*price;
}

GroupTicket::GroupTicket(const char* name, double price): Ticket(name, calculateDiscount(price))
{
}
