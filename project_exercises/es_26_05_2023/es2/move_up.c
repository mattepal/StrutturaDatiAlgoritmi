#include "minheap.h"

void HeapMinMoveUpRec(Heap* h, int i) {
	if (i != 0 && *HeapGetNodeValue(h,i) <*HeapGetNodeValue(h,HeapParent(i))) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, HeapParent(i)));
		i = HeapParent(i);
		HeapMinMoveUpRec(h, i);
	}
	return;
}
//void main() {
//	int v[] = { 4,56,29,0,8,7,6 };
//	Heap* p = HeapCreateEmpty();
//	p=Heap
//	HeapMinMoveUp(p,7);
//	HeapWriteStdout(p);
//}