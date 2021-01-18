#include "pch.h"
#include <iostream>
using namespace std;

#include "TicTacToe.h"

int main()
{
	setlocale(LC_ALL, "Russian");
	Tictactoe game;
	game.menu();
	int choice;
	cin >> choice;

	while (choice < 0 || choice > 1)
	{
		cout << "WRONG number!!!" << endl;
		cout << "Your choice: ";
		cin >> choice;
	}
	while (choice != 0)
	{
		while(choice != 0)
		{
			game.printField();
			cout << "To move - enter coordinates x, y" << endl;
			int x, y;
			cout << "x: ";
			cin >> x;
			cout << "y: ";
			cin >> y;

			game.setCoordinatePlayer(x, y);
			game.printField();
			game.checkWinnerPlayer();
			if (game.getFlag() == 1)
			{
				cout << endl;
				cout << "*** Game over ***" << endl;
				break;
			}
			game.checkNoWin();
			if (game.getCheck() == 9)
			{
				cout << "Nobody wins!!!" << endl;
				break;
			}

			cout << "Computer move" << endl;
			game.setCoordinateComp();
			//game.printField();
			game.checkWinnerComp();
			if (game.getFlag() == 1)
			{
				cout << endl;
				cout << "*** Game over ***" << endl;
				break;
			}

			game.setCheck();
		}
		
		cout << "\n" << endl;
		cout << "Would you like to play one more time?\nYes - press 1\nNo - press 0" << endl;
		cout << "Your choice: ";
		cin >> choice;
		cout << endl;
		
		if (choice == 1)
		{
			game.setField();
			game.setFlag();
			game.setCheck();
		}
		else
			choice = 0;
	}
	
	cout << endl;
	cout << "ВЫ ВЫШЛИ ИЗ ИГРЫ." << endl;

	return 0;
}


