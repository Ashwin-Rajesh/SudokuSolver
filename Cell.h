#ifndef CELL_H
#define CELL_H

#include "RowCol.h"
#include "Box.h"

#include <array>

using namespace std;

typedef array<bool, 9> Possibilities;

class Number;

class Cell
{
private:
	int id;
	int num;
	RowCol* row;
	RowCol* col;
	Box* box;
	
	Possibilities pos;
	int numPossibilities;
	bool confirm;

public:
	static vector<Number *> numbers;

	Cell(int i, RowCol* r, RowCol* c, Box* b);

	int getId();
	int getNumber();
	RowCol* getRow();
	RowCol* getCol();
	Box* getBox();
	Possibilities getPossibilities();
	int getNumPossibilities();

	void removePossibility(int n);

	void confirmNumber(int n);
	bool isConfirmed();
};

#endif // !CELL_H