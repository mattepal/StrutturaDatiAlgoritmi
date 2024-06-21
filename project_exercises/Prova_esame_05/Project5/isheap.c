#include "minheap.h"
#include <stdbool.h>
#include <limits.h>
#include <stdio.h>

void ish(){
	

}

bool IsHeap(const Heap* h) {
	if (HeapIsEmpty(h)) {
		return true;
	}
	if (h == NULL)
		return false;
	 size_t size = h->size;
	 if (size == 1)
		 return true;
	bool heap = true;
	/*while (size>0)
	{
		heap = true;
		ElemType *tmp=HeapGetNodeValue(h, 0);
		HeapMinMoveDown(h, 0);
		if (ElemCompare(tmp, &h->data[0]) != 0) {
			heap = false;
			break;
		}
		else {
			h->data[0] = INT_MAX;
			HeapMinMoveDown(h, 0);
			size--;
		}

	}*/
	return heap;

}
