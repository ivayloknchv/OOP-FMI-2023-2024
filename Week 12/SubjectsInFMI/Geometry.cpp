#include "Geometry.h"

Geometry::Geometry(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass)
	:SubjectInFMI(Subjects::GEOMETRY, lecturer, assistants, assistantsCount, pointsToPass)
{
}

SubjectInFMI* Geometry::clone() const
{
	return new Geometry(*this);
}

double Geometry::gradeToPass() const
{
	return 0.75*getPoints();
}

const char* Geometry::getSubjectName() const
{
	return "Geometry";
}
