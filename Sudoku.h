#ifndef SUDOKU_H
#define SUDOKU_H

#include "RowCol.h"
#include "Box.h"


class Sudoku
{
private:
	vector<Number*> numberList;
	vector<RowCol*> horizontal;
	vector<RowCol*> vertical;
	vector<Box*> box;

public:
	Sudoku();

};

#endif // !SUDOKU_H