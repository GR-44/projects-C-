#include <iostream>
#include <fstream>
using namespace std;

#include "Menu.h"
#include "Business.h"

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

Business Menu::input_data_business()const
{
	Menu menu;
	string first, last;
	int day, month, year;
	cout << "Enter your first name: ";
	cin >> first;
	cout << "Enter your last name: ";
	cin >> last;
	cout << "Enter your birthdate(format: dd/mm/yyyy): ";
	scanf_s("%d%*c%d%*c%d", &day, &month, &year);

	Business business(first, last, day, month, year);
	cout << "Choose your seat: ";
	int seat;
	while (true)
	{
		seat = menu.check_input_seat_business();
		if (!menu.is_Busy(seat))
			break;
		else
		{
			cout << "This seat is already busy!\n";
			cout << "Please, choose another seat: ";
		}
	}
	business.setSeat(seat);
	return business;
}

Econom Menu::input_data_econom()const
{
	Menu menu;
	string first, last;
	int day, month, year;
	cout << "Enter your first name: ";
	cin >> first;
	cout << "Enter your last name: ";
	cin >> last;
	cout << "Enter your birthdate(format: dd/mm/yyyy): ";
	scanf_s("%d%*c%d%*c%d", &day, &month, &year);

	Econom econom(first, last, day, month, year);
	cout << "Choose your seat: ";
	int seat;
	while (true)
	{
		seat = menu.check_input_seat_econom();
		if (!menu.is_Busy(seat))
			break;
		else
		{
			cout << "This seat is already busy!\n";
			cout << "Please, choose another seat: ";
		}
	}
	econom.setSeat(seat);
	return econom;
}

bool Menu::check_full_business()const
{
	Menu menu;
	if (!menu.checkFullFill("business"))
		menu.menu_vacant_seat("business");
	else
	{
		menu.fullfilled_business();
		cout << "Would you like to buy Econom Class ticket?\n";
		cout << "Enter 1 to buy or 2 to exit.\n";
		cout << "Your choice: ";
		int alternative = menu.check_alternative_choice();
		if (alternative == 1)
			return false;
		else
		{
			system("cls");
			menu.nextFlight();
		}
	}
	return true;
}

bool Menu::check_full_econom()const
{
	Menu menu;
	if (!menu.checkFullFill("econom"))
		menu.menu_vacant_seat("econom");
	else
	{
		menu.fullfilled_econom();
		cout << "Would you like to buy First Class ticket?\n";
		cout << "Enter 1 to buy or 2 to exit.\n";
		cout << "Your choice: ";
		int alternative = menu.check_alternative_choice();
		if (alternative == 1)
			return false;
		else
		{
			system("cls");
			menu.nextFlight();
		}
	}
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
		
		if (ticket_class == "business")
		{
			cout << "================ VACANT SEATS BUSINESS ===============\n";
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
			cout << "================ VACANT SEATS ECONOM ===============\n";
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
}

bool Menu::is_Busy(int choice)const
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

void Menu::fullfilled_business()const
{
	cout << endl;
	cout << "*********************************************************\n";
	cout << "********** ALL BUSINESS CLASS TICKETS ARE SOLD! *********\n";
	cout << "*********************************************************\n";
	cout << endl;
}

void Menu::fullfilled_econom()const
{
	cout << endl;
	cout << "*******************************************************\n";
	cout << "********** ALL ECONOM CLASS TICKETS ARE SOLD! *********\n";
	cout << "*******************************************************\n";
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

