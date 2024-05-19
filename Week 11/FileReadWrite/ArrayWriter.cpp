#include "ArrayWriter.h"
#include <fstream>

ArrayWriter::ArrayWriter(const MyString& filePath) : FileWriter(filePath)
{
}

void ArrayWriter::write(const int* arr, size_t size) const
{
	if (!arr)
	{
		return;
	}

	std::ofstream ofs(filePath.c_str());

	if (!ofs.is_open())
	{
		return;
	}

	ofs <<'[';

	for (size_t i = 0; i < size; i++)
	{
		ofs << arr[i];

		if (i != size - 1)
		{
			ofs << ' ';
		}
	}
	ofs << ']' << '\n';

	ofs.close();
}
