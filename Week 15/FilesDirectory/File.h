#pragma once
class File
{
protected:

	char* fileName = nullptr;

private:

	void copyFrom(const File& other);
	void moveFrom(File&& other);
	void free();

public:
	
	File(const char* name);
	File(const File& other);
	File& operator=(const File& other);
	File(File&& other) noexcept;
	File& operator=(File&& other) noexcept;
	virtual ~File();

	virtual void print() const = 0;
	virtual double getSize() const = 0;
	virtual File* clone() const = 0;
	
};

