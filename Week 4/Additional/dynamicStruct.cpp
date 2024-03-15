#include <iostream>
#include <fstream>
#include <cstring>

#pragma warning (disable : 4996)

struct Person
{
	char* name;
	int age;
	double height;
};

void initPerson(Person& p, const char* name, int age, double height)
{
	if (!name)
	{
		return;
	}

	p.name = new char[strlen(name) + 1];

	strcpy(p.name, name);

	p.age = age;

	p.height = height;
}

Person readPerson(std::ifstream& ifs)
{
	Person p;

	int nameLen;

	ifs.read((char*)&nameLen, sizeof(nameLen));

	p.name = new char[nameLen + 1];
	p.name[nameLen] = '\0';

	ifs.read(p.name, nameLen);
	ifs.read((char*)&p.age, sizeof(p.age));
	ifs.read((char*)&p.height, sizeof(p.height));

	return p;
}

void readFromBinary(std::ifstream& ifs, Person*& arr, int& size)
{
	if (!arr)
	{
		return;
	}

	ifs.read((char*)&size, sizeof(size));

	arr = new Person[size];

	for (int i = 0; i < size; i++)
	{
		arr[i] = readPerson(ifs);
	}
}

void readFromBinary(const char* fileName, Person*& arr, int& size)
{
	if (!fileName || !arr)
	{
		return;
	}

	std::ifstream ifs(fileName, std::ios::binary | std::ios::in);

	if (!ifs.is_open())
	{
		return;
	}

	readFromBinary(ifs, arr, size);

	ifs.close();
}

void writePerson(std::ofstream& ofs, const Person& p)
{
	int nameLen = strlen(p.name);

	ofs.write((const char*)&nameLen, sizeof(nameLen));

	ofs.write(p.name, nameLen);

	ofs.write((const char*)&p.age, sizeof(p.age));

	ofs.write((const char*)&p.height, sizeof(p.height));
}

void writeOnBinary(std::ofstream& ofs, const Person* arr, int size)
{
	if (!arr)
	{
		return;
	}

	ofs.write((const char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
	{
		writePerson(ofs, arr[i]);
	}
}

void writeOnBinary(const char* fileName, const Person* arr, int size)
{
	if (!fileName || !arr)
	{
		return;
	}

	std::ofstream ofs(fileName, std::ios::binary | std::ios::out);

	if (!ofs.is_open())
	{
		return;
	}

	writeOnBinary(ofs, arr, size);

	ofs.close();
}

void freePerson(Person& p)
{
	delete[] p.name;
	p.age = 0;
	p.height = 0;
}

void print(const Person* arr, int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i].name << ' ' << arr[i].age << ' ' << arr[i].height << std::endl;
	}
}

int main()
{
	Person* arr;
	int size;
	readFromBinary("people.dat", arr, size);

	print(arr, size);

	for (int i = 0; i < size; i++)
	{
		freePerson(arr[i]);
	}

	delete[] arr;
	return 0;
}
