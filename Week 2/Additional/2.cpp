#include <iostream>
#include <fstream>

namespace Constants
{
	const unsigned MAX_SIZE = 16;
	const unsigned IP_NUMS = 4;
}

union ip
{
	uint32_t num;
	unsigned char ipNums[Constants::IP_NUMS];
};

struct Time 
{
	unsigned hour;
	unsigned minutes;
	unsigned seconds;
};

struct Log
{
	char username[Constants::MAX_SIZE+1];
	ip myIP;
	Time myTime;
};

bool writeIP(const ip myIP, std::ofstream& outFile)
{
	outFile << (unsigned)myIP.ipNums[3] << "." << (unsigned)myIP.ipNums[2] << "." << (unsigned)myIP.ipNums[1] << "." << (unsigned)myIP.ipNums[0]<<' ';

	return true;
}

bool writeTime(const Time& myTime, std::ofstream& outFile)
{
	outFile << myTime.hour << ':' << myTime.minutes << ':' << myTime.seconds;

	return true;
}

bool writeLog(const Log& toWrite, std::ofstream& outFile)
{
	outFile << toWrite.username<<' ';
	writeIP(toWrite.myIP, outFile);
	writeTime(toWrite.myTime, outFile);
	return true;
}

bool writeLogs(const Log* logs, size_t size, const char* filePath) 
{
	if (!filePath)
	{
		return false;
	}

	std::ofstream outFile(filePath);

	if (!outFile.is_open())
	{
		return false;
	}

	for (size_t i = 0; i < size; i++)
	{
		writeLog(logs[i], outFile);

		if (i != size - 1)
		{
			outFile<< '\n';
		}
	}

	outFile.close();

	return true;
}

bool toIP( std::ifstream& inFile, ip& myIP)
{

	uint32_t a = 0, b = 0, c = 0, d = 0;

	inFile >> a;
	inFile.ignore();
	inFile >> b;
	inFile.ignore();
	inFile >> c;
	inFile.ignore();
	inFile >> d;

	myIP.ipNums[3] = a;
	myIP.ipNums[2] = b;
	myIP.ipNums[1] = c;
	myIP.ipNums[0] = d;

	return true;
}

bool readTime(Time& myTime, std::ifstream& inFile)
{
	inFile >> myTime.hour;
	inFile.ignore();
	inFile >> myTime.minutes;
	inFile.ignore();
	inFile >> myTime.seconds;

	return true;
}

bool readLog(Log& toRead, std::ifstream& inFile)
{
	inFile >> toRead.username;
	toIP(inFile, toRead.myIP);
	inFile.ignore();
	readTime(toRead.myTime, inFile);

	return true;
}

size_t logsCount(std::ifstream& inFile)
{
	size_t counter = 0;

	char temp;

	while (true)
	{
		temp = inFile.get();

		if (inFile.eof())
		{
			break;
		}

		if (temp == '\n')
		{
			counter++;
		}
	}

	return counter+1;
}

size_t readLogs(Log* logs, const char* filePath)
{
	if (!filePath || !logs)
	{
		return -1;
	}

	std::ifstream inFile(filePath);

	if (!inFile.is_open())
	{
		return -1;
	}

	size_t count = logsCount(inFile);

	for (size_t i = 0; i < count; i++)
	{
		readLog(logs[i], inFile);
	}

	inFile.close();

	return count;
}

int main()
{
	Log logs[3]= {
		{"user1", 35451667, {12, 30, 45}},
		{"user2", 21234766, {8, 15, 20}},
		{"user3", 12346356, {23, 59, 59}}
	};

	writeLogs(logs, 3, "logs.txt");

	Log newlogs[5]{};

	size_t count = readLogs(newlogs, "logs.txt");

}
