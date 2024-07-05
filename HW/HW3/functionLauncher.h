#pragma once
#include <fstream>
#include "PartialFunction.h"

class FunctionLauncher
{
	static void generateInterval(const PartialFunction* func);

	static void generateRandomValues(const PartialFunction* func);

	static PartialFunction* readFromFile(const char* filePath);

public:

	static void run();
};