#include <iostream>
#include <cstring>

#pragma warning (disable: 4996)

namespace Constants
{
	constexpr int MIN_AGE = 5;
	constexpr int MAX_AGE = 90;
	constexpr int MIN_NAME= 2;
	constexpr int MAX_NAME = 20;
}

bool isCapitalLetter(char symbol)
{
	return symbol >= 'A' && symbol <= 'Z';
}

bool isLowercase(char symbol)
{
	return symbol >= 'a' && symbol <= 'z';
}

bool  containsOnlySmallLetters(const char* name)
{
	if (!name)
	{
		return false;
	}

	size_t len = strlen(name);

	for (int i = 0; i < len; i++)
	{
		if (!isLowercase(name[i]));
		{
			return false;
		}
	}

	return true;
}

class Person
{
	char name[Constants::MAX_NAME + 1] = "Unknown";
	int age = Constants::MIN_AGE;


	bool isValidAge(int age)
	{
		return (age >= Constants::MIN_AGE && age <= Constants::MAX_AGE);
	}

	bool isValidName(const char* name)
	{
		if (!name)
		{
			return false;
		}

		size_t nameLen = strlen(name);

		if (nameLen<Constants::MIN_NAME || nameLen>Constants::MAX_NAME)
		{
			return false;
		}

		if (!isCapitalLetter(*name))
		{
			return false;
		}

		return containsOnlySmallLetters(name + 1);
	}

public:

	Person() = default;

	Person(const char* name, int age)
	{
		setName(name);
		setAge(age);
	}

	void setName(const char* name)
	{
		if (!isValidName(name))
		{
			strcpy(this->name, "Unknown");
			return;
		}
		strcpy(this->name, name);
	}

	void setAge(int age)
	{
		if (isValidAge(age))
		{
			this->age = Constants::MIN_AGE;

			return;
		}
		this->age = age;
	}

	const char* getName() const
	{
		return name;
	}

	int getAge() const
	{
		return age;
	}
};

int main()
{
	return 0;
}
