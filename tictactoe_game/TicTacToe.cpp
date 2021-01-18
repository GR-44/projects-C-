#include "pch.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

#include "TicTacToe.h"

Tictactoe::Tictactoe()
{
	setField();
	setFlag();
	setCheck();
}

void Tictactoe::menu()
{
	cout << "******************************" << endl;
	cout << "\tGame Tictactoe" << endl;
	cout << "******************************" << endl;
	cout << "Start: press 1\nExit: press 0" << endl;
	cout << "Your choice: ";
}

void Tictactoe::setCoordinatePlayer(int x, int y)
{
	while (arr[x][y] == 1 || arr[x][y] == 2)
	{
		cout << "Enter correct coordinates x, y" << endl;
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
	}
	arr[x][y] = 1;

}

void Tictactoe::setCoordinateComp()
{
	srand(time(NULL));
	int x, y;
	x = rand() % 3;
	y = rand() % 3;

	while (arr[x][y] == 1 || arr[x][y] == 2)
	{
		x = rand() % 3;
		y = rand() % 3;
	}
	arr[x][y] = 2;
}

void Tictactoe::checkWinnerPlayer()
{
	if (arr[0][0] == 1 && arr[0][1] == 1 && arr[0][2] == 1)
	{
		cout << "Player wins!" << endl;
		flag = 1;
	}
	if (arr[1][0] == 1 && arr[1][1] == 1 && arr[1][2] == 1)
	{
		cout << "Player wins!" << endl;
		flag = 1;
	}
	if (arr[2][0] == 1 && arr[2][1] == 1 && arr[2][2] == 1)
	{
		cout << "Player wins!" << endl;
		flag = 1;
	}
	if (arr[0][0] == 1 && arr[1][1] == 1 && arr[2][2] == 1)
	{
		cout << "Player wins!" << endl;
		flag = 1;
	}
	if (arr[2][0] == 1 && arr[1][1] == 1 && arr[0][2] == 1)
	{
		cout << "Player wins!" << endl;
		flag = 1;
	}
	if (arr[0][0] == 1 && arr[1][0] == 1 && arr[2][0] == 1)
	{
		cout << "Player wins!" << endl;
		flag = 1;
	}
	if (arr[0][1] == 1 && arr[1][1] == 1 && arr[2][1] == 1)
	{
		cout << "Player wins!" << endl;
		flag = 1;
	}
	if (arr[0][2] == 1 && arr[1][2] == 1 && arr[2][2] == 1)
	{
		cout << "Player wins!" << endl;
		flag = 1;
	}
}

void Tictactoe::checkWinnerComp()
{
	if (arr[0][0] == 2 && arr[0][1] == 2 && arr[0][2] == 2)
	{
		cout << "Computer wins!" << endl;
		flag = 1;
	}
	if (arr[1][0] == 2 && arr[1][1] == 2 && arr[1][2] == 2)
	{
		cout << "Computer wins!" << endl;
		flag = 1;
	}
	if (arr[2][0] == 2 && arr[2][1] == 2 && arr[2][2] == 2)
	{
		cout << "Computer wins!" << endl;
		flag = 1;
	}
	if (arr[0][0] == 2 && arr[1][1] == 2 && arr[2][2] == 2)
	{
		cout << "Computer wins!" << endl;
		flag = 1;
	}
	if (arr[2][0] == 2 && arr[1][1] == 2 && arr[0][2] == 2)
	{
		cout << "Computer wins!" << endl;
		flag = 1;
	}
	if (arr[0][0] == 2 && arr[1][0] == 2 && arr[2][0] == 2)
	{
		cout << "Computer wins!" << endl;
		flag = 1;
	}
	if (arr[0][1] == 2 && arr[1][1] == 2 && arr[2][1] == 2)
	{
		cout << "Computer wins!" << endl;
		flag = 1;
	}
	if (arr[0][2] == 2 && arr[1][2] == 2 && arr[2][2] == 2)
	{
		cout << "Computer wins!" << endl;
		flag = 1;
	}
}
void Tictactoe::printField()
{
	int i, j;
	cout << "    0 1 2 (y)" << endl;
	cout << "_____________" << endl;
	for (i = 0; i < 3; i++)
	{
		cout << i << " | ";
		for (j = 0; j < 3; j++)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	cout << "(x)" << endl;
	cout << endl;
}

void Tictactoe::setFlag()
{
	flag = 0;
}

int Tictactoe::getFlag()
{
	return flag;
}

void Tictactoe::setCheck()
{
	check = 0;
}

int Tictactoe::getCheck()
{
	return check;
}

void Tictactoe::checkNoWin()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (arr[i][j] != 0)
			{
				++check;
			}
		}
	}
}

void Tictactoe::setField()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			arr[i][j] = 0;
		}
	}
}















