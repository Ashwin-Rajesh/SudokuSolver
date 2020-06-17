#include "Section.h"

Section::Section()
{

}

void Section::addCell(Cell* c)
{
	listOfCells.push_back(c);
}

vector<Cell*> Section::getCells()
{
	return listOfCells;
}

void Section::addNumber(Number* n)
{
	confirmedNumber.push_back(n);
}

vector<Number*> Section::getNumbers()
{
	return confirmedNumber;
}
