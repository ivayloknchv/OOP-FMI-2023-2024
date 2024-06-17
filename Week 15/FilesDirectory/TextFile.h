#pragma once
#include "File.h"

class TextFile : public File
{
	double size = 0.00;

public:

	TextFile(const char* name, double size);

	File* clone() const override;
	void print() const override;
	double getSize() const override;
};

