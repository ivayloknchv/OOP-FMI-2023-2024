#include "PremiumPlayer.h"
#include <cstring>
#include <utility>

#pragma warning (disable : 4996)
void PremiumPlayer::copyFrom(const PremiumPlayer& other)
{
	name = new char[strlen(other.name) + 1]{};
	strcpy(name, other.name);
}

void PremiumPlayer::moveFrom(PremiumPlayer&& other)
{
	name = other.name;
	other.name = name;
}

void PremiumPlayer::free()
{
	delete[] name;
	name = nullptr;
}

void PremiumPlayer::setName(const char* name)
{
	if (!name || this->name == name)
	{
		return;
	}

	delete[] this->name;
	this->name = new char[strlen(name) + 1]{};
	strcpy(this->name, name);
}

PremiumPlayer::PremiumPlayer(const char* name)
{
	setName(name);
}

PremiumPlayer::PremiumPlayer(const PremiumPlayer& other) :Player(other)
{
	copyFrom(other);
}

PremiumPlayer& PremiumPlayer::operator=(const PremiumPlayer& other)
{
	if (this != &other)
	{
		Player::operator=(other);
		free();
		copyFrom(other);
	}

	return *this;
}

PremiumPlayer::PremiumPlayer(PremiumPlayer&& other) noexcept :Player(std::move(other))
{
	moveFrom(std::move(other));
}

PremiumPlayer& PremiumPlayer::operator=(PremiumPlayer&& other) noexcept
{
	if (this != &other)
	{
		Player::operator=(std::move(other));
		free();
		moveFrom(std::move(other));
	}

	return *this;
}

PremiumPlayer::~PremiumPlayer()
{
	free();
}

bool PremiumPlayer::levelUp()
{
	if (stars == Stars::FIVE)
	{
		return false;
	}

	int currentStars = (int)stars+1;

	if (points >= POINTS_LEVEL_GAP)
	{
		stars = (Stars)(currentStars);
		points -= POINTS_LEVEL_GAP;

		return true;
	}

	return false;
}

const char* PremiumPlayer::getName() const
{
	return name;
}
