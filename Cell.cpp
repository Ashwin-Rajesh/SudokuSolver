#include "Cell.h"
#include "Number.h"

Cell::Cell(int i, RowCol* r, RowCol *c, Box* b):id(i),num(0),row(r),col(c),box(b), pos({1,1,1,1,1,1,1,1,1}), numPossibilities(9), confirm(false)
{}

int Cell::getId()						{return id;}

int Cell::getNumber()					{return num;}

RowCol* Cell::getRow()					{return row;}

RowCol* Cell::getCol()					{return col;}

Possibilities Cell::getPossibilities()	{return pos;}

int Cell::getNumPossibilities()			{return numPossibilities;}

Box* Cell::getBox()						{return box;}

void Cell::removePossibility(int n)
{
	if(confirm)
		return;

	if(n > 0 && n < 10)
		if(pos.at(n - 1))
		{
			pos.at(n - 1) = false;
			numPossibilities--;
			numbers.at(n - 1)->removeCell(this);
		}
	else
		return;

	if(numPossibilities == 1)
	{
		for(int i = 0; i < 9; i++)
			if(pos.at(i))
				confirmNumber(i + 1);
	}
}

void Cell::confirmNumber(int n)
{
	pos = {0,0,0,0,0,0,0,0,0};
	numPossibilities = 1;
	confirm = true;
	num = n;
	numbers.at(n-1)->confirmCell(this);

	for(auto number:numbers)
		number->removeCell(this);

	row->confirmNumber(n);
	col->confirmNumber(n);
	box->confirmNumber(n);
}

bool Cell::isConfirmed()
{
	return confirm;
}