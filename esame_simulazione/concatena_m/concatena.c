#include "doublelist.h"

ElemType *prendi(Item *v) {
	return DListGetHeadValue(v);
}

Item* ConcatenaN(Item** v, size_t v_size) {
	if (v_size == 0) {
		return 0;
	}
	Item* start = NULL, * finish = NULL;
	for (int i = 1; i < v_size; i++) {
		if (v[i] != NULL) {
			if (finish != NULL) {
				start=
			}
			else {
				start = v[i];
			}
			if (v[i + 1] != NULL) {
				finish = v[];
			}
		}
	}
	return start;
}