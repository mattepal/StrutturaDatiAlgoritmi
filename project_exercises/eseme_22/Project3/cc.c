#include "cc.h"

bool IsIn(const ElemType i_l,const ElemType *v,size_t v_size) {
	for (size_t j = 0; j < v_size; j++) {
		if (i_l==v[j])
			return true;
	}
	return false;

}

// 1-2-3-4-5-6-7-8
//3-7-6-8
//
int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size)
{	
	int c = 0;
	bool isIn=false,prec=false;
	for (; !ListIsEmpty(i); i = ListGetTail(i)) {
			isIn = IsIn(i->value, v, v_size);
			if (!isIn) {
				if (prec == true) {
					c = c + 1;
					prec = false;
				}
			}
			else {
				prec = true;
			}
	}
	if (prec && isIn)
		c++;
	return c;
}

//Item* ListCreateFromVector(const int* v, size_t v_size) {
//	Item* list = ListCreateEmpty();
//	for (size_t i = 0; i < v_size; ++i) {
//		list = ListInsertBack(list, &v[i]);
//	}
//	return list;
//}
//
//int main(void) {
//	int iv[] = { 0,1,2,3,4 };
//	size_t iv_size = sizeof(iv) / sizeof(int);
//	Item* i = ListCreateFromVector(iv, iv_size);
//	int v[] = {3,4};
//	size_t v_size = 2;
//
//	int res = ComponentiConnesse(i, &v, v_size);
//
//	ListDelete(i);
//
//	return res;
//}