#pragma once
#include <fstream>

namespace Helpers
{
	size_t getFileSize(std::ifstream & ifs);
	size_t getSymbolsCount(std::ifstream& ifs, char ch);
}