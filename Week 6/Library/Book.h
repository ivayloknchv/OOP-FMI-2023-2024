#pragma once
#include <fstream>

constexpr int MAX_ISBN = 13;

enum class Genres:char
{
	unknown,
	thriller,
	crime,
	fantasy,
	romance,
	scifi
};

class Book
{
	char* name = nullptr;
	char* content = nullptr;
	int releaseYear = 0;
	char ISBN[MAX_ISBN + 1]{};
	Genres genre = Genres::unknown;	
	
	void copyFrom(const Book& other);
	void free();

public:

	Book();
	Book(const Book& other);
	Book& operator=(const Book& other);
	~Book();

	Book(const char* newName, const char* newContent, int newReleaseYear, const char* newISBN, Genres newGenre);

	void setName(const char* newName);
	void setContent(const char* newContent);
	void setReleaseYear(int newReleaseYear);
	void setISBN(const char* newISBN);
	void setGenre(Genres newGenre);

	const char* getName() const;
	const char* getContent() const;
	int getReleaseYear() const;
	const char* getISBN() const;
	Genres getGenre() const;

	void saveToFile(std::ofstream& ofs) const;
	friend Book readFromFile(std::ifstream& ifs);
};

Book readFromFile(std::ifstream& ifs);