#ifndef DB_H
#define DB_H

#include <cstdint>

namespace slot
{
	using Slot = std::uint_fast32_t;

	extern Slot slot1;
	extern Slot slot2;
	extern Slot slot3;
	extern Slot slot4;

	void swapSlots(Slot& x, Slot& y);
	void transferStockByRef(Slot& source, Slot& destination, Slot amount);
}

#endif