#include <iostream>
#include "Company.h"

int main()
{
 
    Company company;

    company.addWorker("John Doe", 30, 3000, 24);
    company.addWorker("Jane Smith", 25, 2500, 18);
    company.addTrainee("Alice Brown", 22, 1500, 60);
    company.addPaidTrainee("Bob White", 23, 2000, 12, 30, 85.0);
    company.addWorker("Chris Black", 40, 3500, 36);
    company.addTrainee("Diana Green", 21, 1600, 45);
    company.addPaidTrainee("Eve Blue", 24, 1800, 10, 20, 90.0);
    company.addWorker("Frank Yellow", 29, 2800, 22);
    company.addTrainee("Grace Red", 23, 1700, 50);
    company.addPaidTrainee("Hank Purple", 25, 1900, 14, 25, 88.0);

    std::cout << "Average salary: " << company.getAvgSalary() << std::endl;

    std::cout << company.twoSum(5000);
	return 0;
}