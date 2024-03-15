#include <iostream>
#include <fstream>
#include <cstring>
#pragma warning (disable: 4996)

namespace Constants
{
	constexpr int MAX_TITLE = 20;
	constexpr int MAX_DESCRIPTION = 128;
	constexpr int MAX_TASKS = 5;
}

class Task
{
	char title[Constants::MAX_TITLE]{};
	char description[Constants::MAX_DESCRIPTION]{};
	int points=0;

	void readFromBinary(std::ifstream& ifs)
	{
		ifs.read(title, Constants::MAX_TITLE);
		ifs.read(description, Constants::MAX_DESCRIPTION);
		ifs.read((char*)&points, sizeof(points));
	}

	void writeToBinary(std::ofstream& ofs) const
	{
		ofs.write(title, Constants::MAX_TITLE);
		ofs.write(description, Constants::MAX_DESCRIPTION);
		ofs.write((const char*)&points, sizeof(points));
	}

public:

	Task(){}

	Task(const char* title, const char* description, int points)
	{
		setTitle(title);
		setDescription(description);
		setPoints(points);
	}

	void setTitle(const char* title)
	{
		if (!title)
		{
			return;
		}

		strcpy(this->title, title);
	}

	void setDescription(const char* description)
	{
		if (!description)
		{
			return;
		}

		strcpy(this->description, description);
	}

	void setPoints(int points)
	{
		if (points < 0)
		{
			points = 0;
		}

		this->points = points;
	}

	const char* getTitle() const
	{
		return title;
	}

	const char* getDescription() const
	{
		return description;
	}

	int getPoints() const
	{
		return points;
	}

	void readFromBinary(const char* fileName)
	{
		if (!fileName)
		{
			return;
		}

		std::ifstream ifs(fileName, std::ios::binary | std::ios::in);

		if (!ifs.is_open())
		{
			return;
		}

		readFromBinary(ifs);

		ifs.close();
	}

	void writeToBinary(const char* fileName) const
	{
		if (!fileName)
		{
			return;
		}

		std::ofstream ofs(fileName, std::ios::binary | std::ios::out);

		if (!ofs.is_open())
		{
			return;
		}

		writeToBinary(ofs);

		ofs.close();
	}
};

class Test
{
	Task tasks[Constants::MAX_TASKS]{};
	int numberOfTasks = 0;
	int minPoints = 0;

	void readFromBinary(std::ifstream& ifs)
	{
		ifs.read((char*)&numberOfTasks, sizeof(numberOfTasks));
		ifs.read((char*)tasks, numberOfTasks*sizeof(Task));		
		ifs.read((char*)&minPoints, sizeof(minPoints));
	}

	void writeToBinary(std::ofstream& ofs) const
	{
		ofs.write((const char*)&numberOfTasks, sizeof(numberOfTasks));
		ofs.write((const char*)tasks, numberOfTasks * sizeof(Task));		
		ofs.write((const char*)&minPoints, sizeof(minPoints));
	}

public:
	Test() {}

	Test(const Task* tasks, int numberOfTasks, int minPoints)
	{
		setTasks(tasks, numberOfTasks);
		setNumberOfTasks(numberOfTasks);
		setMinPoints(minPoints);
	}

	void setTasks(const Task* tasks, int numberOfTasks)
	{
		if (!tasks)
		{
			return;
		}

		for (int i = 0; i < numberOfTasks; i++)
		{
			this->tasks[i] = tasks[i];
		}

	}

	void setNumberOfTasks(int numberOfTasks)
	{
		if (numberOfTasks < 0)
		{
			numberOfTasks = 0;
		}

		this->numberOfTasks = numberOfTasks;
	}

	void setMinPoints(int minPoints)
	{
		if (minPoints < 0)
		{
			minPoints = 0;
		}

		this->minPoints = minPoints;
	}

	Task* getTasks() const
	{
		return (Task*)tasks;
	}

	int getNumberOfTasks() const
	{
		return numberOfTasks;
	}

	int getMinPoints() const
	{
		return minPoints;
	}

	int getMaxPoints() const
	{
		int max = 0;

		for (int i = 0; i < numberOfTasks; i++)
		{
			max += tasks[i].getPoints();
		}

		return max;
	}

	void readFromBinary(const char* fileName)
	{
		if (!fileName)
		{
			return;
		}

		std::ifstream ifs(fileName, std::ios::binary | std::ios::in);

		if (!ifs.is_open())
		{
			return;
		}

		readFromBinary(ifs);

		ifs.close();
	}

	void writeToBinary(const char* fileName) const
	{
		if (!fileName)
		{
			return;
		}

		std::ofstream ofs(fileName, std::ios::binary | std::ios::out);

		if (!ofs.is_open())
		{
			return;
		}

		writeToBinary(ofs);

		ofs.close();
	}
};

int main()
{
	return 0;
}
