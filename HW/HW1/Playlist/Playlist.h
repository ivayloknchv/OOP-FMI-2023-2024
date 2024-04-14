#include "Song.h"
#pragma once

class Playlist
{
private:

	Song songs[Constants::MAX_SONGS]{};
	int songsCount = 0;

	int getSongPosition(const char* title) const;

	void swap(Song& lhs, Song& rhs);

	void selectonSort(bool(*pred)(const Song&, const Song&));

	bool checkIfSongExists(int num) const;

public:

	void addSong(const char* songTitle, int hours, int minutes, int seconds, const char* genre, const char* contentFile);

	void printPlaylist() const;

	void searchSongByTitle(const char* songToFind) const;

	void searchSongByGenre(char genre) const;

	void sortByName();

	void sortByDuration();

	void addRhytm(const char* title, int k);

	void remixSongs(const char* lhs, const char* rhs);

	void saveSongToBinaryFile(const char* songTitle, const char* fileName) const;

	void saveContentToBinaryFile(const char* songTitle, const char* fileName) const;
};
