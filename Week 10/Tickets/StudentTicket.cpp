#include "StudentTicket.h"

double StudentTicket::calculateDiscount(double price) const
{
    return 0.5 * price;
}

StudentTicket::StudentTicket(const char* name, double price):Ticket(name, calculateDiscount(price))
{
}
