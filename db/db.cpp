#include "db.h"
#include <cassert>

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

	void transferStockByRef(Slot& source, Slot& destination, Slot amount)
	{
		assert(source >= amount && "Transfer stock error!");
		source -= amount;
		destination += amount;
	}
}