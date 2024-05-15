#include <iostream>
#include "Device.h"
#include "SmartLight.h"
#include "SmartThermostat.h"
#include "SmartSpeaker.h"
#include "SmartHome.h"

int main()
{
	SmartSpeaker sp("speaker", "sony", 34);
	SmartHome home;
	home.add(&sp);
	
	home.addTheromstat("thermo", "tesy", 28, 30);
	home.showAll();

	home.removeByIdx(0);
	home.showAll();
	return 0;
}