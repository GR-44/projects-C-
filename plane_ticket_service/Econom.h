#pragma once
#include <string>
using std::string;

#include "Ticket.h"

class Econom : public Ticket
{
public:
	Econom(const string& first, const string& last, const int& d, const int& m, const int& y);
	~Econom();

	void setSeat(int);
	int getSeat()const;
	string getTicketClass()const;
	void printEconomClassTicket()const;

private:
	int econom_seat;
	bool checkSeat(int);
	string ticket_class = "econom";
};

