#include "DIS.h"

DIS::DIS(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass)
	:SubjectInFMI(Subjects::DIS, lecturer, assistants, assistantsCount, pointsToPass)
{
}

SubjectInFMI* DIS::clone() const
{
	return new DIS(*this);
}

double DIS::gradeToPass() const
{
	return 0.7 * getPoints();
}

const char* DIS::getSubjectName() const
{
	return "DIS";
}


