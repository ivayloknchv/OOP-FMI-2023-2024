#include <iostream>

const int MAX_NAME_SIZE = 16;
const int MAX_ARR_SIZE = 20;
enum class Major {
	I,
	IS,
	CS,
	SE,
	DA,
	MA,
	AM,
	ST,
	MI
};

struct Student {
	char str[MAX_NAME_SIZE];
	int FN;
	Major major;
};

struct Course {
	Student students[MAX_ARR_SIZE] = {};
	int courseCount;
};

int getMajorCount(const Course& myCourse, const Major& major, Student* myStudents)
{
	if (!myStudents)
	{
		return -1;
	}

	int counter = 0;
	for (int i = 0; i < myCourse.courseCount; i++)
	{
		if (myCourse.students[i].major == major)
		{
			myStudents[counter] = myCourse.students[i];
			counter++;
		}
	}

	return counter;
}

int main()
{
	Student std1 = { "std1", 123123, Major::SE };
	Student std2 = { "std2", 321321, Major::MI };
	Student students[2] = { std1, std2 };
	Course course;
	course.students[0] = std1;
	course.students[1] = std2;
	course.courseCount = 2;
	Student myStudents[MAX_ARR_SIZE]{};

	int majorCounter = getMajorCount(course, Major::SE, myStudents);
	std::cout << majorCounter;
	return 0;
}