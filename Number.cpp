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

void Number::confirmCell(Cell *c)
{
	int rid = c->getRow()->getId();
	int cid = c->getCol()->getId();
	int bid = c->getBox()->getId();

	row_locations[rid]->finish();
	col_locations[cid]->finish();
	box_locations[bid]->finish();
}

void Number::processIndirect()
{
	int rid = -1;
	int cid = -1;
	int bid = -1;

	for(auto row:row_locations)
	{
		bid = -1;
		for(auto c:row->getCells())
		{
			if(bid == -1)
				bid = c->getBox()->getId();

			if(bid != c->getBox()->getId())
			{
				bid = -2;
				break;
			}
		}
		if(bid > 0)
		{
			NumberSection* box = box_locations[bid];
			for(auto c:box->getCells())
				if(c->getRow()->getId() != row->getId())
					c->removePossibility(value);
		}
	}

	
	for(auto col:col_locations)
	{
		bid = -1;
		for(auto c:col->getCells())
		{
			if(bid == -1)
				bid = c->getBox()->getId();

			if(bid != c->getBox()->getId())
			{
				bid = -2;
				break;
			}
		}
		if(bid > 0)
		{
			NumberSection* box = box_locations[bid];
			for(auto c:box->getCells())
				if(c->getCol()->getId() != col->getId())
					c->removePossibility(value);
		}
	}

	
	for(auto box:box_locations)
	{
		rid = -1;
		cid = -1;
		for(auto c:box->getCells())
		{
			if(rid == -1)
				rid = c->getRow()->getId();
			if(cid == -1)
				cid = c->getCol()->getId();
			
			if(rid != c->getRow()->getId())
				rid = -2;
			if(cid != c->getCol()->getId())
				cid = -2;	
		}
		if(rid > 0)
		{
			NumberSection* row = row_locations[rid];
			for(auto c:row->getCells())
				if(c->getBox()->getId() != box->getId())
					c->removePossibility(value);
		}
	}
}

int Number::getValue() const
{
	return value;
}