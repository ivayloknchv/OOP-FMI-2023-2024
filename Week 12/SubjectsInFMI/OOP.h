#pragma once
#include "SubjectInFMI.h"

class OOP : public SubjectInFMI
{
	size_t _bonusPoints = 0;

public:

	OOP(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass, size_t bonusPoints);
	SubjectInFMI* clone() const override;
	double gradeToPass() const override;
	const char* getSubjectName() const override;
};

