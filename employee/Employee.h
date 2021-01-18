#include <string>
using namespace std;

class Employee
{
public:
	Employee(string, string, double);
	void   setFirstName(string);
	string getFirstName();
	void   setLastName(string);
	string getLastName();
	void   setMonthSalary(double);
	double getMonthSalary();

private:
	string firstName;
	string lastName;
	double monthsalary;
};

