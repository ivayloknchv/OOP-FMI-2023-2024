#include "FlightScanner.h"
#include <cstring>
#include <fstream>
#include <sstream>
#include <exception>

#pragma warning (disable : 4996)

void FlightScanner::handleAirport(char* airport) const
{
	if (strlen(airport) != 3)
	{
		throw std::length_error("Size is different than 3");
	}
	toUpper(airport);

}

void FlightScanner::parseLine(const char* line, FlightRecord& record)
{
	std::stringstream ss(line);

	ss >> record.origin;

	if (strlen(record.origin) != 3)
	{
		throw std::length_error("Size is different than 3");
	}

	try
	{
		handleAirport(record.origin);
	}
	catch (const std::exception& exc)
	{
		std::cout << "Error while processing the origin. Given: " << record.origin << std::endl;
		throw;
	}

	ss >> record.destination;

	if (strlen(record.destination) != 3)
	{
		throw std::length_error("Size is different than 3");

	}

	try
	{
		handleAirport(record.destination);
	}
	catch (const std::exception& exc)
	{
		std::cout << "Error while processing the destination. Given: " << record.destination << std::endl;
		throw;
	}

	char amountStr[64]{};

	ss >> amountStr;

	try
	{
		record.amount = convertToNum(amountStr);
	}
	catch (const std::bad_cast& exc)
	{
		static constexpr unsigned DEFAULT_AMOUNT = 50;
		std::cout << "Invalid amount. Setting to default value: " << DEFAULT_AMOUNT << std::endl;
		record.amount = DEFAULT_AMOUNT;
		throw;
	}
}

bool FlightScanner::readAndExport(std::ifstream& ifs)
{
	std::ofstream ofs(outputFile, std::ios::out | std::ios::app);

	if (!ofs.is_open())
	{
		std::cout << "Could not open the output file!" << std::endl;
	}

	bool noErrors = true;


	while (!ifs.eof())
	{
		char buffer[1024]{};
		ifs.getline(buffer, 1024);

		FlightRecord record;

		try
		{
			parseLine(buffer, record);
			saveRecord(ofs, record);
		}
		catch (const std::invalid_argument& exc)
		{
			std::cout << "Invalid arugment occured on line " << lineIndex << ": " << exc.what() << ". The flight will NOT be saved! " << std::endl;
			noErrors = false;
		}
		catch (const std::length_error& exc)
		{
			std::cout << "Lenght error occured on line " << lineIndex << ": " << exc.what() << ". The flight will NOT be saved! " << std::endl;
			noErrors = false;
		}
		catch(const std::bad_cast& exc)
		{
			std::cout << "Bad cast error occured on line " << lineIndex << ": " << exc.what() << ". The flight will be saved! " << std::endl;
			saveRecord(ofs, record);
			noErrors = false;
		}
		catch (const std::exception& exc)
		{
			std::cout << "Unknow error occured on line " << lineIndex << ": " << exc.what() << ". The flight will NOT be saved! " << std::endl;
			noErrors = false;
		}
		catch (...)
		{
			std::cout << "Unknown error occured on line " << lineIndex << ". The flight will NOT be saved! " << std::endl;
			noErrors = false;
		}
		lineIndex++;
	}
	return noErrors;
}

void FlightScanner::saveRecord(std::ofstream& ofs, const FlightRecord& record) const
{
	static constexpr double EU_TO_BGN = 1.95;
	ofs << record.origin << ' ' << record.destination << ' ' << record.amount * EU_TO_BGN << std::endl;
}

FlightScanner::FlightScanner(const char* inputFile, const char* outputFile)
{
	strcpy(this->inputFile, inputFile);
	strcpy(this->outputFile, outputFile);
}

void FlightScanner::run()
{
		std::cout << "Scanning for file..." << std::endl;
		std::ifstream ifs(inputFile);

		if (!ifs.fail())
		{
			std::cout << "File Found!" << std::endl;

			if (readAndExport(ifs))
			{
				std::cout << "Successfully exported file!" << std::endl;
			}

			else
			{
				std::cout << "An error occurred while exporting the File!" << std::endl;
			}

			ifs.close();
		}

		else
		{
			std::cout << "File not found!" << std::endl;
		}
}
