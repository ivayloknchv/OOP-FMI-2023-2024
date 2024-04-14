#include "Row.h"
#pragma once

struct htmlTable
{
	Row rows[Constants::MAX_ROWS_COUNT]{};
	int rowCount = 0;

	void editCell();

	void addRow();

	void removeRow();

	void printTable() const;

private:

	int getMaxColSize() const;

	bool validateRow(int row) const;

	bool validateEdit(int row, int col, const char* newStr) const;

	bool editCell(int row, int col, const char* newStr);

	bool removeRow(int rowToRemove);
	
	void shiftTableDown(int row);
	
	int getMaxSizeOfSingleColumn(int currentCol) const;

	void getSizeOfColums(int* colSizes, int size) const;
};