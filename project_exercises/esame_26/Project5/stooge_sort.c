#include <stdint.h>
#include <stdlib.h>

size_t TwoThirds(size_t n) {
	if (n % 3 == 0) {
		return (2 * n) / 3;
	}
	return (2 * n) / 3 + 1;
}

void swap(int *a,int * b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void stoogeRec(int *vector,size_t vector_size) {
	if (vector_size < 2 || vector==NULL) {
		return;
	}
	if (vector_size == 2) {
		if (vector[0] > vector[vector_size - 1])
			swap(&vector[0], &vector[vector_size - 1]);
	}
	else {
		int med = TwoThirds(vector_size);
		stoogeRec(vector, med);
		stoogeRec(vector + (vector_size/3), med);
		stoogeRec(vector, med);
	}
}

void Stooge(int* vector, size_t vector_size) {
	
	stoogeRec(vector, vector_size);
}

//int main(void) {
//	int a[] = { 3,5,7,1,2,3,46,21 };
//	Stooge(a, 8);
//	return 0;
//}