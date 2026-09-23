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
	constexpr Slot getMaxSlotCapacity() { return 30; };

	void swapSlots(Slot& x, Slot& y);
	[[nodiscard]] bool transferStock(Slot& source, Slot& destination, Slot amount);
	[[nodiscard]] bool transferStock(Slot* source, Slot* destination, Slot amount);
	[[nodiscard]] bool isSlotEmpty(const Slot* slot);
}

#endif