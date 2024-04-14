#include <fstream>
#pragma once

namespace Constants
{
	constexpr int MAX_NAME = 64;
	constexpr int MAX_CONTENT = 256;
	constexpr int MAX_SONGS = 30;
	constexpr int GENRES_COUNT = 5;
	constexpr int BITS_IN_BYTE = 8;
}

namespace GenresNS
{
	enum Genres
	{
		JAZZ,
		ELECTRONIC,
		HIPHOP,
		POP,
		ROCK
	};

	int getGenrePosition(char symbol);
}

int getFileSize(std::ifstream& ifs);

int getMin(int lhs, int rhs);