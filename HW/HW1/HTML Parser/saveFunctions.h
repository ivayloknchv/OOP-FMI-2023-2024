#include "htmlTable.h"
#include <fstream>

#pragma once

void saveTD(std::ofstream& ofs, const char* field);

void saveTH(std::ofstream& ofs, const char* field);

void saveRow(std::ofstream& ofs, const Row& currentRow);

void saveToFile(std::ofstream& ofs, const htmlTable& table);

void saveToFile(const htmlTable& table, const char* fileName);