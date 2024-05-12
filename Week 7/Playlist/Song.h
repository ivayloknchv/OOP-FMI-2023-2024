#pragma once

class Song
{
private:

	static constexpr unsigned MAX_DURATION = 600;

	char* name = nullptr;
	char* genre = nullptr;
	unsigned duration = 0;
	Song* next = nullptr;

	void copyFrom(const Song& other);
	void moveFrom(Song&& other);
	void free();

public:

	Song() = default;
	Song(const Song& other);
	Song& operator= (const Song& other);
	Song(Song&& other) noexcept;
	Song& operator=(Song&& other) noexcept;
	~Song();

	Song(const char* name, const char* genre, unsigned duration, Song* next=nullptr);

	void setName(const char* name);
	void setGenre(const char* genre);
	void setDuration(unsigned duration);
	void setNextSong(Song* next);

	const char* getName() const;
	const char* getGenre() const;
	unsigned getDuration() const;
	Song* getNextSong() const;

	void printSong() const;
};

