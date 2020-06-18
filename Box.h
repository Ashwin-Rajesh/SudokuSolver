#ifndef BOX_H
#define BOX_H

#include "Section.h"

class Box : public Section
{
public:
	Box(int i);

	void findIndirect();
};

#endif // !BOX_H