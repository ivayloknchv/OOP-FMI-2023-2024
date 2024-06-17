#include <iostream>
#include <fstream>

class Base
{
public:
	virtual ~Base() = default;
};

class A : public Base
{};

class B: public Base
{};

class SingletonFactory
{
private:
	size_t* nums = nullptr;
	size_t current = 0;
	size_t numSize = 0;

	SingletonFactory()
	{
		std::ifstream ifs("data.txt");

		if (!ifs.is_open())
		{
			throw std::exception("Cannot open file!");
		}

		ifs >> numSize;

		nums = new size_t[numSize]{};

		size_t iter = 0;

		while (!ifs.eof())
		{
			ifs >> nums[iter++];
		}
	}

	~SingletonFactory()
	{
		delete[] nums;
		nums = nullptr;
		numSize = current = 0;
	}

public:

	static SingletonFactory& getInstance()
	{
		static SingletonFactory instance;
		return instance;
	}

	SingletonFactory(const SingletonFactory& other) = delete;
	SingletonFactory& operator=(const SingletonFactory& other) = delete;

	Base* create()
	{
		if (current >= numSize)
		{
			return nullptr;
		}

		if (nums[current++] % 2 == 0)
		{
			return new A();
		}
		else
		{
			return new B();
		}
	}
};

int main()
{
	SingletonFactory& inst = SingletonFactory::getInstance();
	
	Base* ptr = inst.create();
	delete ptr;

	return 0;
}
