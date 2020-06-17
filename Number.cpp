#include "Number.h"

Number::Number(int i)
{
	setValue(i);
}

void Number::setValue(int i)
{
	value = i;
}

int Number::getValue()
{
	return value;
}
