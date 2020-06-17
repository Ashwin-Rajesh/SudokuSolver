#include "Sudoku.h"

using namespace std;

vector<Number *> Cell::numbers;

Sudoku::Sudoku()
{
	//DECLARATION
	for (int i = 0; i < 9; i++)
	{
		horizontal.push_back(new RowCol(i));
		vertical.push_back(new RowCol(i));
		box.push_back(new Box(i));
	}

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
				RowCol* row = horizontal.at(i);
				RowCol* col = vertical.at(j);
				Box* b = box.at(int(i/3)*3 + int(j/3));
				
				cells[i][j] = new Cell(row, col, b);

				row->addCell(cells[i][j]);
				col->addCell(cells[i][j]);
				b->addCell(cells[i][j]);
		}
	}

	for(int i = 0; i < 9; i++)
		numberList.push_back(new Number(i+1, cells));

	Cell::numbers = numberList;

	// Read from file
	string line;
	ifstream file("./Sudoku.txt");
	if (file.is_open())
	{
		int i = 0;
		while (getline(file, line))
		{
			for (int j = 0; j < 9; j++)
			{	
				if (line[j] != '0')
				{
					cells[i][j]->confirmNumber(line[j] - '0');
				}
			}
			i++;
		}
	}

	file.close();
	
	cout << "Puzzle now" << endl;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			Cell* c = cells[i][j];
			if(c->isConfirmed()) 
				cout << " " << c->getNumber()<<" ";
			else
				cout << " _ ";
		}
		cout<<endl;
		for (int j = 0; j < 9; j++)
		{
			Cell* c = cells[i][j];
			cout << "(" << c->getNumPossibilities() << ")";
		}
		cout << endl << endl;
	}

	auto b = cells[2][4]->getPossibilities();

	for (int i = 0; i < 9; i++)
	{
		if(b.at(i))
			cout << i+1 << " ";
	}
}