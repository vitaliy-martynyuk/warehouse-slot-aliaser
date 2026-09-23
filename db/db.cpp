#include "db.h"
#include <iostream>

namespace slot
{
	Slot slot1{ 12 };
	Slot slot2{ 2 };
	Slot slot3{ 24 };
	Slot slot4{ 16 };

	void swapSlots(Slot& x, Slot& y)
	{
		Slot tmp{ y };
		y = x;
		x = tmp;
	}

	bool transferStock(Slot& source, Slot& destination, Slot amount)
	{
		if (source < amount) return false;
		source -= amount;
		destination += amount;

		return true;
	}

	bool transferStock(Slot* source, Slot* destination, Slot amount)
	{
		if (*source < amount) return false;
		*source -= amount;
		*destination += amount;

		return true;
	}

	void printSlotsInfo(bool ok)
	{
		using std::cout;

		cout << "------------------------------\n";
		if (!ok) cout << ">>Previous operation falied!<<\n------------------------------\n";
		cout << "Slot 1: " << slot1 << '\n';
		cout << "Slot 2: " << slot2 << '\n';
		cout << "Slot 3: " << slot3 << '\n';
		cout << "Slot 4: " << slot4 << '\n';
		cout << "------------------------------\n\n";
	}
}