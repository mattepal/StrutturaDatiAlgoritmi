#include <stdlib.h>

typedef struct {
	rsize_t capacity;
	rsize_t size;
	int* dati;
}Vector;

void vectorpush(Vector* v, int e) {
	if (v->capacity == v->size) {
		v->capacity *= 2;
		v->dati = realloc(v->dati,v->capacity*sizeof(int));
	}
	v->dati[v->size] = e;
	(v->size)++;
}
void swap(int *a,int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void selectionsort(Vector* v) {
	for (size_t i = 0; i < v->size; i++) {
		size_t minpos = i;
		for (size_t j = i+1; j <v->size; j++)
		{
			if (v->dati[j]<v->dati[minpos]) {
				minpos = j;
			}
		}
		if (i != minpos) {
			swap(v->dati+i,v->dati+minpos);
		}
	}
}
//int main(void) {
//	Vector v = { .capacity = 1,.size = 0,.dati = malloc(sizeof(int)) };
//	srand(0);
//	for (int i = 0; i < 20; i++)
//	{
//		vectorpush(&v, rand());
//	}
//	selectionsort(&v);
//	return EXIT_SUCCESS;
//}