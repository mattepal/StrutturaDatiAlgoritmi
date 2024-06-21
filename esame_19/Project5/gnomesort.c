#include <stdlib.h>

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}

void GnomeSort(int* v, size_t v_size){
	size_t i = 1;
	while(i<v_size) {
		if (v[i] < v[i - 1]) {
			swap(&v[i], &v[i - 1]);
			i = i - 1;
		}
		else {
			i++;
		}
	}
	return;
}

//int main() {
//	int v[] = { 2,6,3,5,4 };
//	GnomeSort(v, 5);
//	return 0;
//}