#include "pch.h"
#include <iostream>
using namespace std;

#include "ADV_Rectangle.h"

int main()
{
	setlocale(0, ".1251");
	Rectangle fig1(1, 1, 1, 12, 15, 12, 15, 1);

	cout << "Length: ";
	fig1.lengthRectangle();
	cout << "Width: ";
	fig1.widthRectangle();
	cout << "Perimetr: ";
	fig1.perimetr();
	cout << "Area: ";
	fig1.area();

	cout << endl;
	fig1.drawArea();

}
