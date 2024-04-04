#include <iostream>
#include "Browser.h"

int main()
{
	WebPage wp1("gmail.com","123.21");
	WebPage wp2("facebook.com", "143.21.67");
	WebPage wp3("stackoverflow.com", "192.168.1.1");

	Browser br;
	br.addPage(wp1);
	(br += wp2)+=wp1;
	br += wp3;
	br.print();

	Browser cpy = br;
	cpy -= 1;
	cpy.print();

	return 0;
}