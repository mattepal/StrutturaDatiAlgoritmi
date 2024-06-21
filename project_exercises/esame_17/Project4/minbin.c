#include "tree.h"
#include <stdlib.h>

Node* CreateMinBinTreeRec(const ElemType* v, size_t v_size) {
	if (v == NULL || v_size== 0) {
		return NULL; 
	}
	ElemType min = 0;
	size_t pos = 0;
	for (size_t c = 0; c < v_size; c++) {
		if (ElemCompare(&v[c], &min) < 0) {
			min = v[c];
			pos = c;
		}
	}
	size_t lend = v_size - pos-1;
	size_t lens = pos;
	ElemType* destra = NULL;
	ElemType* sinistra = NULL;
	if (lend > 0)
		destra = calloc(lend, sizeof(ElemType));
	if (lens > 0)
		sinistra = calloc(lens, sizeof(ElemType));
	for (size_t s= 0; s < lens; s++) {
		sinistra[s] = v[s];
	}
	for (size_t d = lend; d < v_size; d++) {
		destra[d] = v[d];
	}

	Node* t = TreeCreateRoot(&min, CreateMinBinTreeRec(sinistra,lens), CreateMinBinTreeRec(destra,lend));
	free(destra);
	free(sinistra);
	return t;
}


Node* CreateMinBinTree(const ElemType* v, size_t v_size) {
	return CreateMinBinTreeRec(v,v_size);
}
