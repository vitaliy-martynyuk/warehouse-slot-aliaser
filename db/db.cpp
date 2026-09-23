#include "db.h"

namespace slot
{
	Slot slot1{ 12 };
	Slot slot2{ 2 };
	Slot slot3{ 8 };
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
		if (destination + amount > getMaxSlotCapacity()) return false;
		source -= amount;
		destination += amount;

		return true;
	}

	bool transferStock(Slot* source, Slot* destination, Slot amount)
	{
		if (!source || !destination) return false;
		if (*source < amount) return false;
		if (*destination + amount > getMaxSlotCapacity()) return false;
		*source -= amount;
		*destination += amount;

		return true;
	}

	bool isSlotEmpty(const Slot* slot)
	{
		return !slot || !(*slot);
	}
}