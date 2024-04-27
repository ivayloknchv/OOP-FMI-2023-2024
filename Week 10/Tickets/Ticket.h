#pragma once

class Ticket
{
	char* name = nullptr;
	double price = 0;

	void copyFrom(const Ticket& other);
	void moveFrom(Ticket&& other);
	void free();

public:

	Ticket() = default;
	Ticket(const Ticket& other);
	Ticket& operator=(const Ticket& other);
	Ticket(Ticket&& other) noexcept;
	Ticket& operator=(Ticket&& other) noexcept;
	~Ticket();

	Ticket(const char* newName, double newPrice);

	void setName(const char* newName);
	void setPrice(double newPrice);

	const char* getName() const;
	double getPrice() const;

	void printInfo() const;
};

