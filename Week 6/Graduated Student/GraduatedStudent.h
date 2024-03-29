#pragma once

class GraduatedStudent
{
	char* name=nullptr;
	int* grades = nullptr;
	int gradesCount = 0;
	char quote[30+1]{};

	void copyFrom(const GraduatedStudent& other);
	void free();

public:

	GraduatedStudent() = default;

	GraduatedStudent(const char* newName, const int* newGrades, int newGradesCount, const char* newQuote);

	GraduatedStudent(const GraduatedStudent& other);

	GraduatedStudent& operator=(const GraduatedStudent& other);

	void setName(const char* newName);

	void setGrades(const int* newGrades, int newGradesCount);

	void setQuote(const char* newQuote);

	const char* getName() const;

	const int* getGrades() const;

	const int getGradesCount() const;

	const char* getQuote() const;

	~GraduatedStudent();
};