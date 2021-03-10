#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::fstream;

#include "Ticket.h"
#include "Econom.h"

Econom::Econom(const string& first, const string& last, const int& d, const int& m, const int& y)
    : Ticket(first, last, d, m, y)
{}

Econom::~Econom() {}

void Econom::setSeat(int choice)
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
            econom_seat = choice;
            f.close();
        }
        else
            f.close();
    }
}

int Econom::getSeat()const
{
    return econom_seat;
}

bool Econom::checkSeat(int choice)
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

string Econom::getTicketClass()const
{
    return this->ticket_class;
}

void Econom::printEconomClassTicket()const
{
    cout << "=================TICKET=================\n";
    cout << "Company: BM Limited co.\n";
    cout << "Passenger first name: " << Econom::getFirstName() << endl;
    cout << "Passenger last name: " << Econom::getLastName() << endl;
    cout << "Birthdate: ";
    Ticket::getBirthdate();
    cout << "Class: " << Econom::getTicketClass() << endl;
    cout << "Seat: " << Econom::getSeat() << endl;
    Ticket::getDateTime();
    cout << "=================TICKET=================\n";
}







