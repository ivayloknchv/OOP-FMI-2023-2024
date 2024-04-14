#include "Time.h"
#include "ConstantsAndHelpers.h"
#pragma once

class Song
{
private:

	char songTitle[Constants::MAX_NAME + 1]{};
	Time duration;
	unsigned char genre = 0;
	unsigned char content[Constants::MAX_CONTENT + 1]{};

	void modifyGenre(const char* genre);

	void printGenre() const;

	void findGenreToPrint(int index) const;

public:

	Song() = default;

	Song(const char* songTitle, int hours, int minutes, int seconds, const char* genre, const char* contentFile);

	void setSongTitle(const char* songTitle);

	void setDuration(int hours, int minutes, int seconds);

	void setGenre(const char* genre);

	void setContent(const char* contentFile);

	const char* getSongTitle() const; 

	const Time& getDuration() const;

	unsigned char getGenre() const;

	const unsigned char* getContent() const;

	void addRhythm(int k);

	void mixSong(const Song& newSong);

	void printSong() const;
};