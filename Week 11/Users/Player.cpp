#include "Player.h"

int Player::idCounter = 0;

static unsigned getPowOfTwo(int num)
{
	return 2 << num;
}

Player::Player()
{
	id = idCounter;
	idCounter++;
}

bool Player::levelUp()
{
	if (stars == Stars::FIVE)
	{
		return false;
	}

	int currentStars = (int)(stars) + 1;

	if (points >= (getPowOfTwo(currentStars-1))* POINTS_LEVEL_GAP)
	{
		stars = (Stars)(currentStars);
		points -= currentStars * (getPowOfTwo(currentStars)) * POINTS_LEVEL_GAP;
		return true;
	}
	return false;
}

void Player::addPoints(int pointsToAdd)
{
	points += pointsToAdd;
}

int Player::getID() const
{
	return id;
}

int Player::getPoints() const
{
	return points;
}

Stars Player::getStars() const
{
	return stars;
}
