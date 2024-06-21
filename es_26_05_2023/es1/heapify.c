#include "minheap.h"

Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	Heap* ss = HeapCreateEmpty();
	if (ss == NULL) {
		return ss;
	}
	for (size_t i = 0; i < v_size; i++) {
		HeapMinInsertNode(ss,&v[i]);
	}
	return ss;
}
//int main() {
//	int v[] = { 4,56,29,0,8,7,6 };
//	Heap* p = HeapCreateEmpty();
//	p=HeapMinHeapify(v,7);
//	HeapWriteStdout(p);
//	return 0;
//}