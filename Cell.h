#ifndef CELL_H
#define CELL_H

#include "Section.h"

#include <array>

using namespace std;

typedef array<bool, 9> Possibilities;

class Number;

struct GuessWrongSignal{
	int level;
};

class Cell
{
private:
	int id;
	int num;
	Section* row;
	Section* col;
	Section* box;
	
	Possibilities pos;
	int numPossibilities;
	bool confirm;

public:
	static vector<Number *> numbers;

	Cell(int i, Section* r, Section* c, Section* b);

	int getId();
	int getNumber();
	Section* getRow();
	Section* getCol();
	Section* getBox();
	Possibilities getPossibilities();
	int getNumPossibilities();

	void removePossibility(int n);

	void confirmNumber(int n);
	bool isConfirmed();
};

#endif // !CELL_H