#pragma once
#include "Song.h"

class Playlist
{
	Song* first = nullptr;

	Song& getLast() const;
	bool findSong(const Song& toFind) const;
public:

	Playlist() = default;
	Playlist(Song* first);

	const Song& operator[](int idx) const;
	Song& operator[](int idx);

	const Song& operator[](const char* name) const;
	Song& operator[](const char* name);

	Playlist& operator+=(Song& newSong);
	Playlist& operator-=(Song& toRemove);

	void operator()() const;
	operator bool() const;

	unsigned getTotalDuration() const;

	unsigned getSongsCount() const;
};

