#ifndef CELL_H
#define CELL_H

#include "Number.h"

using namespace std;

class Cell
{
private:
	Number* num;
	int row, col;
	//vector<bool> possibleValues = { false,false,false,false,false,
	//								false,false,false,false };
	vector<Number*> possibilities;
	int boxNumber;
	bool confirm = false;


public:
	Cell(int r, int c, int box);

	void setNumber(Number* n);
	Number* getNumber();

	void setRow(int r);
	int getRow();

	void setCol(int c);
	int getCol();

	void setPossibilities(vector<Number*> n);
	void removePossibility(Number* n);
	vector<Number*> getPossibilities();

	void setBoxNumber(int box);
	int getBoxNumber();

	void setConfirm(bool b);
	bool isConfirmed();
};

#endif // !CELL_H