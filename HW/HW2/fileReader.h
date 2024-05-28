#pragma once
#include <fstream>
#include "PartialFunction.h"


PartialFunction* readFromFile(std::ifstream& ifs);

PartialFunction* readFromFile(const char* filePath);