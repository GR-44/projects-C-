#ifndef TICTACTOE_H
#define TICTACTOE_H

class Tictactoe
{
public:
	Tictactoe();
	void menu();
	void setField();
	void setCoordinatePlayer(int, int);
	void setCoordinateComp();
	void setFlag();
	void setCheck();
	int getCheck();
	int getFlag();
	void checkWinnerPlayer();
	void checkWinnerComp();
	void printField();
	void checkNoWin();


private:
	int arr[3][3];
	int x_coordinate;
	int y_coordinate;
	int flag;
	int check;
};



#endif // !TICTACTOE_H

