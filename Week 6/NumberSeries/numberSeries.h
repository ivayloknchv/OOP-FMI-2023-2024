#pragma once

class numberSeries
{	
	int* series = nullptr;
	int (*formulaPtr)(int num) = nullptr;
	int a0 = 0;
	int nextIdx = 0;
	int size = 0;

	void copyFrom(const numberSeries& other);
	void free();

	void reAllocateSeries(int newSize);
	void addToSeries(int startIdx);

	bool isNumInAllocatedMemebers(int num)const;

public:

	numberSeries();
	numberSeries(const numberSeries& other);
	numberSeries& operator=(const numberSeries& other);
	~numberSeries();
	
	numberSeries(int(*formulaPtr)(int), int newStart);

	void setStart(int newStart);
	void setFormula(int(*newFormulaPtr)(int));

	int getNumByIndex(int idx);

	bool isNumInSeries(int n) const;
};