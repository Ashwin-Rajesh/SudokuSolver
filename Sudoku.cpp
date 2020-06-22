#include "Sudoku.h"

using namespace std;

vector<Number *> Cell::numbers;

Sudoku::Sudoku(int table[9][9])
{
	//DECLARATION
	for (int i = 0; i < 9; i++)
	{
		horizontal.push_back(new Section(i));
		vertical.push_back(new Section(i));
		box.push_back(new Section(i));
	}

	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
				Section* row = horizontal.at(i);
				Section* col = vertical.at(j);
				Section* b = box.at(int(i/3)*3 + int(j/3));
				
				cells[i][j] = new Cell((9*i)+j, row, col, b);

				row->addCell(cells[i][j]);
				col->addCell(cells[i][j]);
				b->addCell(cells[i][j]);
		}
	}

	for(int i = 0; i < 9; i++)
		numberList.push_back(new Number(i+1, cells));

	Cell::numbers = numberList;

	for(int i = 0; i < 9; i++)
		for (int j = 0; j < 9; j++)
			if(table[i][j] > 0 && table[i][j] < 10)
				cells[i][j]->confirmNumber(table[i][j]);

	cout << "Created sudoku" << endl;	
	print();
}

int Sudoku::spin()
{
	int count = getConfirmed();

	while(count != 81)
	{
		cout << "Processing indirect..." << endl;
		for(auto number:numberList)
				number->processIndirect();
			if(count == getConfirmed())
				branch();
			count = getConfirmed();
	}
	
	cout << "Finished" << endl;
	
	int table[9][9];
	for(int i = 0;i < 9; i++)
		for(int j = 0; j < 9; j++)
			table[i][j] = cells[i][j]->getNumber();

	throw GuessRightSignal(table);
	return 0;
}

Sudoku *Sudoku::branch()
{
	int min_pos = 10;
	Cell* min_cell = nullptr;
	int table[9][9];

	for(int i = 0; i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(!cells[i][j]->isConfirmed())
			{
				if(cells[i][j]->getNumPossibilities() < min_pos)
				{
					min_pos = cells[i][j]->getNumPossibilities();
					min_cell = cells[i][j];
				}
				table[i][j] = 0;
			}
			else
				table[i][j] = cells[i][j]->getNumber();
			
	
	Possibilities pos = min_cell->getPossibilities();
	vector<int> num_pos;

	for(int i = 0; i < 9; i++)
		if(pos.at(i))
			num_pos.push_back(i+1);
	
	bool sol_found = false;
	for(int i:num_pos)
	{
		cout << "trying out number " << i << " at " << min_cell->getId() << endl;
		table[min_cell->getRow()->getId()][min_cell->getCol()->getId()] = i;
		try{
			Sudoku sub(table);
			sub.spin();
		}
		catch(GuessWrongSignal g){
			continue;
		}
		sol_found = true;
		break;
	}
	if(!sol_found)
		throw 100;
	else
		throw 'a';
}

void Sudoku::print()
{
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
	}
}

int Sudoku::getConfirmed()
{
	int count = 0;
	for(int i = 0;i < 9; i++)
		for(int j = 0; j < 9; j++)
			if(cells[i][j]->isConfirmed())
				count++;
	return count;
}