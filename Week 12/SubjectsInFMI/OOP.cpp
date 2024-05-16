#include "OOP.h"

OOP::OOP(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass, size_t bonusPoints)
	:SubjectInFMI(Subjects::OOP, lecturer, assistants, assistantsCount, pointsToPass), _bonusPoints(bonusPoints)
{
}

SubjectInFMI* OOP::clone() const
{
	return new OOP(*this);
}

double OOP::gradeToPass() const
{
	return 0.8 * (getPoints() + _bonusPoints);
}

const char* OOP::getSubjectName() const
{
	return "OOP";
}
