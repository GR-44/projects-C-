#include "pch.h"
#include <iostream>
#include <string>
#include"Employee.h"
using namespace std;	

int main()
{
	Employee employee_1("John", "Dow", 2700.50*1.1);
	Employee employee_2("Samantha", "Black", 3400*1.1);

	cout << "Employee: " << employee_1.getFirstName() << " " << employee_1.getLastName()
		 << "\nSalary: $" << employee_1.getMonthSalary() << endl;

	puts("");
	cout << "Employee: " << employee_2.getFirstName() << " " << employee_2.getLastName()
		 << "\nSalary: $" << employee_2.getMonthSalary() << endl;

	puts("");
	puts("Employee 2:");
	printf("Salary: $%.2lf",employee_2.getMonthSalary());
	puts("\n");
}


