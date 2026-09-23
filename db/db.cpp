#include "db.h"

namespace slot
{
	inline Slot slot1{ 12 };
	inline Slot slot2{ 2 };
	inline Slot slot3{ 0 };
	inline Slot slot4{ 0 };

	Slot& slot1Ref{ slot1 };
	Slot& slot2Ref{ slot2 };
	Slot& slot3Ref{ slot3 };
	Slot& slot4Ref{ slot4 };

	Slot* slot1Ptr{ &slot1 };
	Slot* slot2Ptr{ &slot2 };
	Slot* slot3Ptr{ &slot3 };
	Slot* slot4Ptr{ &slot4 };

	void swapSlots(Slot& x, Slot& y)
	{
		Slot tmp{ y };
		y = x;
		x = tmp;
	}
}