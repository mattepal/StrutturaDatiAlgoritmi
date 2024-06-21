#include "minheap.h"
#include <string.h>
#include <stdlib.h>
#include <limits.h>


int KthLeast(const int* v, size_t n, int k) {
	int min = 0;
	Heap* new = HeapCreateEmpty();
	for (int i = 0; i < n; i++) {
		HeapMinInsertNode(new, &v[i]);
	}
	for (int i = 1; i < k; i++) {
		new->data[0] = INT_MAX;
		HeapMinMoveDown(new, 0);
	}
	min = new->data[0];
	HeapDelete(new);
	return min;
	}

//int main() {
//	int v[] = {0 ,12 ,4 ,21, 2, 18, 77, 8, 9 };
//	size_t n = 9;
//	KthLeast(v,n,2);
//	return 0;
//
//}