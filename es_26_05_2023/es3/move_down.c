#include "minheap.h"

void HeapMinMoveDownRec(Heap* h, int i) {
	int r=HeapRight(i), l=HeapLeft(i), s = i;
	if((l < (int)h->size) && *HeapGetNodeValue(h, l) < *HeapGetNodeValue(h, s)){
		s = l;
	}
	if ((r < (int)h->size) && *HeapGetNodeValue(h, r) < *HeapGetNodeValue(h, s)) {
		s = r;
	}
	if (s != i) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, s));n

		i = s;
		HeapMinMoveDownRec(h, i);
	}
	return;
}