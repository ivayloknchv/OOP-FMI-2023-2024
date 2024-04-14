#include "ConstantsAndHelpers.h"

int GenresNS::getGenrePosition(char symbol)
{
	switch (symbol)
	{
	case 'p':
		return Genres::POP;
		break;

	case 'r':
		return Genres::ROCK;
		break;

	case 'h':
		return Genres::HIPHOP;
		break;

	case 'e':
		return Genres::ELECTRONIC;
		break;

	case 'j':
		return Genres::JAZZ;
		break;

	default: break;
	}

	return -1;
}

int getFileSize(std::ifstream& ifs)
{
	int currentPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);
	int size = ifs.tellg();
	ifs.seekg(currentPos);
	return size;
}

int getMin(int lhs, int rhs)
{
	return (lhs >= rhs) ? rhs : lhs;
}