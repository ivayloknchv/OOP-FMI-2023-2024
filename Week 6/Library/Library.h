#pragma once
#include "Book.h"
#include "Bitset.h"

constexpr int MAX_BOOKS = 1024;

class Library
{
	Book books[MAX_BOOKS]{};
	Bitset isAvailable;
	int size = 0;

	int bookIdx(const char* book) const;
	void swap(Book& lhs, Book& rhs);
public:

	void addBook(const Book& book);
	void removeBook(Book& book);
	const Book* borrowBook(const char* book);
	void returnBook(const Book& book);

	void saveBooksToFile(const char* filePath) const;
	void readBooksFromFile(const char* filePath);
};
