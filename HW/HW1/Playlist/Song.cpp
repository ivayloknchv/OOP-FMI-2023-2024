#include "Song.h"
#include "ConstantsAndHelpers.h"
#include <iostream>
#include <cstring>

#pragma warning (disable : 4996)

void Song::modifyGenre(const char* genre)
{
	if (!genre)
	{
		return;
	}

	while (*genre != '\0')
	{
		int shift = GenresNS::getGenrePosition(*(genre++));


		if (shift != -1)
		{
			this->genre = this->genre | 1 << shift;
		}
	}
}

void Song::printGenre() const
{
	bool flag = false; // flag is false before a genre on odd position is printed, flips to true afterwards

	for (int i = Constants::GENRES_COUNT-1; i >= 0; i--)
	{
		if (genre & 1 << i)
		{

			if (flag)
			{
				std::cout << '&';
			}
			findGenreToPrint(i);
			flag = true;
		}
	}
}

void Song::findGenreToPrint(int index) const
{
	switch (index)
	{
	case GenresNS::Genres::ROCK:
		std::cout << "Rock";
		break;
	case GenresNS::Genres::POP:
		std::cout << "Pop";
		break;
	case GenresNS::Genres::HIPHOP:
		std::cout << "Hip-Hop";
		break;
	case GenresNS::Genres::ELECTRONIC:
		std::cout << "Electronic";
		break;
	case GenresNS::Genres::JAZZ:
		std::cout << "Jazz";
		break;
	default: break;
	}
}

Song::Song(const char* songTitle, int hours, int minutes, int seconds, const char* genre, const char* contentFile)
{
	setSongTitle(songTitle);
	setDuration(hours, minutes, seconds);
	setGenre(genre);
	setContent(contentFile);
}

void Song::setSongTitle(const char* songTitle)
{
	if (!songTitle)
	{
		return;
	}
	strcpy(this->songTitle, songTitle);
}

void Song::setDuration(int hours, int minutes, int seconds)
{
	duration = Time(hours, minutes, seconds);
}

void Song::setGenre(const char* genre)
{
	if (!genre)
	{
		return;
	}

	modifyGenre(genre);
}

void Song::setContent(const char* contentFile)
{
	if (!contentFile)
	{
		return;
	}

	std::ifstream ifs(contentFile, std::ios::binary | std::ios::in);

	if (!ifs.is_open())
	{
		return;
	}

	if (getFileSize(ifs) > Constants::MAX_CONTENT)
	{
		std::cout << "Your file is too large! The contnent couldn't be loaded!" << std::endl;
		return;
	}

	ifs.read((char*)content, Constants::MAX_CONTENT);

	ifs.close();
}

const char* Song::getSongTitle() const
{
	return songTitle;
}

const Time& Song::getDuration() const
{
	return duration;
}

unsigned char Song::getGenre() const
{
	return genre;
}

const unsigned char* Song::getContent() const
{
	return content;
}

void Song::addRhythm(int k)
{
	int size = strlen((char*)content);
	int totalBits = Constants::BITS_IN_BYTE * size;
	int countBitsToChange = (totalBits) / k;

	for (int i = 1; i <= countBitsToChange; i++)
	{
		int currentBit = totalBits - i * k;

		int index = currentBit / Constants::BITS_IN_BYTE; //first we need to find which index we need to change a bit at

		int shiftLeft = (index + 1) * Constants::BITS_IN_BYTE - currentBit - 1; //then we calculate the postion of the bit in the char

		content[index] = content[index] | 1 << shiftLeft;
	}
}

void Song::mixSong(const Song& newSong)
{
	const unsigned char* otherContent = newSong.getContent();

	int l1 = strlen((const char*)content);
	int l2 = strlen((const char*)newSong.getContent());

	int minLen = getMin(l1,l2);

	for (int i = 0; i < minLen; i++)
	{
		content[i] = content[i] ^ otherContent[i];
	}
}

void Song::printSong() const
{
	std::cout << songTitle << ", ";
	duration.printTime();
	std::cout << ", ";
	printGenre();
	std::cout << std::endl;
}