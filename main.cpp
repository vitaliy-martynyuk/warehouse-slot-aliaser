#include "db/db.h"
#include <iostream>

int main()
{
	[[maybe_unused]] int x{ 0 };
	std::cout << *(slot::slot1Ptr) << ' ' << *(slot::slot2Ptr) << '\n';
	slot::swapSlots(slot::slot1Ref, slot::slot2Ref);
	std::cout << *(slot::slot1Ptr) << ' ' << *(slot::slot2Ptr) << '\n';

	return 0;
}