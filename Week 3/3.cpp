#include <iostream>
#include <fstream>

namespace Constants
{
	constexpr size_t MAX_SIZE = 25;
}

struct JobOffer 
{
	char companyName[Constants::MAX_SIZE+1];
	size_t staffCount;
	size_t daysOff;
	double moneyProject;
};

JobOffer initOffer()
{
	JobOffer myOffer;

	std::cin >> myOffer.companyName;
	std::cin >> myOffer.staffCount;
	std::cin >> myOffer.daysOff;
	std::cin >> myOffer.moneyProject;

	return myOffer;
}

void initOffers(JobOffer* offers, const size_t size)
{
	for (size_t i = 0; i < size; i++)
	{
		offers[i] = initOffer();
	}
}

void writeOnFile(std::ofstream& ofs, const JobOffer* offers, const size_t size)
{
	ofs.write((const char*)offers, size * sizeof(JobOffer));
}

void writeOnFile(const char* fileName,const JobOffer* offers, const size_t size)
{
	if (!fileName || !offers)
	{
		return;
	}

	std::ofstream ofs(fileName, std::ios::out | std::ios::app | std::ios::binary);

	if (!ofs.is_open())
	{
		return;
	}

	writeOnFile(ofs, offers, size);

	ofs.close();
}

size_t getSize(std::ifstream& ifs)
{
	size_t currentPos = ifs.tellg();

	ifs.seekg(0, std::ios::end);

	size_t size = (size_t)ifs.tellg();

	ifs.seekg(0, currentPos);

	return size / sizeof(JobOffer);
}

void printOffer(const JobOffer& offer)
{
	std::cout << offer.companyName << ' ' << offer.staffCount << ' ' << offer.daysOff << ' ' << offer.moneyProject << std::endl;
}

void filterOffer(std::ifstream& ifs, size_t minSalary)
{
	size_t size = getSize(ifs);

	JobOffer* offers = new JobOffer[size];

	ifs.read((char*)offers, size * sizeof(JobOffer));

	for (size_t i = 0; i < size; i++)
	{
		if (offers[i].moneyProject > minSalary)
		{
			printOffer(offers[i]);
		}
	}

	delete[] offers;
}

void filterOffer(const char* filePath, size_t minSalary)
{
	if (!filePath)
	{
		return;
	}

	std::ifstream ifs(filePath, std::ios::in | std::ios::binary);

	if (!ifs.is_open())
	{
		return;
	}

	filterOffer(ifs, minSalary);
}

bool findOffer(std::ifstream& ifs, const char* name)
{
	size_t size = getSize(ifs);

	JobOffer* offers = new JobOffer[size];

	ifs.read((char*)offers, size * sizeof(JobOffer));

	for (size_t i = 0; i < size; i++)
	{
		if (!strcmp(offers[i].companyName, name))
		{
			return true;
		}
	}

	delete[] offers;

	return false;
}

bool findOffer(const char* filePath, const char* name)
{
	if (!filePath || !name)
	{
		return false;
	}

	std::ifstream ifs(filePath);

	if (!ifs.is_open())
	{
		return false;
	}

	return findOffer(ifs, name);
}

int main()
{
	return 0;
}