#pragma once
#include "SubjectInFMI.h"

class DIS : public SubjectInFMI
{
public:

	DIS(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass);
	SubjectInFMI* clone() const override;
	double gradeToPass() const override;
	const char* getSubjectName() const override;
};

