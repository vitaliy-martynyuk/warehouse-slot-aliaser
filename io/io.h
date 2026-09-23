#ifndef IO_H
#define IO_H

#include "../db/db.h"
#include <iostream>

namespace io
{
	void printSlotsInfo(bool ok = true)
	{
		using std::cout;

		cout << "------------------------------\n";
		if (!ok) cout << ">>Previous operation failed!<<\n------------------------------\n";
		cout << "Slot 1: " << slot::slot1 << '\n';
		cout << "Slot 2: " << slot::slot2 << '\n';
		cout << "Slot 3: " << slot::slot3 << '\n';
		cout << "Slot 4: " << slot::slot4 << '\n';
		cout << "------------------------------\n\n";
	}
}

#endif