#include "Number.h"

Number::Number(int i, Cell* table[9][9]) : value(i)
{
	for(int i = 0; i < 9; i++)
	{
		row_locations[i] = new NumberSection(i, this);
		col_locations[i] = new NumberSection(i, this);
		box_locations[i] = new NumberSection(i, this);
	}

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			row_locations[i]->addCell(table[i][j]);
			col_locations[j]->addCell(table[i][j]);
			box_locations[int(i/3)*3 + int(j/3)]->addCell(table[i][j]);
		}
	}
}

void Number::removeCell(Cell* c)
{
	int rid = c->getRow()->getId();
	int cid = c->getCol()->getId();
	int bid = c->getBox()->getId();

	row_locations[rid]->removeCell(c);
	col_locations[cid]->removeCell(c);
	box_locations[bid]->removeCell(c);
}

int Number::getValue() const
{
	return value;
}