#include "Playlist.h"
#include <stdexcept>
#include <cstring>

#pragma warning (disable : 4996)

Song& Playlist::getLast() const
{
	Song* current = first;
	Song* next = first->getNextSong();

	while (next != nullptr)
	{
		current = next;
		next = next->getNextSong();
	}

	return *current;
}

bool Playlist::findSong(const Song& toFind) const
{
	const Song* current = first;
	const Song* next = first->getNextSong();

	while (strcmp(current->getName(), toFind.getName()))
	{
		current = next;

		if (current == nullptr)
		{
			return false;
		}

		next = next->getNextSong();
	}

	return true;
}

Playlist::Playlist(Song* first)
{
	this->first = first;
}

const Song& Playlist::operator[](int idx) const
{
	int counter = 0;

	const Song* current = first;
	const Song* next = first->getNextSong();

	while (counter != idx)
	{
		if (current == nullptr)
		{
			throw std::invalid_argument("Such song doesn't exist!");
		}

		current = next;
		next = next->getNextSong();
		counter++;
	}

	return *current;
}

Song& Playlist::operator[](int idx)
{
	int counter = 0;

	Song* current = first;
	Song* next = first->getNextSong();

	while (counter != idx)
	{
		if (current == nullptr)
		{
			throw std::invalid_argument("Such song doesn't exist!");
		}

		current = next;
		next = next->getNextSong();
		counter++;
	}

	return *current;
}

const Song& Playlist::operator[](const char* name) const
{
	const Song* current = first;
	const Song* next = first->getNextSong();

	while (strcmp(current->getName(), name))
	{
		current = next;

		if (current == nullptr)
		{
			throw std::invalid_argument("Such song doesn't exist!");
		}

		next = next->getNextSong();
	}

	return *current;
}

Song& Playlist::operator[](const char* name)
{
	Song* current = first;
	Song* next = first->getNextSong();

	while (strcmp(current->getName(), name))
	{
		current = next;

		if (current == nullptr)
		{
			throw std::invalid_argument("Such song doesn't exist!");
		}

		next = next->getNextSong();
	}

	return *current;
}

Playlist& Playlist::operator+=(Song& newSong)
{
	Song& last = getLast();
	last.setNextSong(&newSong);
	return *this;
}

Playlist& Playlist::operator-=(Song& toRemove)
{
	if (findSong(toRemove))
	{
		if (!strcmp(first->getName(), toRemove.getName()))
		{
			first = first->getNextSong();
		}

		else
		{
			Song* current = first;
			Song* next = current->getNextSong();

			while (next != nullptr)
			{
				if (!strcmp(next->getName(), toRemove.getName()))
				{
					current->setNextSong(next->getNextSong());

					if (next->getNextSong() != nullptr)
					{
						current = next->getNextSong();
						next = current->getNextSong();
					}
					else
					{
						next = nullptr;
					}
					toRemove.setNextSong(nullptr);
				}
				else
				{
					current = next;
					next = next->getNextSong();
				}
			}
		}
	}
	return *this;
}

void Playlist::operator()() const
{
	const Song* current = first;
	const Song* next = current->getNextSong();

	while (current != nullptr)
	{
		current->printSong();
		current = next;

		if (!next)
		{
			break;
		}

		next = next->getNextSong();
	}
}

Playlist::operator bool() const
{
	return first != nullptr;
}

unsigned Playlist::getTotalDuration() const
{
	unsigned toReturn = 0;

	const Song* current = first;
	const Song* next = current->getNextSong();

	while (current != nullptr)
	{
		toReturn += current->getDuration();

		current = next;

		if (!next)
		{
			break;
		}

		next = next->getNextSong();
	}

	return toReturn;
}

unsigned Playlist::getSongsCount() const
{
	unsigned toReturn = 0;

	const Song* current = first;
	const Song* next = current->getNextSong();

	while (current != nullptr)
	{
		toReturn++;

		current = next;

		if (!next)
		{
			break;
		}

		next = next->getNextSong();
	}

	return toReturn;
}

