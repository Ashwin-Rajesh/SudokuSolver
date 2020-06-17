#include "Sudoku.h"

Sudoku::Sudoku()
{
	//DECLARATION
	for (int i = 0; i < 9; i++)
	{
		numberList.push_back(new Number(i + 1));
		horizontal.push_back(new RowCol(i));
		vertical.push_back(new RowCol(i));
		box.push_back(new Box(i));
	}
	numberList.push_back(new Number(0));

	//READ FROM FILE
	string line;
	ifstream file("C:\\Users\\surya\\source\\repos\\SudokuAlgorithm\\SudokuAlgorithm\\Sudoku.txt");
	if (file.is_open())
	{
		int i = 0;
		while (getline(file, line))
		{
			int x = i / 3;
			for (int j = 0; j < line.size(); j++)
			{
				int y = j / 3;

				horizontal.at(i)->addCell(new Cell(i, j, (x * 3) + y));
				vertical.at(j)->addCell(new Cell(i, j, (x * 3) + y));
				box.at(x * 3 + y)->addCell(horizontal.at(i)->getCells().at(j));

				if (line[j] == '0')
				{
					horizontal.at(i)->getCells().at(j)->setNumber(numberList.at(numberList.size() - 1));
					horizontal.at(i)->getCells().at(j)->setConfirm(false);
					
					vertical.at(j)->getCells().at(i)->setNumber(numberList.at(numberList.size() - 1));
					vertical.at(j)->getCells().at(i)->setConfirm(false);

					box.at(x * 3 + y)->addNumber(numberList.at(numberList.size() - 1));
					horizontal.at(i)->getCells().at(j)->setPossibilities(numberList);
				}

				else
				{
					horizontal.at(i)->getCells().at(j)->setNumber(numberList.at(((int)(line[j]) - 48) - 1));
					horizontal.at(i)->addNumber(numberList.at(((int)(line[j]) - 48) - 1));
					horizontal.at(i)->getCells().at(j)->setConfirm(true);

					vertical.at(j)->getCells().at(i)->setNumber(numberList.at(((int)(line[j]) - 48) - 1));
					vertical.at(j)->addNumber(numberList.at(((int)(line[j]) - 48) - 1));
					vertical.at(j)->getCells().at(i)->setConfirm(true);

					box.at(x * 3 + y)->addNumber(numberList.at(((int)(line[j]) - 48) - 1));
				}
			}
			i++;
		}
	}

	file.close();
	
	//POSSIBILITY
	/*for (auto h : horizontal)
	{
		for (auto n : h->getNumbers())
		{
			for (auto c : h->getCells())
			{
				if (!c->isConfirmed())
				{
					c->removePossibility(n);
				}
			}
		}
	}*/

	for (auto v : vertical)
	{
		for (auto n : v->getNumbers())
		{
			for (auto c : v->getCells())
			{
				if (!c->isConfirmed())
				{
					c->removePossibility(n);
				}
			}
		}
	}

	/*for (auto b : box)
	{
		for (auto n : b->getNumbers())
		{
			for (auto c : b->getCells())
			{
				if (!c->isConfirmed())
				{
					c->removePossibility(n);
				}
			}
		}
	}*/
	for (auto h : horizontal)
	{
		for (auto c : h->getCells())
		{
			cout << c->getNumber()->getValue()<<"  ";
		}
		cout << endl;
	}

	/*cout << horizontal.at(3)->getCells().at(0)->isConfirmed();

	for (auto v : vertical.at(0)->getNumbers())
	{
		cout << v->getValue() << "  ";
	}

	cout << endl;*/

	/*for (auto v : vertical.at(1)->getCells())
	{
		cout << v->getNumber()->getValue() << "()";
	}*/


	for (auto x : horizontal.at(0)->getCells().at(0)->getPossibilities())
	{
		cout << x->getValue()<<"  ";
	}
}