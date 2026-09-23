#include "db/db.h"
#include "io/io.h"

int main()
{
	io::printSlotsInfo();
	slot::swapSlots(slot::slot1, slot::slot2);
	io::printSlotsInfo();

	io::printSlotsInfo(slot::transferStock(slot::slot1, slot::slot2, 1));
	io::printSlotsInfo(slot::transferStock(slot::slot2, slot::slot1, 200));

	io::printSlotsInfo(slot::transferStock(&slot::slot4, &slot::slot3, 5));
	io::printSlotsInfo(slot::transferStock(&slot::slot4, &slot::slot1, 2));

	io::printSlotsInfo(slot::transferStock(nullptr, &slot::slot1, 5));

	io::printSlotInfo(slot::slot1, slot::isSlotEmpty(&slot::slot1));
	io::printSlotsInfo(slot::transferStock(&slot::slot1, &slot::slot2, 3));
	io::printSlotInfo(slot::slot1, slot::isSlotEmpty(&slot::slot1));

	return 0;
}