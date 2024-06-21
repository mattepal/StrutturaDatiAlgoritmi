#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void swap(int *y,int *x) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}

void CocktailSort(int* v, size_t v_size) {
	size_t start = 0;
	size_t end = v_size - 1;
	bool ordinato = false;
	if (v == NULL)
		return;
	while (start < end && !ordinato) {
		ordinato = true;
		for (size_t i = 1; i <= end; i++) {
			if (v[i] < v[i - 1]) {
				swap(&v[i], &v[i - 1]);
				ordinato = false;
			}
		}
		for (size_t c = end; c != start+1; c--) {
			if (v[c] < v[c - 1]) {
				swap(&v[c], &v[c - 1]);
				ordinato = false;
			}
		}
		start++;
		end--;
	}
	return;
}
//int main() {
//	int v[] = { 2,1,3 };
//	CocktailSort(&v, 3);
//	for (int i = 0; i < 3; i++) {
//		printf("%d, ",v[i]);
//	}
//	return 0;
//}