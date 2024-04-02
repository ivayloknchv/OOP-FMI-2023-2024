#include "Member.h"
#include <cstring>

Member::Member(const char* newName, int newMemberID, Library* newLib)
{
	setName(newName);
	setId(newMemberID);
	setLibrary(newLib);
}

void Member::borrowBook(const char* bookName)
{
	if (!bookName)
	{
		return;
	}
	borrowed = library->borrowBook(bookName);
}

void Member::returnBook()
{
	if (!borrowBook)
	{
		return;
	}

	library->returnBook(*borrowed);
	borrowed = nullptr;
}

void Member::setName(const char* newName)
{
	if (!newName)
	{
		return;
	}

	if (strlen(newName) > MAX_SIZE)
	{
		return;
	}

	strcpy(name, newName);
}

void Member::setId(int newId)
{
	memberID = newId;
}

void Member::setLibrary(Library* newLibrary)
{
	if (!newLibrary)
	{
		return;
	}

	library = newLibrary;
}

const char* Member::getName() const
{
	return name;
}

int Member::getID() const
{
	return memberID;
}

const Book* Member::getBook() const
{
	return borrowed;
}
