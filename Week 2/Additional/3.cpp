#include <iostream>
#include <fstream>

const unsigned MAX_LEN = 64;
const unsigned MAX_SIZE = 20;

struct City
{
	char cityName[MAX_LEN]{};
	unsigned population;
};

struct District
{
	City cities[MAX_SIZE]{};
	unsigned count = 0;
};

void AddCityToFile(std::ofstream& OutFile, const City& city)
{
	OutFile << city.cityName << ", " << city.population << std::endl;
}

bool AddDistrictToFile(const char* fileName, const District& district)
{
	if (!fileName)
	{
		return false;
	}

	std::ofstream OutFile(fileName);

	if (!OutFile.is_open())
	{
		return false;
	}

	for (unsigned i = 0; i < district.count; i++)
	{
		AddCityToFile(OutFile, district.cities[i]);
	}

	OutFile.close();

	return true;
}

void ReadCityFromFile(std::ifstream& InFile, City& city)
{
	InFile.getline(city.cityName,MAX_LEN,',');
	InFile >> city.population;
	InFile.ignore();
}

void Swap(City& c1, City& c2)
{
	City temp = c1;
	c1 = c2;
	c2 = temp;
}

void SelectionSort(District& district)
{
	int min_idx;

	for (unsigned i = 0; i < district.count - 1; i++)
	{
		min_idx = i;

		for (unsigned j = i + 1; j < district.count; j++)
		{
			if (district.cities[min_idx].population > district.cities[j].population)
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			Swap(district.cities[i], district.cities[min_idx]);
		}
	}
}

void ReadDistrictFromFile(std::ifstream& InFile, District& district)
{
	
	while (true)
	{
		City& temp = district.cities[district.count++];

		ReadCityFromFile(InFile, temp);

		if (InFile.eof())
		{
			break;
		}
	}
}

void RearrangeDistrict(const char* fileNameToRead, const char* fileNameToPrint)
{
	if (!fileNameToRead || !fileNameToPrint)
	{
		return;
	}

	std::ifstream InFile(fileNameToRead);

	if (!InFile.is_open())
	{
		return;
	}

	District district;

	ReadDistrictFromFile(InFile, district);

	AddDistrictToFile(fileNameToPrint, district);

	SelectionSort(district);

	InFile.close();
}


int main()
{
	RearrangeDistrict("file1.txt", "file2.txt");

	return 0;
}
