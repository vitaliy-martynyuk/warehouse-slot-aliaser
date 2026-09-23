# Warehouse Slot Aliaser

A small C++ console utility that manages a handful of warehouse storage
slots, each holding a stock count, and lets you swap slots, transfer stock
between them, and check whether a slot is empty. Pointers and references
are the actual mechanism, not incidental syntax.

Built as a learning project while working through
[learncpp.com](https://www.learncpp.com/), focused on consolidating
Chapter 12: lvalue references, pointers, `const` with both, null pointers,
and choosing pass-by-reference vs. pass-by-address on purpose. Chapter F
(`constexpr` functions proven with `static_assert`) is woven in as the
source of the slot capacity limit.

## What it does

- Stores four slots as individually named, shared global `Slot` variables
- `swapSlots` swaps two slots' contents through references
- `transferStock` moves stock between two slots. It's overloaded to take
  either references or pointers, returns whether the transfer happened,
  and refuses transfers that would underflow the source or push the
  destination over capacity
- The pointer overload safely rejects `nullptr` for either slot instead
  of dereferencing it
- `isSlotEmpty` takes a pointer-to-const and treats both "no slot at all"
  (`nullptr`) and "a real slot holding 0" as empty
- The capacity limit comes from a `constexpr` function, and a
  `static_assert` confirms it is evaluated at compile time

## Project structure

```
main.cpp                    // demonstrates each operation, including failure cases
db/
  db.h / db.cpp             // slots, swapSlots, transferStock overloads, isSlotEmpty,
                            //   getMaxSlotCapacity
  db_tests.cpp              // static_assert proof for the constexpr capacity
io/
  io.h / io.cpp             // printing all slots, a single slot, or a null slot
```

## Building

Requires a C++20-capable compiler.

```bash
g++ -std=c++20 -Wall -Wextra -Wconversion -Wshadow -Wsign-conversion -o app \
    main.cpp db/db.cpp db/db_tests.cpp io/io.cpp
```

Or open `Warehouse Slot Aliaser.slnx` in Visual Studio.

## Running

```bash
./app
```

Example output (slot labels are memory addresses and differ between runs):

```
------------------------------
Slot 0x55edc4cdb010: 12
Slot 0x55edc4cdb018: 2
Slot 0x55edc4cdb020: 8
Slot 0x55edc4cdb028: 16
------------------------------

------------------------------
>>Previous operation failed!<<
------------------------------
Slot 0x55edc4cdb010: 1
Slot 0x55edc4cdb018: 13
Slot 0x55edc4cdb020: 8
Slot 0x55edc4cdb028: 16
------------------------------

------------------------------
Slot NULL: empty
------------------------------
```

## Notes

Parameters use a reference when the function always needs a real slot
(`swapSlots`, the reference `transferStock`) and a pointer when "no slot
at all" must be representable (`isSlotEmpty`, the pointer
`transferStock`), because a reference can never be null. Functions that
only read a slot take `const Slot*` or `const Slot&`, so they accept
read-only data. Pointers are passed by value throughout: copying a
pointer still points at the same slot, so a reference-to-pointer is
never needed. `printSlotInfo` takes its slot by `const` reference so the
address it prints is the real slot's, not a stack copy's. Insufficient
stock and over-capacity transfers are ordinary runtime refusals handled
with `if` and a `[[nodiscard]] bool` result, not `assert`, so they still
apply in release builds, and the source check runs first so
`destination + amount` can't wrap around on the unsigned `Slot` type.