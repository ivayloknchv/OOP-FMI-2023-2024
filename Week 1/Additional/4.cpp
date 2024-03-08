#include <iostream>


namespace StudentNS
{
	enum class Course {
		First,
		Second,
		Third,
		Fourth,
		Unknown
	};

	struct Student {
		int fn;
		Course course;
		double average;
	};

	Student initStudent(const int& fn, const Course& course, const double& avg)
	{
		Student st;

		if (fn >= 10000 && fn <= 99999)
		{
			st.fn = fn;

			if (course == Course::First || course == Course::Second || course == Course::Third || course == Course::Fourth)
			{
				st.course = course;

				if (avg >= 2.00 && avg <= 6.00)
				{
					st.average = avg;

					return st;
				}	
			}
		}
		return { 0,Course::First,2.00 };
	}

	Course getCourse(const int& course)
	{
		switch (course)
		{
		case 1: 
			return Course::First; 
			break;
		case 2:
			return Course::Second;
			break;
		case 3:
			return Course::Third;
			break;
		case 4:
			return Course::Fourth;
			break;
		default: 
			return Course::Unknown;
		}
	}

	void printCourse(const Course& course)
	{
		switch (course)
		{
		case (Course::First):
			std::cout << "First course" << '\t';
			break;
		case (Course::Second):
			std::cout << "Second course" << '\t';
			break;
		case(Course::Third):
			std::cout << "Third course" << '\t';
			break;
		case (Course::Fourth):
			std::cout << "Fourth course" << '\t';
			break;
		}
	}

	void printStudent(const Student& st)
	{
		std::cout << st.fn << '\t';
		printCourse(st.course);
		std::cout << st.average << std::endl;
	}
}

namespace GroupNS 
{
	using namespace StudentNS;
	const int MAX_SIZE = 25;

	struct Group 
	{
		Student students[MAX_SIZE];
		double averageGroup;
		unsigned count;		
	};

	Group CreateGroup()
	{
		Group group;
		
		std::cin >> group.count;
		int fn = 0;
		int course = 0;
		double avg = 0.00;
		double total = 0.00;
		Course c;
		for (unsigned i = 0; i < group.count; i++)
		{
			std::cin >> fn;
			std::cin >> course;
			std::cin >> avg;
			total += avg;
			c = getCourse(course);

			group.students[i] = initStudent(fn, c, avg);
		}
		group.averageGroup = total / group.count;
		return group;
	}

	unsigned getScholarshipCount(const Group& group, const double& minGrade)
	{
		unsigned counter = 0;

		for (unsigned i = 0; i < group.count; i++)
		{
			if (group.students[i].average >= minGrade)
			{
				counter++;
			}
		}

		return counter;
	}

	void Swap(Student& a, Student& b)
	{
		Student temp = a;
		a = b;
		b = temp;
	}

	void selectionSort(Student* students, const unsigned& count)
	{
		if (!students)
		{
			return;
		}
		unsigned max_idx = 0;
		for (unsigned i = 0; i < count - 1; i++)
		{
			max_idx = i;
			for (unsigned j = i + 1; j < count; j++)
			{
				if (students[j].average > students[max_idx].average)
				{
					max_idx = j;
				}
			}
			if (max_idx != i)
			{
				Swap(students[i], students[max_idx]);
			}
		}
	}

	void printStudentsList(const Student* scholarshipStudents, const unsigned& count)
	{
		if (!scholarshipStudents)
		{
			return;
		}

		for (unsigned i= 0; i < count; i++)
		{
			printStudent(scholarshipStudents[i]);
		}
	}

	void showScholarshipStudents(const Group& group, const double& minGrade)
	{
		unsigned count = getScholarshipCount(group, minGrade);
		Student* scholarshipStudents = new Student[count];
		Student* copy = scholarshipStudents;

		for (unsigned i = 0; i < group.count; i++)
		{
			if (group.students[i].average>=minGrade)
			{
				*copy = group.students[i];
				copy++;
			}
		}

		selectionSort(scholarshipStudents, count);

		printStudentsList(scholarshipStudents, count);

		copy = nullptr;

		delete[] scholarshipStudents;
		
	}
}

int main()
{
	using namespace GroupNS;

	Group gr = CreateGroup();
	std::cout << gr.averageGroup;
	return 0;
}
