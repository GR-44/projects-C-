#pragma once
#include <string>
using std::string;

class Ticket
{
public:
	Ticket(const string& first, const string& last, const int& d, const int& m, const int& y);
	~Ticket();

	void setFirstName(const string&);
	string getFirstName()const;

	void setLastName(const string&);
	string getLastName()const;

	void getDateTime()const;
	enum place { VACANT, BUSY };

	void setBirthdate(int, int, int);
	void getBirthdate() const;

	virtual void setSeat(int) = 0;
	virtual int getSeat()const = 0;
	virtual string getTicketClass()const = 0;

private:
	string firstName;
	string lastName;
	string check_str(const string& s);
	int day;
	int month;
	int year;

	int checkDay(int)const;
	int checkYear(int)const;
};

