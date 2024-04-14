#include "Playlist.h"
#include <iostream>
#include <fstream>
#include <cstring>

#pragma warning (disable : 4996)

int Playlist::getSongPosition(const char* title) const
{
	if (!title)
	{
		return -1;
	}

	for (int i = 0; i < songsCount; i++)
	{
		if (!strcmp(songs[i].getSongTitle(), title))
		{
			return i;
		}
	}
	return -1;
}

void Playlist::swap(Song& lhs, Song& rhs)
{
	Song temp = lhs;
	lhs = rhs;
	rhs = temp;
}

void Playlist::selectonSort(bool(*pred)(const Song&, const Song&))
{
	int min_idx = 0;

	for (int i = 0; i < songsCount - 1; i++)
	{
		min_idx = i;

		for (int j = i + 1; j < songsCount; j++)
		{
			if (pred(songs[j], songs[min_idx]))
			{
				min_idx = j;
			}
		}

		if (min_idx != i)
		{
			swap(songs[i], songs[min_idx]);
		}
	}
}

bool Playlist::checkIfSongExists(int num) const
{
	if (num != -1)
	{
		return true;
	}

	std::cout << "The song cannot be found on the playlist!" << std::endl;

	return false;
}

void Playlist::addSong(const char* songTitle, int hours, int minutes, int seconds, const char* genre, const char* contentFile)
{
	if (songsCount == Constants::MAX_SONGS)
	{
		std::cout << "Full capacity!" << std::endl;

		return;
	}

	songs[songsCount++] = Song(songTitle, hours, minutes, seconds, genre, contentFile);
}

void Playlist::printPlaylist() const
{
	for (int i = 0; i < songsCount; i++)
	{
		std::cout << i + 1 << ") ";
		songs[i].printSong();
	}
}

void Playlist::searchSongByTitle(const char* songToFind) const
{
	if (!songToFind)
	{
		return;
	}

	int songPosition = getSongPosition(songToFind);

	if (!checkIfSongExists(songPosition))
	{
		return;
	}

	songs[songPosition].printSong();
}

void Playlist::searchSongByGenre(char genre) const
{
	int genreIndex = GenresNS::getGenrePosition(genre);

	if (genreIndex == -1)
	{
		std::cout << "The genre doesn't exist!" << std::endl;
		return;
	}

	for (int i = 0; i < songsCount; i++)
	{
		if (songs[i].getGenre() & 1 << genreIndex)
		{
			songs[i].printSong();
		}
	}
}

void Playlist::sortByName()
{
	selectonSort([](const Song& lhs, const Song& rhs) ->bool {return (strcmp(lhs.getSongTitle(), rhs.getSongTitle()) < 0); });
}

void Playlist::sortByDuration()
{
	selectonSort([](const Song& lhs, const Song& rhs) -> bool {return (lhs.getDuration().TransformIntoSeconds() < rhs.getDuration().TransformIntoSeconds()); });
}

void Playlist::addRhytm(const char* title, int k)
{
	if (!title)
	{
		return;
	}

	int index = getSongPosition(title);

	if (checkIfSongExists(index))
	{
		songs[index].addRhythm(k);
	}
}

void Playlist::remixSongs(const char* lhs, const char* rhs)
{
	if (!lhs || !rhs)
	{
		return;
	}

	int index1 = getSongPosition(lhs);
	int index2 = getSongPosition(rhs);

	if (!checkIfSongExists(index1) || !checkIfSongExists(index2))
	{
		return;
	}

	songs[index1].mixSong(songs[index2]);
}

void Playlist::saveSongToBinaryFile(const char* songTitle, const char* fileName) const
{
	if (!fileName || !songTitle)
	{
		return;
	}

	int songIndex = getSongPosition(songTitle);

	if (!checkIfSongExists(songIndex))
	{
		return;
	}

	std::ofstream ofs(fileName, std::ios::binary | std::ios::out);

	if (!ofs.is_open())
	{
		std::cout << "Problem while opening the file occured!" << std::endl;
		return;
	}

	ofs.write((const char*)&songs[songIndex], sizeof(Song));

	ofs.close();
}

void Playlist::saveContentToBinaryFile(const char* songTitle, const char* fileName) const
{
	if (!fileName || !songTitle)
	{
		return;
	}

	int songIndex = getSongPosition(songTitle);

	if (!checkIfSongExists(songIndex))
	{
		return;
	}

	std::ofstream ofs(fileName, std::ios::binary | std::ios::out);

	if (!ofs.is_open())
	{
		std::cout << "Problem while opening the file occured!" << std::endl;
		return;
	}

	ofs.write((const char*)songs[songIndex].getContent(), sizeof(Song));

	ofs.close();
}