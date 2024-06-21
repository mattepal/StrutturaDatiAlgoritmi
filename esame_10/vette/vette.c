#include "list.h"

int contavetterec(const Item* i, int cont) {
	const Item* new = i;
	if (ListIsEmpty(new))
		return cont;
	ElemType* tmp = ListGetHeadValue(new);
	while (!ListIsEmpty(new))
	{
		if (ListGetTail(new) == NULL) {
			break;
		}
		new = ListGetTail(new);
		if (ElemCompare(tmp, ListGetHeadValue(new)) < 0) {
			break;
		}

	}
	cont++;
	i = ListGetTail(i);
	contavetterec(i, cont);
}

int ContaVette(const Item* i) {
	return contavetterec(i,0);
}
//
//int main(void) {
//	Item* list = ListCreateEmpty();
//	for (int i = 10; i-- > 0;) {
//		list = ListInsertBack(list, &i);
//	}
//	int res = ContaVette(list);
//	return 0;
//}


