#include "shift.h"

Item* ShiftN(Item* list, size_t n)
{
	int len = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		len += 1;
	}
	if (ListIsEmpty(list) || len == 1) {
		return list;
	}
	if (n == 0)
		return list;
	n %= (len - 1);
	if (n == 0) {
		n = (len - 1);
	}
	Item* succ = ListGetTail(list);
	Item* precc = list;
	for (int i = 0; i <(int)n; i++) {
		list = ListGetTail(list);
	}
	precc->next = ListGetTail(list);
	list->next = precc;
	return succ;
}

Item* ListCreateFromVector(const int* v, size_t v_size) {
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, &v[i]);
	}
	return list;
}
int main(void) {
	int v[] = { 0,1,2,3,4,5,6,7,8 };
	size_t v_size = sizeof(v) / sizeof(int);
	Item* list = ListCreateFromVector(v, v_size);
	ListWriteStdout(list);
	list = ShiftN(list, 2);
	ListWriteStdout(list);
	ListDelete(list);

	return 0;
}