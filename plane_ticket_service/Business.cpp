#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::fstream;

#include "Ticket.h"
#include "Business.h"

Business::Business(const string& first, const string& last, const int& d, const int& m, const int& y)
	: Ticket(first, last, d, m, y)
{}

Business::~Business() {}

void Business::setSeat(int choice)
{
    fstream f;
    f.open("tickets.txt", fstream::in | fstream::out);

    if (!f.is_open())
    {
        cout << "Error!\nFile is damaged or not exist.\n";
    }
    else
    {
        if (checkSeat(choice))
        {
            f.seekp(choice*2);
            f << 1;
            business_seat = choice;
            f.close();
        }
        else
        {
            f.close();
        }
            
    }
}

int Business::getSeat()const
{
	return business_seat;
}

bool Business::checkSeat(int choice)
{
    fstream f;
    f.open("tickets.txt", fstream::in);

    if (!f.is_open())
    {
        cout << "Error!\nFile is damaged or not exist.\n";
        return false;
    }
    else
    {
        place vacant = VACANT;

        int seat;
        f.seekp(choice*2);
        f >> seat;

        if (seat == VACANT)
        {
            return true;
            f.close();
        }
        else
        {
            return false;
            f.close();
        }
    }
}

string Business::getTicketClass()const
{
    return this->ticket_class;
}

void Business::printBusinessClassTicket() const
{
    cout << "=================TICKET=================\n";
    cout << "Company: BM Limited co.\n";
    cout << "Passenger first name: " << Business::getFirstName() << endl;
    cout << "Passenger last name: " << Business::getLastName() << endl;
    cout << "Birthdate: ";
    Ticket::getBirthdate();
    cout << "Class: " << Business::getTicketClass() << endl;
    cout << "Seat: " << Business::getSeat() << endl;
    Ticket::getDateTime();
    cout << "=================TICKET=================\n";
}





