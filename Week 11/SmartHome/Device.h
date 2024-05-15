#pragma once

class Device
{
	char* _name = nullptr;
	char* _manufacturer = nullptr;

	void copyFrom(const Device& other);
	void moveFrom(Device&& other);
	void free();

public:

	Device() = default;
	Device(const Device& other);
	Device& operator=(const Device& other);
	Device(Device&& other) noexcept;
	Device& operator=(Device&& other) noexcept;
	virtual ~Device();

	Device(const char* name, const char* manufacturer);

	virtual Device* clone() const = 0;

	void setName(const char* name);
	void setManufacturer(const char* manufacturer);

	const char* getName() const;
	const char* getManufacturer() const;

	virtual void turnOff() const = 0;
	virtual void turnOn() const = 0;
	virtual void printInfo() const;
};

