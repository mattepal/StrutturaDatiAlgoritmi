#include "next_greater.h"



ElemType* NextGreater(const Item* list, size_t* answer_size) {
	size_t cnt = 0;
	for (Item* tmp2 = list; !ListIsEmpty(tmp2); tmp2 = ListGetTail(tmp2)) {
		cnt += 1;
	}
	if (ListIsEmpty(list)) {
		*answer_size = 0;
		return NULL;
	}
	*answer_size = cnt;
	ElemType* answer = calloc(cnt, sizeof(ElemType));
	int c = 0;
	for (Item* tmp = list; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		int cnt = 0;
		for (Item* tmp1 = tmp; !ListIsEmpty(tmp1); tmp1 = ListGetTail(tmp1)) {
			if (ElemCompare(&tmp->value,&tmp1->value) < 0) {
				cnt += 1;
			}
			if (cnt == 1) {
				answer[c] = tmp1->value;
				cnt++;
				c++;
				break;
			}
		}
		if (cnt < 1) {
			answer[c] = INT_MIN;
			c++;
		}
	}
	return answer;

}

Item* ListCreateFromVector(const int* v, size_t v_size) {
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, &v[i]);
	}
	return list;
}

//int main(void) {
//	int v[] = { 2, 3, 1, 4, 7, 2 };
//	size_t v_size = sizeof(v) / sizeof(int);
//	Item* list = ListCreateFromVector(v, v_size);
//	size_t answer_size;
//	ElemType* answer = NextGreater(list, &answer_size);
//	free(answer);
//
//	ListDelete(list);
//
//	return EXIT_SUCCESS;
//}