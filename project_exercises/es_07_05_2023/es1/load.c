#define _CRT_SECURE_NO_WARNINGS
#include "list.h"

Item* ListLoad(const char* filename) {
	Item* L = ListCreateEmpty();
	if (filename == NULL)
		return L;
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return L;
	}
	ElemType e;
	while (ElemRead(f, &e)>0) {
		L = ListInsertHead(&e, L);
	}
	fclose(f);
	return L;
}
//int main(void) {
//	ListLoad("data_00.txt");
//	return 0;
//}