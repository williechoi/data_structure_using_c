#ifndef __SLOT_H__
#define __SLOT_H__

#include "Person.h"

typedef int Key;
typedef Person* Value;

enum SlotStatus
{
	EMPTY,
	DELETED,
	INUSE
};

typedef struct _slot
{
	Key key;			// 4byte (Key -> int)
	Value val;			// 4byte (Value -> pointer)
	enum SlotStatus status;
} Slot;

#endif