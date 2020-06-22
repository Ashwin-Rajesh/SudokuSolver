#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

#include "NumberSection.h"
#include "Cell.h"

class Number
{
private:
	int value;
	NumberSection *row_locations[9];
	NumberSection *col_locations[9];
	NumberSection *box_locations[9];

public:
	Number(int i, Cell* table[9][9]);

	void removeCell(Cell* c);
	void confirmCell(Cell* c);
	void processIndirect();

	int getValue() const;
};

#endif // !CELL_H
