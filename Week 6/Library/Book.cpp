#include "Book.h"
#include <cstring>

#pragma warning (disable : 4996)

void Book::copyFrom(const Book& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	content = new char[strlen(other.content) + 1];
	strcpy(content, other.content);

	strcpy(ISBN, other.ISBN);

	genre = other.genre;

	releaseYear = other.releaseYear;
}

void Book::free()
{
	delete[] name;
	delete[] content;

	name = nullptr;
	content = nullptr;
	releaseYear = 0;
	ISBN[0] = '\0';
	genre = Genres::unknown;
}

Book::Book() = default;

Book::Book(const Book & other)
{
	copyFrom(other);
}

Book& Book::operator=(const Book& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}

	return *this;
}

Book::~Book()
{
	free();
}

Book::Book(const char* newName, const char* newContent, int newReleaseYear, const char* newISBN, Genres newGenre)
{
	setName(newName);
	setContent(newContent);
	setReleaseYear(newReleaseYear);
	setISBN(newISBN);
	setGenre(newGenre);
}

void Book::setName(const char* newName)
{
	if (!newName)
	{
		return;
	}

	if (name == newName)
	{
		return;
	}

	delete[] name;
	name = new char[strlen(newName) + 1];
	strcpy(name, newName);
}

void Book::setContent(const char* newContent)
{
	if (!newContent)
	{
		return;
	}

	if (newContent == content)
	{
		return;
	}

	delete[] content;
	strcpy(content, newContent);
}

void Book::setReleaseYear(int newReleaseYear)
{
	if (newReleaseYear < 1900)
	{
		return;
	}

	releaseYear = newReleaseYear;
}

void Book::setISBN(const char* newISBN)
{
	if (!newISBN)
	{
		return;
	}

	strcpy(ISBN, newISBN);
}

void Book::setGenre(Genres newGenre)
{
	genre = newGenre;
}

const char* Book::getName() const
{
	return name;
}

const char* Book::getContent() const
{
	return content;
}

int Book::getReleaseYear() const
{
	return releaseYear;
}

const char* Book::getISBN() const
{
	return ISBN;
}

Genres Book::getGenre() const
{
	return genre;
}

void Book::saveToFile(std::ofstream& ofs) const
{
	int nameLen = strlen(name);
	ofs.write((const char*)&nameLen, sizeof(int));
	ofs.write(name, strlen(name));

	int contentLen = strlen(content);
	ofs.write((const char*)&contentLen, sizeof(int));
	ofs.write(content, strlen(content));

	ofs.write((const char*)releaseYear, sizeof(releaseYear));
	ofs.write(ISBN, MAX_ISBN);
	ofs.write((const char*)&genre, sizeof(genre));

}

Book readFromFile(std::ifstream& ifs)
{
	Book newBook;
	
	int nameSize = 0;
	ifs.read((char*)&nameSize, sizeof(nameSize));

	newBook.name = new char[nameSize + 1];
	newBook.name[nameSize] = '\0';
	ifs.read(newBook.name, nameSize);

	int contentSize = 0;
	ifs.read((char*)&contentSize, sizeof(contentSize));

	newBook.content = new char[contentSize + 1];
	newBook.content[contentSize] = '\0';
	ifs.read(newBook.content, contentSize);

	ifs.read((char*)&newBook.releaseYear, sizeof(newBook.releaseYear));
	ifs.read(newBook.ISBN, MAX_ISBN);
	ifs.read((char*)&newBook.genre, sizeof(newBook.genre));

	return newBook;
}
