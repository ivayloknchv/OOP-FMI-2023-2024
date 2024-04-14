#include "Field.h"
#pragma once

struct Row
{
	Field fields[Constants::MAX_ROW_SIZE]{};
	bool headingsHistogram[Constants::MAX_ROW_SIZE]{};
	int colCount = 0;

	void printRow(const int* colSizes, int maxColSize) const;

	void fillRow(const char* information);

	void emptyRow();

private:

	void printWhiteSpaces(int count) const;

	void printIfHeading(bool pred) const;

};