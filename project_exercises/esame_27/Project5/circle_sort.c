#include <stdlib.h>
#include <stdbool.h>

void swap(int* x, int* y) {
	int tmp = *x;
	*x = *y;
	*y = tmp;
	return;
}

void CircleSortRec(int* v, size_t v_size, bool *ordinato,int start,int fine) {
	if (v_size == 1) {
		return;
	}
	
	for (;start <=fine ; start++, fine--) {
		if (v[start] > v[fine]) {
			*ordinato = false;
			swap(&v[start], &v[fine]);
		}
	}
	if (v_size % 2 != 0) {
		if (v[(v_size / 2)] > v[(v_size / 2 + 1)]) {
			*ordinato = false;
			swap(&v[v_size / 2], &v[v_size / 2 + 1]);
		}
	}
	if (v_size % 2 != 0) {
		CircleSortRec(v, (v_size + 1) / 2, ordinato,start,v_size/2-1);
		CircleSortRec(v + (v_size / 2), v_size / 2, ordinato, v_size / 2,fine);
	}
	else {
		CircleSortRec(v , v_size / 2, ordinato,start,v_size/2);
		CircleSortRec(v + (v_size / 2), v_size / 2, ordinato,v_size/2-1,fine);
	}
	
}

void CircleSort(int* v, size_t v_size) {
	bool ordinato = false;	
	if (v_size < 0 || v == NULL)
		return ;
	size_t lung = v_size - 1;
	while (!ordinato) {
		ordinato = true;
		CircleSortRec(v,v_size,&ordinato,0,lung);
	}
	return;
}
int main() {
	int v[] = { 4,2,12,5,7,6,1 };
	CircleSort(v, 7);
	return 0;
}