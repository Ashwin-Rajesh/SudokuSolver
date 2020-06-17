#ifndef BOX_H
#define BOX_H

#include "Section.h"

class Box : public Section
{
private:
	int id;
	//vector<Cell*> listOfCells;

public:
	Box(int i);
	//void addCell(Cell* c);
	//vector<Cell*> getList();

};

#endif // !BOX_H