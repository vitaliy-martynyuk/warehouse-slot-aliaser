#ifndef IO_H
#define IO_H

#include "../db/db.h"

namespace io
{
	void printSlotsInfo(bool ok = true);
	void printSlotInfo(const slot::Slot& slot, bool isEmpty = false);
	void printSlotInfo(std::nullptr_t, bool isEmpty = false);
}

#endif