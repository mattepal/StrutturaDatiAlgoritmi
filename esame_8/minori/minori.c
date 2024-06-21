#include "list.h"
#include <stdint.h>
#include <stdlib.h>

Item* CreaDaMinori(const Item* i, int v) {
	Item* new =ListCreateEmpty();
	if (ListIsEmpty(i)) {
		return NULL;
	}
	int cont = 0;
	for (Item*tmp=i; !ListIsEmpty(tmp);tmp=ListGetTail(tmp)) {
		if (ElemCompare(&v,ListGetHeadValue(tmp))>=0) {
			new=ListInsertBack(new, ListGetHeadValue(tmp));
			cont++;
		}
	}
	if (cont == 0) {
		return NULL;
	}
	return new;
}
//int main(void) {
//	Item* test = ListCreateEmpty();
//	for (int i = 0; i < 10; i++) {
//		test = ListInsertBack(test, &i);
//	}
//	Item* res = CreaDaMinori(test, 5);
//	return 0;
//}