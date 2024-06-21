#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void SommaKRec(int n, int k, int *vcurr, int i,int somma,int *nsol) {
	if (i == n) {
		if (somma == k) {
			*nsol = *nsol + 1;
			printf("{");
			for (int s = 0; s < n; s++) {
				if (vcurr[s] == 1) {
					printf("%d, ", s + 1);
				}
			}
			printf("}, ");
		}
		return;
	}
	vcurr[i] = 0;
	SommaKRec(n, k, vcurr, i + 1, somma,nsol);
	vcurr[i] = 1;
	SommaKRec(n,k,vcurr,i+1,somma+(i+1),nsol);

}


int SommaK(int n, int k) {
	int nsol = 0;
	int* vcurr = calloc(n, sizeof(int));
	SommaKRec(n,k,vcurr,0,0,&nsol);
	free(vcurr);
	return nsol;
}

