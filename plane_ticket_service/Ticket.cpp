#include <iostream>
#include <iomanip>
#include <fstream>
#include <ctime>
#include <string>
using namespace std;

#include "Ticket.h"

Ticket::Ticket(const string& first, const string& last, const int& d, const int& m, const int& y)
{
	setFirstName(first);
	setLastName(last);
	setBirthdate(d, m, y);
}

Ticket::~Ticket() {}

string Ticket::check_str(const string& s)
{
	string temp = "";
	return s.length() < 25 ? temp + s : temp.append(s, 0, 25);
}

void Ticket::setFirstName(const string& s)
{
	firstName = check_str(s);
}

string Ticket::getFirstName()const
{
	return firstName;
}

void Ticket::setLastName(const string & s)
{
	lastName = check_str(s);
}

string Ticket::getLastName()const
{
	return lastName;
}

void Ticket::getDateTime()const
{
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	int year = 1900 + ltm.tm_year;
	int month = 1 + ltm.tm_mon;
	int day = ltm.tm_mday;
	int hour = ltm.tm_hour;
	int min = ltm.tm_min;
	int sec = ltm.tm_sec;
	cout << "Date: " << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << year << "\t\t";
	cout << "Time: " << setfill('0') << setw(2) << hour << ":" << setw(2) << min << ":" << setw(2) << sec << endl;
}

void Ticket::setBirthdate(int d, int m, int y)
{
	if (m > 0 && m <= 12)
		month = m;
	else
	{
		month = 1; // invalid month set to 1
		cout << "Invalid month (" << m << ") set to 1.\n";
	}

	year = checkYear(y);
	day = checkDay(d);
}

void Ticket::getBirthdate() const
{
	cout << setfill('0') << setw(2) << day << "/" << setw(2) << month << "/" << year << endl;
}

// check day and 29 february
int Ticket::checkDay(int day)const
{
	static const int daysPerMonth[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (day > 0 && day <= daysPerMonth[month])
		return day;
	if (month == 2 && day == 29 && (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)))
		return day;
	cout << "Invalid day (" << day << ") set to 1.\n";
	return 1;
}

int Ticket::checkYear(int year)const
{
	int current_year;
	time_t now = time(0);
	tm ltm;
	localtime_s(&ltm, &now);
	current_year = 1900 + ltm.tm_year;
	if (year < 1900 || year > current_year)
		year = 1900;
	return year;
}




















