#ifndef __NUMBERSECTION__
#define __NUMBERSECTION__

#include <vector>

using namespace std;

class Number;
class Cell;

class NumberSection
{
private:
    int id;
    Number* number;
    int num_cells;
    vector<Cell*> cells;
    bool finished;
public:
    NumberSection(int i, Number* n);

    void addCell(Cell* c);
    
    int getNumCells();
    vector<Cell*> getCells();

    void removeCell(Cell* c);
};

#endif