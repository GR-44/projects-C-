#pragma once
#include <string>
using std::string;

class Menu
{
public:

	enum place { VACANT, BUSY };
	
	void logo();
	void print_ticket()const;
	void main_menu()const;
	void menu_vacant_seat(string)const;
	int check_input_choice()const;
	int check_input_seat_business()const;
	int check_input_seat_econom()const;
	bool is_Busy(int);
	bool checkFullFill(string) const;
	void fullfilled()const;
	int check_alternative_choice()const;
	void nextFlight()const;
};


