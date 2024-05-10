#pragma once
#include "Player.h"

class Guest : public Player
{
	unsigned minutesToStay = 0;

public:

	Guest(int mintesToStay);

	bool levelUp() override;
};

