#include "differenza.h"

Item* Differenza(const Item* i1, const Item* i2)
{
	ElemType p = 0,ris,s=0,m=0;
	const ElemType cost = 1;
	Item* r = ListCreateEmpty();
	if (ListIsEmpty(i2)) {
		for (const Item* tmp = i1; !ListIsEmpty(tmp); tmp = ListGetTail(tmp))
			r = ListInsertBack(r, &tmp->value);
	}
	else {
		while (!ListIsEmpty(i1))
		{
			s = i1->value;
			if (!ListIsEmpty(i2))
				m = i2->value;
			else
				m = 0;
			if (ElemCompare(&p, &cost) == 0) {
				s = s - 1;
				p = 0;
			}
			if (ElemCompare(&i1->value, &i2->value) < 0) {
				p = 1;
				s = s + 10;
			}
			ris = s - m + '0';
			r = ListInsertBack(r, &ris);
			i1 = ListGetTail(i1);
			if(!ListGetTail(i2)){
				i2 = ListGetTail(i2);
			}
		}
	}

	return r;
}

//Item* ListCreateFromVector(const int* v, size_t v_size) {
//	Item* list = ListCreateEmpty();
//	for (size_t i = 0; i < v_size; ++i) {
//		list = ListInsertBack(list, &v[i]);
//	}
//	return list;
//}
//int main(void) {
//	int v[] = { 2,4,5};
//	int v2[] = {4,2,3 };
//	size_t v_size = sizeof(v) / sizeof(int);
//	size_t v_size2 = sizeof(v2) / sizeof(int);
//	Item* list = ListCreateFromVector(v, v_size);
//	Item* list2 = ListCreateFromVector(v2, v_size2);
//	ListWriteStdout(list);
//	ListWriteStdout(list2);
//	Differenza(list,list2);
//	ListWriteStdout(list);
//	ListDelete(list);
//	ListDelete(list2);
//
//	return 0;
//}