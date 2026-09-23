#include "io.h"
#include "../db/db.h"
#include <iostream>

namespace io
{
	using std::cout;

	void printSlotsInfo(bool ok)
	{
		cout << "------------------------------\n";
		if (!ok) cout << ">>Previous operation failed!<<\n------------------------------\n";
		cout << "Slot " << &slot::slot1 << ": " << slot::slot1 << '\n';
		cout << "Slot " << &slot::slot2 << ": " << slot::slot2 << '\n';
		cout << "Slot " << &slot::slot3 << ": " << slot::slot3 << '\n';
		cout << "Slot " << &slot::slot4 << ": " << slot::slot4 << '\n';
		cout << "------------------------------\n\n";
	}

	void printSlotInfo(slot::Slot slot, bool isEmpty)
	{
		cout << "------------------------------\n";
		if (isEmpty) cout << "Slot " << &slot << ": empty\n";
		else cout << "Slot " << &slot << ": " << slot << '\n';

		cout << "------------------------------\n\n";
	}
}