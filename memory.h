#ifndef clox_memory_h
#define clox_memory_h

#include "common.h"

#define GROW_CAPACITY(capacity) \
    ((capacity) < 8 ? 8 : (capacity) * 2) // Multiply capacity by 2 if it's greater than eight, otherwise just set it to eight. Pretty straightforward dynamically sized array stuff

#define GROW_ARRAY(type, pointer, old_count, new_count) \
    (type*)reallocate(pointer, sizeof(type) * (old_count), \
            sizeof(type) * (new_count))

#define FREE_ARRAY(type, pointer, old_count) \
    reallocate(pointer, sizeof(type) * (old_count), 0)

/*
oldSize 	newSize 	            Operation
0 	        Non‑zero 	            Allocate new block.
Non‑zero 	0 	                    Free allocation.
Non‑zero 	Smaller than oldSize 	Shrink existing allocation.
Non‑zero 	Larger than oldSize 	Grow existing allocation.
    */

void* reallocate(void* pointer, size_t old_size, size_t new_size);

#endif
