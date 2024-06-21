#include "no_dups.h"

Item* RemoveDuplicates(const Item* i) {
	Item* ret = ListCreateEmpty();
	if (ListIsEmpty(i)) {
		return ret;
	}
	bool find = false;
	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		for (Item* tmp1 = ret; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if (ElemCompare(&tmp->value, &tmp1->value) == 0) {
				find = true;
				break;
			}
		}
		if (find) {
			find = false;
		}
		else {
			ret = ListInsertBack(ret, &tmp->value);
		}
	
	}
	return ret;
}

