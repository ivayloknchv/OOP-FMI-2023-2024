#pragma once
#include "Library.h"

constexpr int MAX_SIZE = 64;

class Member
{
	char name[MAX_SIZE + 1]{};
	int memberID = 0;
	Library* library;
	const Book* borrowed = nullptr;

public:

	Member(const char* newName, int newMemberID, Library* newLib);
	void borrowBook(const char* bookName);
	void returnBook();

	void setName(const char* newName);
	void setId(int newId);
	void setLibrary(Library* newLibrary);

	const char* getName() const;
	int getID() const;
	const Book* getBook() const;
};