#include "db/db.h"
#include <iostream>

int main()
{
	std::cout << slot::slot1 << ' ' << slot::slot2 << '\n';
	slot::swapSlots(slot::slot1, slot::slot2);
	std::cout << slot::slot1 << ' ' << slot::slot2 << '\n';

	return 0;
}