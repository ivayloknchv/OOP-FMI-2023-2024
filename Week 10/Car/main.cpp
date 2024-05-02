#include <iostream>
#include "Car.h"
int main()
{
	Accumulator acc("AccumulatorProducer", "Best in the world", 200, "65battery32");
	Engine en1("Engine Producer", "Engine model",50);
	Engine en2("Engine Producer", "Engine model", 55);
	Tyre t("Tyre Factory", "Description", 217, 60, 15);

	Car c1(&en1, &t, &t, &t, &t, &acc, 5342, 1500, 60);
	Car c2(&en2, &t, &t, &t, &t, &acc, 5342, 1500, 60);

	Car* winner = dragRace(&c1, &c2);

	return 0;
}