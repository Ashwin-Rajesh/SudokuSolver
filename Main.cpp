#include "Sudoku.h"

int main()
{
	int cells[9][9];

	string line;
	// ifstream file("C:\\Users\\surya\\source\\repos\\SudokuAlgorithm\\SudokuAlgorithm\\Examples\\Sudoku.txt");
	ifstream file("./Examples/Sudoku1.txt");
	if (file.is_open())
	{
		int i = 0;
		while (getline(file, line))
		{
			for (int j = 0; j < 9; j++)
				cells[i][j] = line[j] - '0';
			i++;
		}
		file.close();
	}
	else
	{
		cout << "File not found";
		return 1;
	}

	Sudoku game(cells);
	try{
		cout << game.spin() << endl;
	}
	catch(GuessRightSignal r)
	{
		for(int i = 0; i < 9; i++)
			{
				for(int j = 0; j < 9; j++)
					cout << r.table[i][j] << " ";
				cout << endl;
			}
		return 0;
	}
	game.print();
}