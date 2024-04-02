#include "Library.h"
#include <cstring>

#pragma warning (disable : 4996)

int Library::bookIdx(const char* book) const
{
	for (int i = 0; i < size; i++)
	{
		if (!strcmp(books[i].getName(), book))
		{
			return i;
		}
	}
	return -1;
}

void Library::swap (Book& lhs, Book& rhs)
{
	Book temp=lhs;
	lhs = rhs;
	rhs = temp;
}

void Library::addBook(const Book& book)
{
	if (size == MAX_BOOKS)
	{
		return;
	}

	if (bookIdx(book.getName())!=-1)
	{
		return;
	}

	books[size] = book;
	isAvailable.addNumber(size);
	size++;
}

void Library::removeBook(Book& book)
{
	int wantedIdx = bookIdx(book.getName());

	if (wantedIdx==-1)
	{
		return;
	}

	swap(books[wantedIdx], books[size - 1]);
	isAvailable.removeNumber(size);

	if (isAvailable.hasNumber(size)) 
	{
		isAvailable.addNumber(wantedIdx);
	}
	else 
	{
		isAvailable.removeNumber(wantedIdx);
	}

	size--;
}

const Book* Library::borrowBook(const char* book)
{
	int idx = bookIdx(book);

	if (idx == -1)
	{
		return nullptr;
	}

	isAvailable.removeNumber(idx);
	return &books[idx];
}

void Library::returnBook(const Book& book)
{
	int idx = bookIdx(book.getName());

	if (idx == -1)
	{
		return;
	}

	isAvailable.addNumber(idx);
}

void Library::saveBooksToFile(const char* filePath) const
{
	if (!filePath)
	{
		return;
	}

	std::ofstream ofs(filePath, std::ios::binary);

	if (!ofs.is_open())
	{
		return;
	}

	ofs.write((const char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
	{
		books[i].saveToFile(ofs);
	}

	isAvailable.save(ofs);

	ofs.close();
}

void Library::readBooksFromFile(const char* filePath)
{
	if (!filePath)
	{
		return;
	}

	std::ifstream ifs(filePath, std::ios::binary);

	if (!ifs.is_open())
	{
		return;
	}

	ifs.read((char*)&size, sizeof(size));

	for (int i = 0; i < size; i++)
	{
		books[i] = readFromFile(ifs);
	}

	isAvailable = read(ifs);
	ifs.close();
}
