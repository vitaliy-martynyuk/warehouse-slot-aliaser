#ifndef DB_H
#define DB_H

#include <cstdint>

namespace slot
{
	using Slot = std::uint_fast32_t;

	extern Slot& slot1Ref;
	extern Slot& slot2Ref;
	extern Slot& slot3Ref;
	extern Slot& slot4Ref;

	extern Slot* slot1Ptr;
	extern Slot* slot2Ptr;
	extern Slot* slot3Ptr;
	extern Slot* slot4Ptr;

	void swapSlots(Slot& x, Slot& y);
}

#endif