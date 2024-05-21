#include <iostream>
#include "MeteoStation.h"
#include "NewspaperObserver.h"
#include "Observer.h"
#include "RadioObserver.h"
#include "TVObserver.h"

int main()
{
	MeteoStation ms("vraca", 33.21);

	Observer* o1 = new TVObserver("media", "vraca", 34.55);

	Observer* o2 = new RadioObserver("radio", "vraca", 32.55);

	ms.registerObserver(o1);
	ms.registerObserver(o2);

	ms.setTemperature(36);

	o1->printMeteo();
	o2->printMeteo();

	ms.unregisterObserver(o1);
	ms.setTemperature(20);

	o2->printMeteo();

	delete o1;
	delete o2;
	return 0;
}
