#include "Cell.h"

Cell::Cell(int r, int c, int box)
{
	setRow(r);
	setCol(c);
	setBoxNumber(box);
}

void Cell::setNumber(Number* n)
{
	num = n;
}

Number* Cell::getNumber()
{
	return num;
}

void Cell::setRow(int r)
{
	row = r;
}

int Cell::getRow()
{
	return row;
}

void Cell::setCol(int c)
{
	col = c;
}

int Cell::getCol()
{
	return col;
}

void Cell::setPossibilities(vector<Number*> n)
{
	n.pop_back();
	possibilities = n;
}

void Cell::removePossibility(Number* n)
{
	vector<Number*>::iterator itr = find(possibilities.begin(), possibilities.end(), n);
	if (itr != possibilities.end())
	{
		possibilities.erase(itr);
	}
}

vector<Number*> Cell::getPossibilities()
{
	return possibilities;
}

void Cell::setBoxNumber(int box)
{
	boxNumber = box;
}

int Cell::getBoxNumber()
{
	return boxNumber;
}

void Cell::setConfirm(bool b)
{
	confirm = b;
}

bool Cell::isConfirmed()
{
	return confirm;
}
