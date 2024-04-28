#pragma once

class Person
{
private:
	char* name = nullptr;
	int age = 0;

	void copyFrom(const Person& other);
	void moveFrom(Person&& other);
	void free();

public:

	Person() = default;
	Person(const Person& other);
	Person& operator=(const Person& other);
	Person(Person&& other) noexcept;
	Person& operator=(Person&& other) noexcept;
	~Person();

	Person(const char* newName, int newAge);

	const char* getName() const;
	int getAge() const;

	void print() const;

protected:

	void setName(const char* newName);
	void setAge(int newAge);
};

