#include <string>
#ifndef ADV_RECTANGLE_H
#define ADV_RECTANGLE_H

class Rectangle
{
public:
	Rectangle(int, int, int, int, int, int, int, int);
	void setRectangle(int, int, int, int, int, int, int, int);
	void lengthRectangle();
	void widthRectangle();
	void perimetr();
	void area();
	void setCharacter();
	void drawArea();

private:
	int coordinate1;
	int coordinate2;
	int coordinate3;
	int coordinate4;

	int lenght1;
	int lenght2;
	int width1;
	int width2;
	char character;
};

#endif // !ADV_RECTANGLE_H

