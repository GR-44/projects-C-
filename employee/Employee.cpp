#include "pch.h"
#include <iostream>
#include <string>
#include "Employee.h"
using namespace std;

Employee::Employee(string name, string surname, double salary)
{
	setFirstName(name);
	setLastName(surname);
	setMonthSalary(salary);
}

void Employee::setFirstName(string name)
{
	firstName = name;
}

string Employee::getFirstName()
{
	return firstName;
}

void Employee::setLastName(string surname)
{
	lastName = surname;
}

string Employee::getLastName()
{
	return lastName;
}

void Employee::setMonthSalary(double salary)
{
	if (salary >= 0)
	{
		monthsalary = salary;
	}
	else
	{
		monthsalary = 0;
		cout << "Wrong value of salary!\n" <<
			    "Salary: $" << getMonthSalary() << endl;
	}
}

double Employee::getMonthSalary()
{
	return monthsalary;
}




