#pragma once
#include <string>
using std::string;

#include "Ticket.h"

class Business : public Ticket
{
public:
	Business(const string& first, const string& last, const int& d, const int& m, const int& y);
	~Business();

	void setSeat(int);
	int getSeat()const;
	string getTicketClass()const;
	void printBusinessClassTicket()const;

private:
	int business_seat;
	bool checkSeat(int);
	string ticket_class = "business";
};

