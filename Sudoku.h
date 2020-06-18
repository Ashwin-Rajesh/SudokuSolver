#ifndef SUDOKU_H
#define SUDOKU_H

#include "RowCol.h"
#include "Box.h"
#include "Cell.h"
#include "Number.h"

class Sudoku
{
private:
	vector<Number*> numberList;
	vector<RowCol*> horizontal;
	vector<RowCol*> vertical;
	vector<Box*> box;
	Cell* cells[9][9];

public:
	Sudoku();
	void print();
	int getConfirmed();
};

#endif // !SUDOKU_H