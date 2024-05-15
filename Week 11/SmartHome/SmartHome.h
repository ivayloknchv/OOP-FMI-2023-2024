#pragma once
#include "Device.h"
#include "SmartLight.h"
#include "SmartSpeaker.h"
#include "SmartThermostat.h"

class SmartHome
{
private:

	Device** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void copyFrom(const SmartHome& other);
	void moveFrom(SmartHome&& other);
	void free();

	void resize(size_t newCapacity);

public:

	SmartHome();
	SmartHome(const SmartHome& other);
	SmartHome& operator=(const SmartHome& other);
	SmartHome(SmartHome&& other) noexcept;
	SmartHome& operator=(SmartHome&& other) noexcept;
	~SmartHome();

	void add(Device* device);

	void addLight(const char* name, const char* manufacturer, unsigned brightnessLevel);

	void addTheromstat(const char* name, const char* manufacturer, double currentTemperature, double targetTemperature);

	void addSpeaker(const char* name, const char* manufacturer, unsigned volume);

	void removeByIdx(size_t idx);

	void showAll() const;
};

