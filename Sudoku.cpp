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
				
				cells[i][j] = new Cell((9*i)+j, row, col, b);

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
	// ifstream file("C:\\Users\\surya\\source\\repos\\SudokuAlgorithm\\SudokuAlgorithm\\Examples\\Sudoku.txt");
	ifstream file("./Examples/Sudoku2.txt");
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
	else
	{
		cout << "File not found";
		return;
	}
	
	
	file.close();
	
	print();


	int count = getConfirmed();
	if(count != 81)
	{
		cout << "Processing indirect" << endl;
		while(true)
		{
			cout << "t" << count << endl;
			for(auto number:numberList)
				number->processIndirect();
			if(count == getConfirmed())
				break;
			count = getConfirmed();
		}
		print();
	}
	
	cout << "finished";
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