#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void subsetkrec(int n, int k, bool* vcurr, int i, int* nsol) {
	if (i == n) {
		int cont=0;
		for (int j = 0; j < n; j++) {
			if (vcurr[j]) {
				cont++;
			}
		}
		if (cont==k) {
			(*nsol)++;
			printf("{");
			for (int j = 0; j < n; j++) {
				if (vcurr[j]) {
					printf(" %i ", j);
				}
			}
			printf("},");
		}
		return;
	}
	vcurr[i] = 0;
	subsetkrec(n, k, vcurr, i + 1, nsol);
	vcurr[i] = 1;
	subsetkrec(n, k, vcurr, i + 1, nsol);

}

int subsetk(int n,int k) {
	bool* vcurr = calloc(n, sizeof(bool));
	int nsol = 0;
	subsetkrec(n,k,vcurr,0,&nsol);
	free(vcurr);
	return nsol;
}
void main() {
	subsetk(4,2);
	return;
}