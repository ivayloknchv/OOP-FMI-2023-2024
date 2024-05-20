#pragma once
#include <iostream>
#include "Helpers.h"

class FlightScanner
{
	char inputFile[1024] = "";
	char outputFile[1024] = "";
	unsigned lineIndex = 0;

	struct FlightRecord
	{
		char origin[1024] = "";
		char destination[1024] = "";
		unsigned amount = 0;
	};

	void handleAirport(char* airport) const;
	void parseLine(const char* line, FlightRecord& record);
	bool readAndExport(std::ifstream& ifs);
	void saveRecord(std::ofstream& ofs, const FlightRecord& record) const;
public:

	FlightScanner(const char* inputFile, const char* outputFile);
	void run();
};

