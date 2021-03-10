#include <iostream>
#include <string>
using namespace std;

#include "Ticket.h"
#include "Business.h"
#include "Econom.h"
#include "Menu.h"

int main()
{
    Menu m;
    m.logo();
    m.main_menu();

    bool flag;
    int choice = m.check_input_choice();
    
    while (choice != 3)
    {
        switch (choice)
        {
            case 1:
            {
                flag = true;
                system("cls");
                if (!m.checkFullFill("business"))
                    m.menu_vacant_seat("business");
                else
                {
                    m.fullfilled();
                    cout << "Would you like to buy Econom Class ticket?\n";
                    cout << "Enter 1 to buy or 2 to exit.\n";
                    cout << "Your choice: ";
                    int alternative = m.check_alternative_choice();
                    if (alternative == 1)
                    {
                        choice = 2;
                        flag = false;
                        break;
                    }
                    else
                    {
                        system("cls");
                        m.nextFlight();
                        break;
                    }
                }

                string first, last;
                int day, month, year;
                cout << "Enter your first name: ";
                cin >> first;
                cout << "Enter your last name: ";
                cin >> last;
                cout << "Enter your birthdate(format: dd/mm/yyyy): ";
                scanf_s("%d%*c%d%*c%d", &day, &month, &year);

                Business b(first, last, day, month, year);
                cout << "Choose your seat: ";
                int seat; 
                while (true)
                {
                    seat = m.check_input_seat_business();
                    if (!m.is_Busy(seat))
                        break;
                    else
                    {
                        cout << "This seat is already busy!\n";
                        cout << "Please, choose another seat: ";
                    }
                }
                b.setSeat(seat);

                system("cls");
                b.printBusinessClassTicket();
                cout << endl;
                break;
            }

            case 2:
            {
                flag = true;
                system("cls");
                if (!m.checkFullFill("econom"))
                    m.menu_vacant_seat("econom");
                else
                {
                    m.fullfilled();
                    cout << "Would you like to buy First Class ticket?\n";
                    cout << "Enter 1 to buy or 2 to exit.\n";
                    cout << "Your choice: ";
                    int alternative = m.check_alternative_choice();
                    if (alternative == 1)
                    {
                        choice = 1;
                        flag = false;
                        break;
                    }
                    else
                    {
                        system("cls");
                        m.nextFlight();
                        break;
                    }
                }

                string first, last;
                int day, month, year;
                cout << "Enter your first name: ";
                cin >> first;
                cout << "Enter your last name: ";
                cin >> last;
                cout << "Enter your birthdate(format: dd/mm/yyyy): ";
                scanf_s("%d%*c%d%*c%d", &day, &month, &year);

                Econom e(first, last, day, month, year);
                cout << "Choose your seat: ";
                int seat;
                while (true)
                {
                    seat = m.check_input_seat_econom();
                    if (!m.is_Busy(seat))
                        break;
                    else
                    {
                        cout << "This seat is already busy!\n";
                        cout << "Please, choose another seat: ";
                    }
                }
                e.setSeat(seat);

                system("cls");
                e.printEconomClassTicket();
                cout << endl;
                break;
            }

            default:
                break;
            
        }

        if (flag)
        {
            m.main_menu();
            choice = m.check_input_choice();
        }
    }

    return 0;
}

