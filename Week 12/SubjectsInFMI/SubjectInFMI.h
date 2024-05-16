#pragma once

enum class Subjects
{
	DIS,
	GEOMETRY,
	DSTR2,
	UP,
	OOP,
	UNKNOWN
};

class SubjectInFMI
{
	Subjects _subject = Subjects::UNKNOWN;
	char* _lecturer = nullptr;
	char** _assistants = nullptr;
	size_t _assistantsCount = 0;
	size_t _pointsToPass = 0;

	void copyFrom(const SubjectInFMI& other);
	void moveFrom(SubjectInFMI&& other);
	void free();

	void setSubject(Subjects subject);
	void setLecturer(const char* lecturer);
	void setAssistants(const char* const* assistants, size_t assistantsCount);
	void setPointsToPass(size_t pointsToPass);


protected:

	unsigned getPoints() const;
	
public:

	SubjectInFMI() = default;
	SubjectInFMI(const SubjectInFMI& other);
	SubjectInFMI& operator=(const SubjectInFMI& other);
	SubjectInFMI(SubjectInFMI&& other) noexcept;
	SubjectInFMI& operator=(SubjectInFMI&& other) noexcept;
	virtual ~SubjectInFMI();

	SubjectInFMI(Subjects subject, const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass);

	virtual SubjectInFMI* clone() const = 0;

	virtual double gradeToPass() const = 0;

	virtual const char* getSubjectName() const = 0;

	unsigned getSubjectIdx() const;
};

