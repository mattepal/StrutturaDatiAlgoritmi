#include <Stdlib.h>

int* monete(int* tagli, size_t tagli_size, int budget) {
	if (budget <= 0)
		return NULL;

	int* res = calloc(tagli_size, sizeof(int));

	for (int i = 0; i < (int)tagli_size; i++) {
		res[i] = budget / tagli[i];
		budget %= tagli[i];
	}
	return res;
}
