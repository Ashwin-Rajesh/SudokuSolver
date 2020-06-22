#ifndef SUDOKU_H
#define SUDOKU_H

#include "Section.h"
#include "Cell.h"
#include "Number.h"

struct GuessRightSignal{
	int table[9][9];

	GuessRightSignal(int t[9][9])
	{
		for(int i = 0;i < 9; i++)
			for(int j = 0; j < 9; j++)
				table[i][j] = t[i][j];
	}
};

class Sudoku
{
private:
	vector<Number*> numberList;
	vector<Section*> horizontal;
	vector<Section*> vertical;
	vector<Section*> box;
	Cell* cells[9][9];

public:
	Sudoku(int tabe[9][9]);
	void print();
	int getConfirmed();
	Sudoku *branch();
	int spin();
};

#endif // !SUDOKU_H