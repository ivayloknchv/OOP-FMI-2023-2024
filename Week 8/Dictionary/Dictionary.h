#pragma once

class Dictionary
{
private:

	struct Pair
	{
		char* key = nullptr;
		char* value = nullptr;

		void setKey(const char* key);
		void setValue(const char* value);
	};

	Pair* pairs = nullptr;
	int size = 0;
	int capacity = 0;

	void copyFrom(const Dictionary& other);
	void moveFrom(Dictionary&& other);
	void free();

	int findWord(const char* word, bool& isFound) const;
	void resize(int newCapacity);

	void addInternal(int idx, const char* word, const char* description);
	void removeInternal(int idx);

public:

	Dictionary();
	Dictionary(const Dictionary& other);
	Dictionary& operator=(const Dictionary& other);
	Dictionary(Dictionary&& other) noexcept;
	Dictionary& operator=(Dictionary&& other) noexcept;
	~Dictionary() noexcept;

	void add(const char* word, const char* description);
	void remove(const char* word);
	void print() const;

	const char* operator()(const char* word);
	Dictionary& operator+=(const Dictionary& other);
};

Dictionary operator+(const Dictionary& lhs, const Dictionary& rhs);


