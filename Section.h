#ifndef SECTION_H
#define SECTION_H

#include "Cell.h"

class Section
{
private:
	vector<Cell*> listOfCells;
	vector<Number*> confirmedNumber;
public:
	Section();
	
	void addCell(Cell* c);
	vector<Cell*> getCells();

	void addNumber(Number* n);
	vector<Number*> getNumbers();
};

#endif // !SECTION_H