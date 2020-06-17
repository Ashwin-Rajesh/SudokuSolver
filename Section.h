#ifndef SECTION_H
#define SECTION_H

#include <array>
#include <vector>

using namespace std;

class Cell;
class Number;
typedef array<bool, 9> Confirmed;

class Section
{
private:
	int id;
	vector<Cell*> listOfCells;
public:
	Section(int i);
	
	int getId();

	void addCell(Cell* c);
	vector<Cell*> getCells();

	void confirmNumber(int n);
	Confirmed getConfirmed();
};

#endif // !SECTION_H