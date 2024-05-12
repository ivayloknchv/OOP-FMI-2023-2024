#include "Song.h"
#include <cstring>
#include <utility>
#include <iostream>

#pragma warning (disable : 4996)

void Song::copyFrom(const Song& other)
{
	name = new char[strlen(other.name) + 1]{};
	strcpy(name, other.name);

	genre = new char[strlen(other.genre) + 1]{};
	strcpy(genre, other.genre);

	duration = other.duration;

	next = other.next;
}

void Song::moveFrom(Song&& other)
{
	name = other.name;
	genre = other.genre;
	duration = other.duration;
	next = other.next;

	other.name = nullptr;
	other.genre = nullptr;
	other.duration = 0;
	other.next = 0;
}

void Song::free()
{
	delete[] name;
	name = nullptr;

	delete[] genre;
	genre = nullptr;

	duration = 0;

	next = nullptr;
}

Song::Song(const Song& other)
{
	copyFrom(other);
}

Song& Song::operator=(const Song& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Song::Song(Song&& other) noexcept
{
	moveFrom(std::move(other));
}

Song& Song::operator=(Song&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

Song::~Song()
{
	free();
}

Song::Song(const char* name, const char* genre, unsigned duration, Song* next)
{
	setName(name);
	setGenre(genre);
	setDuration(duration);
	setNextSong(next);
}

void Song::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	delete[] this->name;
	this->name = new char[strlen(name) + 1]{};
	strcpy(this->name, name);
}

void Song::setGenre(const char* genre)
{
	if (!genre || this->genre == genre)
	{
		return;
	}

	delete[] this->genre;
	this->genre = new char[strlen(genre) + 1]{};
	strcpy(this->genre, genre);
}

void Song::setDuration(unsigned duration)
{
	if (duration > MAX_DURATION)
	{
		duration = MAX_DURATION;
	}

	this->duration = duration;
}

void Song::setNextSong(Song* next)
{
	this->next = next;
}

const char* Song::getName() const
{
	return name;
}

const char* Song::getGenre() const
{
	return genre;
}

unsigned Song::getDuration() const
{
	return duration;
}

 Song* Song::getNextSong() const
{
	return next;
}

 void Song::printSong() const
 {
	 std::cout << name << ' ' << genre << ' ' << duration << std::endl;
 }
