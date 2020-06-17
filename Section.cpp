#include "Section.h"
#include "Cell.h"

Section::Section(int i) : id(i)
{}

void Section::addCell(Cell* c)
{
	listOfCells.push_back(c);
}

vector<Cell*> Section::getCells()
{
	return listOfCells;
}

int Section::getId()
{
	return id;
}

void Section::confirmNumber(int n)
{
	for(auto c:listOfCells)
		c->removePossibility(n);
}