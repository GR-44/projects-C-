#pragma once
#include <string>
using std::string;

#include "Business.h";
#include "Econom.h";

class Menu
{
public:

	enum place { VACANT, BUSY };
	
	void logo();
	Business input_data_business()const;
	Econom input_data_econom()const;
	bool check_full_business()const;
	bool check_full_econom()const;
	void main_menu()const;
	void menu_vacant_seat(string)const;
	int check_input_choice()const;
	int check_input_seat_business()const;
	int check_input_seat_econom()const;
	bool is_Busy(int)const;
	bool checkFullFill(string) const;
	void fullfilled_business()const;
	void fullfilled_econom()const;
	int check_alternative_choice()const;
	void nextFlight()const;
};


