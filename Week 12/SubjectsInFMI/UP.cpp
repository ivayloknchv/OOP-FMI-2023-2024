#include "UP.h"

UP::UP(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass)
	:SubjectInFMI(Subjects::UP, lecturer, assistants, assistantsCount, pointsToPass)
{
}

SubjectInFMI* UP::clone() const
{
	return new UP(*this);
}

double UP::gradeToPass() const
{
	return 0.5*getPoints();
}

const char* UP::getSubjectName() const
{
	return "UP";
}
