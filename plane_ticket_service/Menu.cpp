#include <iostream>
#include <fstream>
using std::cout;
using std::endl;
using std::fstream;

#include "Menu.h"

void Menu::logo()
{
	cout << "=====================================================================================================\n";
	cout << "                                       PLANE TICKET SERVICE\n";
	cout << "=====================================================================================================\n";
	cout << endl;
}

void Menu::main_menu()const
{
	cout << "Main menu of service\n";
	cout << "Enter 1 to buy Business Class ticket.\n";
	cout << "Enter 2 to buy Econom Class ticket.\n";
	cout << "Enter 3 to exit.\n";
	cout << "Your choice: ";
}

void Menu::menu_vacant_seat(string ticket_class)const
{
	fstream f;
	f.open("tickets.txt", fstream::in);

	if (!f.is_open())
	{
		cout << "Error!\nFile is damaged or not exist.\n";
	}
	else
	{
		place vacant = VACANT;

		int seat;
		cout << "================VACANT SEATS===============\n";
		if (ticket_class == "business")
		{
			for (int i = 2; i < 11; i+=2)
			{
				f.seekp(i);
				f >> seat;
				if (seat == VACANT)
					cout << "Seat " << i/2 << ":                 vacant\n";
				else
					cout << "Seat " << i/2 << ":                 busy\n";
			}
			f.close();
		}

		if (ticket_class == "econom")
		{
			for (int i = 12; i < 21; i+=2)
			{
				f.seekp(i);
				f >> seat;
				if (seat == VACANT)
					cout << "Seat " << i/2 << ":                 vacant\n";
				else
					cout << "Seat " << i/2 << ":                 busy\n";
			}
			f.close();
		}
		cout << "===========================================\n";
	}
}

int Menu::check_input_choice()const
{
	int choice;
	while (scanf_s("%d", &choice) == 0 || (choice < 1 || choice > 3))
	{
		cout << "Wrong input! Enter an integer 1 - 3." << endl;
		cout << "Your choice: ";
		getchar();
	}
	return choice;
}

int Menu::check_input_seat_business()const
{
	int choice;
	while (scanf_s("%d", &choice) == 0 || (choice < 1 || choice > 5))
	{
		cout << "Wrong input! Enter an integer 1 - 5." << endl;
		cout << "Your choice: ";
		getchar();
	}
	return choice;
}

int Menu::check_input_seat_econom()const
{
	int choice;
	while (scanf_s("%d", &choice) == 0 || (choice < 6 || choice > 10))
	{
		cout << "Wrong input! Enter an integer 6 - 10." << endl;
		cout << "Your choice: ";
		getchar();
	}
	return choice;
}

bool Menu::checkFullFill(string class_ticket) const
{
	if (class_ticket == "business")
	{
		int check_fill_seats = 0;
		fstream f;
		f.open("tickets.txt", fstream::in);

		if (!f.is_open())
		{
			cout << "Error!\nFile is damaged or not exist.\n";
			return false;
		}
		else
		{
			int seat;
			place vacant = BUSY;
			for (int i = 2; i < 11; i+=2)
			{
				f.seekp(i);
				f >> seat;
				if (seat == BUSY)
					++check_fill_seats;
			}

			if (check_fill_seats == 5)
			{
				f.close();
				return true;
			}
			else
			{
				f.close();
				return false;
			}
		}
	}

	if (class_ticket == "econom")
	{
		int check_fill_seats = 0;
		fstream f;
		f.open("tickets.txt", fstream::in);

		if (!f.is_open())
		{
			cout << "Error!\nFile is damaged or not exist.\n";
			return false;
		}
		else
		{
			int seat;
			place vacant = BUSY;
			for (int i = 12; i < 21; i+=2)
			{
				f.seekp(i);
				f >> seat;
				if (seat == BUSY)
					++check_fill_seats;
			}

			if (check_fill_seats == 5)
			{
				f.close();
				return true;
			}
			else
			{
				f.close();
				return false;
			}
		}
	}
}

bool Menu::is_Busy(int choice)
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
		int seat;
		place vacant = BUSY;

		f.seekp(choice * 2);
		f >> seat;

		if (seat == BUSY)
		{
			f.close();
			return true;
		}
		else
		{
			f.close();
			return false;
		}
	}
}

void Menu::fullfilled()const
{
	cout << endl;
	cout << "****************************************\n";
	cout << "********** ALL SEATS ARE SOLD! *********\n";
	cout << "****************************************\n";
	cout << endl;
}

int Menu::check_alternative_choice()const
{
	int choice;
	while (scanf_s("%d", &choice) == 0 || (choice < 1 || choice > 2))
	{
		cout << "Wrong input! Enter an integer 1 - 2." << endl;
		cout << "Your choice: ";
		getchar();
	}
	return choice;
}

void Menu::nextFlight()const
{
	cout << "*******************************************\n";
	cout << "********** NEXT FLIGHT IN 3 HOURS *********\n";
	cout << "*******************************************\n";
	cout << endl;
}


