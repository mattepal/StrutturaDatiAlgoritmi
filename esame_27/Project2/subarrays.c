#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool contigui(size_t n,int *vcurr) {
	bool pres = false;
	for (size_t i = 0; i < n; i++) {
		if (vcurr[i] == 1) {
			for (size_t f = i + 1; f < n; f++) {
				if (vcurr[f] == 1 && pres)
					return false;
				else if (vcurr[f] == 0 && !pres)
					pres = true;
			}
		}
	}
	return true;
}

void OptimalSubarrayRec(const int *v, size_t n,int* vcurr, int i,int summ,int *summbest) {
	if (i == n) {
		if (contigui(n,vcurr)) {
			if (summ > *summbest) {
				*summbest = summ;
			}
		}
		return;
	}
	vcurr[i] = 0;
	OptimalSubarrayRec(v, n, vcurr,  i + 1, summ,summbest);
	vcurr[i] = 1;
	OptimalSubarrayRec(v, n, vcurr,  i + 1, summ + v[i],summbest);
}

int OptimalSubarray(const int* v, size_t n) {
	int* vcurr = calloc(n, sizeof(int));
	int summbest = 0;
	OptimalSubarrayRec(v, n, vcurr, 0,0,&summbest);
	free(vcurr);
	return summbest;
}

int main() {
	int v[] = { 1, 1, 1, -5, -1, -1, -1, -5, -1, -1, -1 };
	int c=OptimalSubarray(v, 11);
	printf("%d", c);
	return 0;

}