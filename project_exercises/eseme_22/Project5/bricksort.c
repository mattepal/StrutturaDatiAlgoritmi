#include <stdlib.h>
#include <stdbool.h>

void swap(int *a,int *b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
	return;
}

void BrickSort(int* v, size_t v_size) {
	bool ordinato = false;
	while (!ordinato) {
		ordinato = true;
		for (size_t i = 1; i < v_size; i=i + 2) {
			if (i + 1 < v_size) {
				if (v[i] > v[i + 1]) {
					swap(&v[i], &v[i + 1]);
					ordinato = false;
				}
			}
		}
		for (size_t k = 0; k < v_size; k = k + 2) {
			if (k + 1 < v_size) {
				if (v[k] > v[k + 1]) {
					swap(&v[k], &v[k + 1]);
					ordinato = false;
				}
			}
		}
	}
}