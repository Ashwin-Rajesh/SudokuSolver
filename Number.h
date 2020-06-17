#ifndef NUMBER_H
#define NUMBER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>

class Number
{
private:
	int value;

public:
	Number(int i);

	void setValue(int i);
	int getValue();

};

#endif // !CELL_H
