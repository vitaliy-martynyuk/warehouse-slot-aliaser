#include "db/db.h"
#include <iostream>

int main()
{
	slot::printSlotsInfo();
	slot::swapSlots(slot::slot1, slot::slot2);
	slot::printSlotsInfo();

	slot::printSlotsInfo(slot::transferStock(slot::slot1, slot::slot2, 1));
	slot::printSlotsInfo(slot::transferStock(slot::slot2, slot::slot1, 200));

	slot::printSlotsInfo(slot::transferStock(&slot::slot4, &slot::slot3, 5));
	slot::printSlotsInfo(slot::transferStock(&slot::slot4, &slot::slot1, 2));

	return 0;
}