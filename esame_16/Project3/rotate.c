#include "list.h"

void inserisci(Item* succ, Item* list) {
	Item* tmp = succ;
	while (tmp->next!=NULL)
	{
		tmp =tmp->next;
	}
	tmp->next = list;
	tmp->next->next = NULL;
}

Item* Rotate(Item* i, int n) {
	Item *list = i;
	Item* succ = NULL;
	Item* fine = i;
	while (n > 0) {
		succ = list->next;
		inserisci(succ,list);
		n = n - 1;
	}
	i = succ;
	return i;
}

int main(void) {
	Item* list = ListCreateEmpty();
	ElemType e;
	e = 1;
	list = ListInsertBack(list, &e);
	e = 2;
	list = ListInsertBack(list, &e);
	
	e = 3;
	list = ListInsertBack(list, &e);
	e = 4;
	list = ListInsertBack(list, &e);
	e = 5;
	list = ListInsertBack(list, &e);
	
	ListWriteStdout(list);
	Item* res = Rotate(list, 2);
	ListWriteStdout(res);
	ListDelete(res);
	return 0;
}



