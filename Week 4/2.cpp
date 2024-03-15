#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable : 4996)

namespace Constants
{
	constexpr unsigned MAX_TITLE = 30;
	constexpr unsigned MAX_GAMES = 30;
	constexpr char SEPARATOR = ';';
}

class Game
{
	char title[Constants::MAX_TITLE];
	double price;
	bool isAvailable;


	void printAviability() const
	{
		switch (isAvailable)
		{
		case(false): std::cout << "Unavailable" << std::endl; break;
		case(true): std::cout << "Available" << std::endl; break;
		}
	}

public:

	Game()
	{
		title[0] = '\0';
		price = 0;
		isAvailable = false;
	}

	Game(const char* title, double price, bool isAvailable)
	{
		setTitle(title);
		setPrice(price);
		setAviability(isAvailable);
	}

	void setTitle(const char*title)
	{
		if (!title)
		{
			this->title[0] = '\0';

			return;
		}

		strcpy(this->title, title);
	}

	void setPrice(double price)
	{
		if (price < 0)
		{
			price = 0;
		}
		this->price = price;
	}

	void setAviability(bool isAvailable)
	{
		this->isAvailable = isAvailable;
	}

	const char* getTitle() const
	{
		return (const char*)title;
	}

	double getPrice() const
	{
		return price;
	}

	double getAviability() const
	{
		return isAvailable;
	}

	bool isFree() const
	{
		return (price == 0);
	}

	void print() const
	{
		std::cout << title << ' ' << price<<' ';
		printAviability();
	}
	
};

class GamePlatform
{
	Game games[Constants::MAX_GAMES];
	int gamesCount = 0;


	void removeAtIndex(int index)
	{
		for (int i = index; i < gamesCount - 1; i++)
		{
			games[i] = games[i + 1];
		}
		gamesCount--;
	}

	void writeToFile(std::ofstream& ofs) const
	{
		for (int i = 0; i < gamesCount; i++)
		{
			writeGame(ofs, games[i]);

			if (i != gamesCount - 1)
			{
				ofs << std::endl;
			}
		}
	}

	void writeGame(std::ofstream& ofs, const Game& game) const
	{
		ofs << game.getTitle() << Constants::SEPARATOR << game.getPrice() << Constants::SEPARATOR << game.getAviability();
	}

	void readFromFile(std::ifstream& ifs)
	{
		while (true)
		{
			readGameFromFile(ifs, games[gamesCount++]);

			if (ifs.eof())
			{
				break;
			}
		}
	}

	void readGameFromFile(std::ifstream& ifs, Game& game)
	{
		char name[Constants::MAX_TITLE];
		double price;
		bool isAvailable;

		ifs.getline(name, Constants::MAX_TITLE, Constants::SEPARATOR);
		ifs >> price;
		ifs.ignore();
		ifs >> isAvailable;
		ifs.ignore();

		game.setTitle(name);
		game.setPrice(price);
		game.setAviability(isAvailable);
	}

	void swap(Game& lhs, Game& rhs)
	{
		Game temp = lhs;
		lhs = rhs;
		rhs = temp;
	}

public:

	void addGame(const Game& game) 
	{
		if (gamesCount == Constants::MAX_GAMES)
		{
			std::cout << "The Platform is full! No more space for games!"<<std::endl;
			return;
		}
		games[gamesCount++] = game;
	}

	Game getCheapestGame() const
	{
		int min_idx = 0;

		for (int i = 1; i < gamesCount; i++)
		{
			if (games[min_idx].getPrice() > games[i].getPrice())
			{
				min_idx = i;
			}
		}

		return games[min_idx];
	}

	Game getMostExpensiveGame() const
	{
		int max_idx = 0;

		for (int i = 1; i < gamesCount; i++)
		{
			if (games[max_idx].getPrice() < games[i].getPrice())
			{
				max_idx = i;
			}
		}

		return games[max_idx];
	}

	void removeGame(const char* title)
	{
		for (int i = 0; i < gamesCount; i++)
		{
			if (strcmp(games[i].getTitle(), title) == 0)
			{
				removeAtIndex(i);
			}
		}
	}

	void printAvaiableGames() const
	{
		for (int i = 0; i < gamesCount; i++)
		{
			if (games[i].getAviability())
			{
				games[i].print();
			}
		}
	}

	void printAllGames() const
	{
		for (int i = 0; i < gamesCount; i++)
		{		
				games[i].print();
		}
	}

	void writeToFile(const char* fileName) const
	{
		if (!fileName)
		{
			return;
		}
		std::ofstream ofs(fileName, std::ios::out);

		if (!ofs.is_open())
		{
			return;
		}

		writeToFile(ofs);

		ofs.close();
	}
	
	void readFromFile(const char* fileName) 
	{
		if (!fileName)
		{
			return;
		}

		std::ifstream ifs(fileName, std::ios::in);

		if (!ifs.is_open())
		{
			return;
		}

		readFromFile(ifs);
		ifs.close();
	}

	void sortByCriteria(bool(*criteria)(const Game&, const Game&))
	{
		int min_idx = 0;

		for (int i = 0; i < gamesCount-1; i++)
		{
			min_idx = i;

			for (int j = i + 1; j < gamesCount; j++)
			{
				if (criteria(games[min_idx], games[j]))
				{
					min_idx = j;
				}
			}

			if (min_idx != i)
			{
				swap(games[min_idx], games[i]);
			}
		}
	}
};

int main()
{
	 Game g1("God of War", 99.99, true);
	 Game g2("GTA VI", 127.98, false);
	 Game g3("Call of Duty", 73.98, true);

	 GamePlatform gp;

	 gp.addGame(g1);
	 gp.addGame(g2);
	 gp.addGame(g3);

	 gp.sortByCriteria([](const Game& lhs, const Game& rhs) -> bool {return strcmp(lhs.getTitle(), rhs.getTitle())>0; });

	 gp.writeToFile("games.txt");

	return 0;
}
