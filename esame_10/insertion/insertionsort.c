#include <stdlib.h>
#include <string.h>
void InsertionSort(int* v, size_t v_size) {
	if (v == NULL || v_size < 2) {
		return;
	}
	int j = 0;
	for (int i = 1; i < (int)v_size; ++i) {
		j = i;
		int tmp = v[i];
		while (v[j - 1] > tmp) {
			v[j] = v[j - 1]; 
			j--;
			v[j] = tmp;     
		}


	}
}
//int main() {
//	int v[] = {1,4,3,7,5};
//	InsertionSort(&v,5);
//}