#include <iostream>
#include <string>
#include <cctype>
using namespace std;

#include "Ticket.h"
#include "Business.h"
#include "Econom.h"
#include "Menu.h"

int main()
{
    Menu menu;
    menu.logo();
    menu.main_menu();

    bool flag = true;
    int choice = menu.check_input_choice();
    
    while (choice != 3)
    {
        switch (choice)
        {
            case 1:
            {
                flag = true;
                system("cls");
                
                if (!menu.check_full_business())
                {
                    flag = false;
                    choice = 2;
                    break;
                }
                else
                    break;

                Business business = menu.input_data_business();

                system("cls");
                business.printBusinessClassTicket();
                cout << endl;
                break;
            }

            case 2:
            {
                flag = true;
                system("cls");
                
                if (!menu.check_full_econom())
                {
                    flag = false;
                    choice = 1;
                    break;
                }
                else
                    break;

                Econom econom = menu.input_data_econom();

                system("cls");
                econom.printEconomClassTicket();
                cout << endl;
                break;
            }

            default:
                break;
            
        }

        if (flag)
        {
            menu.main_menu();
            choice = menu.check_input_choice();
        }
    }

    return 0;
}

