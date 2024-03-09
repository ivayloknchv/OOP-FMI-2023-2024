#include <iostream>
#include <fstream>

constexpr unsigned MAX_SIZE = 23;

struct Person {
	char name[MAX_SIZE + 1];
	double salary;
};

size_t getSize(std::ifstream& ifs)
{
	size_t currentPos = (size_t)ifs.tellg();

	ifs.seekg(0, std::ifstream::end);

	size_t size= (size_t)ifs.tellg();

	ifs.seekg(0, currentPos);

	return size;
}

void printPeople(std::ifstream& ifs,double avgSalary)
{
	size_t size = getSize(ifs);

	size /= sizeof(Person);

	Person* people = new Person[size];

	ifs.read((char*)people, (long long)size * sizeof(Person));

	for (size_t i = 0; i < size; i++)
	{
		if (people[i].salary>avgSalary)
		{
			std::cout << people[i].name << ' ' << people[i].salary<<std::endl;
		}
	}

	delete[] people;
}

void printPeople(const char* fileName, double avgSalary)
{
	if (!fileName)
	{
		return;
	}

	std::ifstream ifs(fileName, std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		return;
	}

	printPeople(ifs, avgSalary);

	ifs.close();
}

void addPerson(std::ofstream& ofs, const Person& person)
{
	ofs.write((const char*)&person, sizeof(person));
}

void addPerson(const char* fileName, const Person& person)
{
	if (!fileName)
	{
		return;
	}

	std::ofstream ofs(fileName, std::ios::out | std::ios::app | std::ios::binary);

	if (!ofs.is_open())
	{
		return;
	}

	addPerson(ofs, person);

	ofs.close();
}

int main()
{
	return 0;
}
