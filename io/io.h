#ifndef IO_H
#define IO_H

#include "../db/db.h"

namespace io
{
	void printSlotsInfo(bool ok = true);
	void printSlotInfo(slot::Slot slot, bool isEmpty = false);
}

#endif