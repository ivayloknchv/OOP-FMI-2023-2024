#pragma once
#include "File.h"
#include "TextFile.h"

class Folder : public File
{
	File** files = nullptr;
	size_t capacity = 0;
	size_t size = 0;

	void copyFrom(const Folder& other);
	void moveFrom(Folder&& other);
	void free();

	void resize(size_t newCapacity);

public:

	Folder(const char* name);
	Folder(const Folder& other);
	Folder& operator=(const Folder& other);
	Folder(Folder&& other) noexcept;
	Folder& operator=(Folder&& other) noexcept;
	~Folder();

	File* clone() const override;
	double getSize() const override;
	void print() const override;

	void addFile(File* other);
};

