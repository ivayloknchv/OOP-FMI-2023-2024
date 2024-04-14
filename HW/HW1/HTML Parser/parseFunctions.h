#include <fstream>
#include "htmlTable.h"
#pragma once

void readTableCell(std::ifstream& ifs, Row& currentRow);

void parseFromFile(std::ifstream& ifs, htmlTable& myTable);

bool parseFromFile(const char* fileName, htmlTable& myTable);