#include "list.h"

//Item* RemoveDuplicates(Item* i){
//	Item* head = i;
//	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
//		ElemType *tmp1 = ListGetHeadValue(head);
//		if (ElemCompare(tmp1, ListGetHeadValue(tmp))==0) {
//			ListGetTail(head);
//			break;
//			ListDelete()
//		}
//
//	}
//	return i;
//}

Item* RemoveDuplicates(Item* i) {
	//Base case
	if (i == NULL)
		return NULL;
	//Next non-duplicate element
	Item* head = i;
	for (Item* tmp = i->next; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(ListGetHeadValue(head), ListGetHeadValue(tmp)) == 0) {
			head->next = tmp->next;
			tmp->next = NULL;
			ListDelete(tmp);
			tmp = head;
		}
		else {
			head = head->next;
		}
	}
	return i;
}

Item* ListCreateFromVector(const int* v, size_t v_size) {
	Item* list = ListCreateEmpty();
	for (size_t i = 0; i < v_size; ++i) {
		list = ListInsertBack(list, &v[i]);
	}
	return list;
}

int main(void) {
	int v[] = { 1,1,1,2,2,2,3,3,3,4,4,4,5,6,7,8,9,10,10,10 };
	size_t v_size = sizeof(v) / sizeof(int);
	Item* list = ListCreateFromVector(v, v_size);
	ListWriteStdout(list);
	list = RemoveDuplicates(list);
	ListWriteStdout(list);
	return 0;
}