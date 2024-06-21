#include "vettore.h"


void vectorpush(Vector* v, const ElemType e) {

	if (v->capacity == v->size) {
		if (v->capacity == 0) {
			v->capacity = 1;
		}
		v->capacity *= 2;
		v->data = realloc(v->data, v->capacity * sizeof(ElemType));
	}
	v->data[v->size] = e;
	(v->size)++;
}

Vector* VectorRead(const char* filename)
{
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Vector* v = calloc(1, sizeof(Vector));
	ElemType e = 0;
	while (ElemRead(f, &e) == true)
	{
		vectorpush(v, e);
	}
	fclose(f);
	return v;
}
Vector* VectorReadSorted(const char* filename)
{
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	Vector* v = calloc(1, sizeof(Vector));
	ElemType e = 0;
	while (ElemRead(f, &e) == true)
	{
		//vectorpush2(v, e);
		vectorpush3(v, e);
	}
	fclose(f);
	return v;
}


void vectorpush3(Vector* v, ElemType e) {

	if (v->capacity == v->size) {
		if (v->capacity == 0) {
			v->capacity = 1;
		}
		v->capacity *= 2;
		v->data = realloc(v->data, v->capacity * sizeof(ElemType));
	}
	size_t minpos = v->size;
	for (size_t j = 0; j < v->size; j++) {
		if (ElemCompare(&e, &v->data[j]) < 0) {
			memmove(v->data + j + 1, v->data + j, sizeof(ElemType) * (v->size  - j));
			minpos = j;
			break;
		}
	}
	v->data[minpos] = e;
	(v->size)++;
}


void vectorpush2(Vector* v, ElemType e) {

	if (v->capacity == v->size) {
		if (v->capacity == 0) {
			v->capacity = 1;
		}
		v->capacity *= 2;
		v->data = realloc(v->data, v->capacity * sizeof(ElemType));
	}
	(v->size)++;
	ElemType tmp = 0;
	if (v->size == 1) {
		v->data[0] = e;
	}
	else {
		for (size_t j = 0; j < v->size - 1; j++) {
			if (ElemCompare(&e, &v->data[j]) < 0) {
				memmove(v->data + j + 1, v->data + j, sizeof(ElemType) * (v->size - 1 - j));
				v->data[j] = e;
				break;
			}
			else if (j + 1 == v->size - 1) {
				v->data[j + 1] = e;
			}
		}
	}
}


int main(void) {
	Vector* v = VectorRead("input_int_02.txt");
	printf("Non sorted: ");
	for (int i = 0; i < v->size; i++) {
		ElemWriteStdout(&v->data[i]);
		printf(" ");
	}
	printf("\n\nSorted: ");
	v = VectorReadSorted("input_int_02.txt");
	for (int i = 0; i < v->size; i++) {
		ElemWriteStdout(&v->data[i]);
		printf(" ");
	}
	free(v->data);
	free(v);
	return 0;
}