#pragma once
#include "Player.h"

class LoggedInUser: public Player
{
	static constexpr int MAX_LEN = 8;
	char password[MAX_LEN] = {};

	void setPassword(const char* password);

public:

	LoggedInUser(const char* password);

	bool logIn(int id, const char* password) const;
};

