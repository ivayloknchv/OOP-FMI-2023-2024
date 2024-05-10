#include "LoggedInUser.h"
#include <cstring>

#pragma warning (disable : 4996)

LoggedInUser::LoggedInUser(const char* password)
{
	setPassword(password);
}

void LoggedInUser::setPassword(const char* password)
{
	if (!password || strlen(password)>8)
	{
		return;
	}

	strcpy(this->password, password);
}

bool LoggedInUser::logIn(int id, const char* password) const
{
	if (!password)
	{
		return false;
	}
	return (this->getID() == id && !strcmp(this->password, password));
}
