#pragma once
#include <iostream>

class WordSet
{
	struct StringNode
	{
		char* data = nullptr;

		void allocateData(const char* newData);
	};

	StringNode* nodes = nullptr;
	int size = 0;
	int capacity = 0;

	
	void copyFrom(const WordSet& other);
	void moveFrom(WordSet&& other);
	void free();

	int findWord(const char* word, bool& isFound) const;
	void resize(int newCapacity);

	void addString(const char* word, int idx);
	void removeString(const char* word, int idx);

public:

	WordSet();
	WordSet(const WordSet& other);
	WordSet& operator=(const WordSet& other);
	WordSet (WordSet&& other) noexcept;
	WordSet& operator=(WordSet&& other) noexcept;
	~WordSet() noexcept;

	WordSet& operator+=(const WordSet& other);
	WordSet& operator-=(const WordSet& other);
	
	bool operator[](const char* word) const;

	WordSet& operator*=(const char* word);
	WordSet& operator/=(const char* word);

	friend std::ostream& operator<<(std::ostream& os, const WordSet& obj);
	friend std::istream& operator>>(std::istream& is, WordSet& obj);
};

WordSet operator + (const WordSet& lhs, const WordSet& rhs);
WordSet operator - (const WordSet& lhs, const WordSet& rhs);
