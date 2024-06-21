#include "sum_dlist.h"

Item* DListSum(const Item* i1, const Item* i2) {
	Item* ret = DListCreateEmpty();
	const Item* s1 = i1;
	const Item* s2 = i2;
	size_t len1 = 0, len2 = 0;
	ElemType r = 0;
	ElemType r1, r2;
	bool resto = false;
	if (DListIsEmpty(i1) && DListIsEmpty(i2)) {
		return ret;
	}
	else if (DListIsEmpty(i1)) {
		while (s2 != NULL) {
			ret = DListInsertBack(ret, &s2->value);
			s2 = DListGetTail(s2);
		}
		return ret;
	}
	else if (DListIsEmpty(i2)) {
		while (s1 != NULL) {
			ret = DListInsertBack(ret, &s1->value);
			s1 = DListGetTail(s1);
		}
		return ret;
	}
	s1 = i1;
	s2 = i2;
	while (s1->next != NULL) {
		s1=DListGetTail(s1);
		len1++;
	}
	while (s2->next!=NULL)
	{
		s2 = DListGetTail(s2);
		len2++;
	}
	if (len1 >= len2) {
		do
		{
			r1 = s1->value;
			if (s2 != NULL)
				r2 = s2->value;
			else
				r2 = 0;
			r = r1 + r2;
			if (resto) {
				r = r + 1;
				resto = false;
			}
			if (r > 9) {
				r = r - 10;
				resto = true;
			}
			ret = DListInsertHead(&r, ret);
			s1 = s1->prev;
			if (s2 != NULL)
				s2=s2->prev;
		} while (s1 != NULL);
	}
	else {
		do
		{
			if (s1 != NULL)
				r1 = s1->value;
			else
				r1 = 0;
			r2 = s2->value;
			r = r1 + r2;
			if (resto) {
				r = r + 1;
				resto = false;
			}
			if (r > 9) {
				r = r - 10;
				resto = true;
			}
			ret = DListInsertHead(&r, ret);
			s2 = s2->prev;
			if (s1 != NULL)
				s1=s1->prev;
		} while (s2 != NULL);
	}

	if (resto) {
		r = 1;
		ret = DListInsertHead(&r, ret);
	}
	return ret;
}

//Item* ListCreateFromVector(const int* v, size_t v_size) {
//	Item* list = DListCreateEmpty();
//	for (size_t i = 0; i < v_size; ++i) {
//		list = DListInsertBack(list, &v[i]);
//	}
//	return list;
//}
//int main(void) {
//	int v[] = { 9, 9, 9, 9 };
//	size_t v_size = sizeof(v) / sizeof(int);
//	Item* list1 = ListCreateFromVector(v, v_size);
//	int v1[] = { 1};
//	size_t v_size1 = sizeof(v1) / sizeof(int);
//	Item* list2 = ListCreateFromVector(v1, v_size1);
//	list1 = DListSum(list1, list2);
//	DListWriteStdout(list1);
//	DListDelete(list1);
//
//	return 0;
//}