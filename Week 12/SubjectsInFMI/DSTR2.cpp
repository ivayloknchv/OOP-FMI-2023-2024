#include "DSTR2.h"

DSTR2::DSTR2(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass)
	:SubjectInFMI(Subjects::DSTR2, lecturer, assistants, assistantsCount, pointsToPass)
{
}

SubjectInFMI* DSTR2::clone() const
{
	return new DSTR2(*this);
}

double DSTR2::gradeToPass() const
{
	return 0.6*getPoints();
}

const char* DSTR2::getSubjectName() const
{
	return "DSTR2";
}
