#include "diff_dlist.h"
//
//ElemType valore(const Item* i, int len) {
//	ElemType ret = 0;
//	for (int c = 0; c < len; c++) {
//		ret = i->value;
//	}
//	return ret;
//}
//
//int ListLen(const Item *i) {
//	int cnt = 0;
//	for (const Item* i1 = i; !DListIsEmpty(i1); i1 = DListGetTail(i1)) {
//		cnt++;
//	}
//	return cnt;
//}

Item* DListDiff(const Item* i1, const Item* i2) {
	Item* ris = DListCreateEmpty();
	const Item* t1 = i1;
	const Item* t2 = i2;
	ElemType n=0,s=0;
	int res = 0;
	if (DListIsEmpty(t2)) {
		while (!DListIsEmpty(t1)) {
			ris = DListInsertBack(ris, &t1->value);
			t1 = DListGetTail(t1);
		}
		return ris;
	}
	if (DListIsEmpty(t1)) {
		while (!DListIsEmpty(t2)) {
			ris = DListInsertBack(ris, &t2->value);
			t2 = DListGetTail(t2);
		}
		return ris;
	}
	if (DListIsEmpty(i1) && DListIsEmpty(i2))
		return ris;
	t1 = i1;
	t2 = i2;
	while (t1->next != NULL) {
		t1 = DListGetTail(t1);
	}
	while (t2->next != NULL) {
		t2 = DListGetTail(t2);
	}
	while (t1!=NULL)
	{
		n = t1->value;
		if (t2 == NULL) {
			s = 0;
		}
		else {
			s = t2->value;
		}
		if (res > 0) {
			n = n - 1;
			res = 0;
		}
		if (n < s) {
			res = 1;
			n = n + 10;
		}
		n = n - s;
		ris = DListInsertHead(&n, ris);
		if(!DListIsEmpty(t1))
			t1 = t1->prev;
		if (!DListIsEmpty(t2))
			t2 = t2->prev;
	}
	return ris;
}
//
//Item* DListCreateFromVector(const ElemType* v, size_t v_size) {
//	Item* list = DListCreateEmpty();
//	for (size_t i = 0; i < v_size; ++i) {
//		list = DListInsertBack(list, &v[i]);
//	}
//	return list;
//}
//
//int main(void) {
//	ElemType v1[] = { 9, 5, 4 };
//	size_t v_size1 = sizeof(v1) / sizeof(ElemType);
//	Item* list1 = DListCreateFromVector(v1, v_size1);
//	ElemType v2[] = { 1,2};
//	size_t v_size2 = sizeof(v2) / sizeof(ElemType);
//	Item* list2 = DListCreateFromVector(v2, v_size2);
//
//	Item* res = DListDiff(list1, list2);
//	DListWriteStdout(res);
//	DListDelete(list1);
//	DListDelete(list2);
//	DListDelete(res);
//	return 0;
//}