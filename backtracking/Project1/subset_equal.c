#include <stdlib.h>
#include <stdio.h>

SubsetEqualRec(int n,int s,int *vcurr,int i,int summ) {
	if (i == n) {
		if (s == summ) {
			printf("{ ");
			for (int j = 0; j < n; j++) {
				if (vcurr[j])
					printf("%d ", j+1);
			}
			printf("}, ");
		}
		return;
	}
	vcurr[i] = 1;
	SubsetEqualRec(n, s, vcurr, i + 1, summ+i+1);
	vcurr[i] = 0;
	SubsetEqualRec(n, s, vcurr, i + 1, summ);
}

int SubsetEqual(int n,int s) {
	if (n <= 0 || s <= 0)
		return 1;
	int* vcurr = calloc(n,sizeof(int));
	SubsetEqualRec(n, s, vcurr, 0,0);
	free(vcurr);
	return 0;
}

int main() {
	SubsetEqual(4, 6);
	return 0;
}