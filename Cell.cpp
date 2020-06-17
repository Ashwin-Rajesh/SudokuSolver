#include "Cell.h"

Cell::Cell(RowCol* r, RowCol *c, Box* b):num(0),row(r),col(c),box(b), pos({1,1,1,1,1,1,1,1,1}), numPossibilities(9), confirm(false)
{}

int Cell::getNumber()				{return num;}

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

	row->confirmNumber(n);
	col->confirmNumber(n);
	box->confirmNumber(n);
}

bool Cell::isConfirmed()
{
	return confirm;
}