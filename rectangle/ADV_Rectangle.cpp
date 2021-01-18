#include "pch.h"
#include <iostream>
using namespace std;

#include "ADV_Rectangle.h"

Rectangle::Rectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	setRectangle(x1, y1, x2, y2, x3, y3, x4, y4);
}

void Rectangle::setRectangle(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4)
{
	coordinate1 = x1;
	coordinate2 = y2;
	coordinate3 = x3;
	coordinate4 = x4;
	lenght1 = x3 - x2;
	lenght2 = x4 - x1;
	width1 = y2 - y1;
	width2 = y3 - y4;

	if (lenght1 == lenght2 && lenght1 == width1 && lenght1 == width2)
	{
		cout << "The figure is not rectangle!\nThe figure is square!" << endl;
	}
	
	if (lenght1 != lenght2 && width1 != width2)
	{
		cout << "This figure is not a rectangle" << endl;
	}
}

void Rectangle::lengthRectangle()
{
	if (lenght1 == lenght2)
	{
		cout << lenght1 << endl;
	}
	else
	{
		cout << "Wrong perameters of figure" << endl;
		cout << "\tLenght1: " << lenght1 << endl
		     << "\tLenght2: " << lenght2 << endl;
	}
}

void Rectangle::widthRectangle()
{
	if (width1 == width2)
	{
		cout << width1 << endl;
	}
	else
	{
		cout << "Wrong perameters of figure" << endl;
		cout << "Wrong perameters of figure" << endl;
		cout << "\tWidth1: " << width1 << endl
			 << "\tWidth2: " << width2 << endl;
	}
}

void Rectangle::perimetr()
{
	if(lenght1 == lenght2 && width1 == width2)
	{
		cout << (lenght1 + lenght2 + width1 + width2) << endl;
	}
	else
	{
		cout << "Wrong perameters!" << endl;
	}
}

void Rectangle::area()
{
	if (lenght1 == lenght2 && width1 == width2)
	{
		cout << (lenght1 * width1) << endl;
	}
	else
	{
		cout << "Wrong perameters!" << endl;
	}
}

void Rectangle::setCharacter()
{
	character = '$';
}

void Rectangle::drawArea()
{
	int arr[20][20] = { 0 };

	for (int i = 0; i < 20; i++)
	{
		for (int j = 0; j < 20; j++)
		{
			if ((i >= coordinate1 && i <= coordinate2) && (j >= coordinate1 && j <= coordinate4))
			{
				cout << character << " ";
			}
			else
			{
				cout << "* ";
			}
		}
		puts("");
	}

}












