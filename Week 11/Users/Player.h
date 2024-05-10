#pragma once

enum class Stars
{
	ONE,
	TWO,
	THREE,
	FOUR,
	FIVE
};

class Player
{
protected:

	static int idCounter;
	static constexpr int POINTS_LEVEL_GAP = 256;

	int id = 0;
	int points = 0;
	Stars stars = Stars::ONE;

public:

	Player();

	virtual bool levelUp();

	void addPoints(int pointsToAdd);

	int getID() const;
	int getPoints() const;	
	Stars getStars() const;
	
	virtual ~Player() = default;
};

