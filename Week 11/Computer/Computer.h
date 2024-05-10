#pragma once

class Computer
{
private:
	double cpuPower = 0;
	char* graphicsCardModel = nullptr;
	int chargePower = 0;

	void copyFrom(const Computer& other);
	void moveFrom(Computer&& other);
	void free();
public:

	Computer() = default;
	Computer(const Computer& other);
	Computer& operator=(const Computer& other);
	Computer(Computer&& other) noexcept;
	Computer& operator=(Computer&& other) noexcept;
	virtual ~Computer() noexcept;


	Computer(double newCPUpower, const char* newGraphicCard, int newChargePower);
	void setCPU(double newCPUpower);
	void setGrapicCard(const char* newGraphicCard);
	void setChargePower(int newChargePower);

	virtual const char* getDevices() const = 0;

	virtual void printType() const = 0;
	
};

