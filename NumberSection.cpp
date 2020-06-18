#include "NumberSection.h"
#include "Number.h"
#include "Cell.h"

NumberSection::NumberSection(int i, Number* n): id(i), number(n), num_cells(0), finished(false)
{}
    
int NumberSection::getNumCells()            {return num_cells;}

vector<Cell*> NumberSection::getCells()     {return cells;}

int NumberSection::getId()                  {return id;}

void NumberSection::addCell(Cell* c)
{
    cells.push_back(c);
    num_cells++;
}

void NumberSection::removeCell(Cell* c)
{
    for(int i = 0; i < cells.size(); i++)
    {
        Cell* cell = cells[i];
        if(cell->getCol()->getId() == c->getCol()->getId() && cell->getRow()->getId() == c->getRow()->getId())
        {
            cells.erase(cells.begin() + i);
            num_cells--;
            if(num_cells == 1)
            {
                cells.at(0)->confirmNumber(number->getValue());
            }
            else if(num_cells == 0)
                finish();
            return;
        }
    }
}

void NumberSection::finish()
{
    cells.clear();
    num_cells=0;
    finished = true;
}