#pragma once
#include "Trainee.h"
#include "Worker.h"

class PaidTrainee: public Worker, public Trainee
{
private:
	double _rating = 0;

public:
	
	PaidTrainee(const MyString& name, unsigned age, double salary, unsigned workingMonths, unsigned daysLeft, double rating);

	Employee* clone() const override;


};

