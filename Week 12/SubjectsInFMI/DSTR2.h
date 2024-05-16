#pragma once
#include "SubjectInFMI.h"

class DSTR2 : public SubjectInFMI
{

public:

	DSTR2(const char* lecturer, const char* const* assistants, size_t assistantsCount, size_t pointsToPass);
	SubjectInFMI* clone() const override;
	double gradeToPass() const override;
	const char* getSubjectName() const override;
};

