#include "pulce.h"

const Item* CalcolaPercorso(const Item* start, size_t n) {
	if (DListIsEmpty(start))
		return NULL;
	if (DListGetTail(start) == NULL && DListGetPrev(start) == NULL)
		return start;
	int salti = 0;
	bool strada = false;
	while (salti <= n) {
		ElemType salticurr = start->value;
		if (salticurr == 0) {
			return start;
		}
		if (salticurr > 0) {
			for (ElemType c = 0; c < salticurr; c++) {
				if (start->next==NULL) {
					strada = true;
				}
				salti++;
				if (!strada) {
					start = start->next;
				}
				else {
					if (start->prev == NULL) {
						strada = false;
					}
					else {
						start = start->prev;
					}
				}
			
			}
		}
	}
}

//Item* ListCreateFromVector(const int* v, size_t v_size) {
//	Item* list = DListCreateEmpty();
//	for (size_t i = 0; i < v_size; ++i) {
//		list = DListInsertBack(list, &v[i]);
//	}
//	return list;
//}
//int main(void) {
//	int v[] = { 2, -3, 4, 1, 0, 5, -12, 3 };
//	size_t v_size = sizeof(v) / sizeof(int);
//	Item* list = ListCreateFromVector(v, v_size);
//	DListWriteStdout(list);
//	ElemType ret = CalcolaPercorso(list+2,13 );
//	DListWriteStdout(list);
//	DListDelete(list);
//
//	return 0;
//}