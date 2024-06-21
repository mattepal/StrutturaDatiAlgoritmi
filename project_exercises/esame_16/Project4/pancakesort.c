
#include <stdlib.h>

void Flip(int* v, size_t n) {
	size_t cnt = n;
	int tmp;
		for (size_t s = 0; s <= n/2 ; s++) {
			tmp = v[s];
			v[s] = v[cnt];
			v[cnt] = tmp;
			cnt--;
		}
	
	return;
}

void PancakeSortRec(int* v, size_t curr_size) {
	if (curr_size == 1) {
		return;
	}
	size_t m = 0;
	int max = 0;
	for (size_t c = 0; c < curr_size; c++) {
		if (v[c] > max) {
			max = v[c];
			m = c;
		}
	}
	Flip(v, m);
	Flip(v, curr_size-1 );
	PancakeSortRec(v, curr_size - 1);
}

void PancakeSort(int* v, size_t v_size) {
	if (v == NULL)
		return ;
	PancakeSortRec(v, v_size);
}

//int main() {
//	int v[] = { 2,6,1,21,12 };
//	PancakeSort(v, 5);
//	return 0;
//}