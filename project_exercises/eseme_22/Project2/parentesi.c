#define _NO_CRT_SECURE_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void ParentesiRec(int n, bool* vcurr, int i,int uni,int uno,int *nsol) {
	if (i == 2*n) {
		if (!vcurr[0])
			return;
		else if (vcurr[2 * n - 1])
			return;
		else {
			*nsol = *nsol + 1;
			for (int z = 0; z < 2 * n;z++) {
				if(vcurr[z]){
					printf("(");
				}
				else if (!vcurr[z]) {
					printf(")");
				}
			}
			printf("\n");
		}
		return;
	}
	if(uni<n){
		vcurr[i] = true;
		ParentesiRec(n, vcurr, i + 1, uni + 1,uno+1, nsol);
	}
	if (uno != 0) {
		vcurr[i] = false;
		ParentesiRec(n, vcurr, i + 1, uni,uno-1, nsol);
	}

}

int Parentesi(int n) {
	if (n < 0)
		return -1;
	int len = 2 * n;
	int nsol = 0;
	bool* vcurr = calloc(len, sizeof(bool));
	ParentesiRec(n, vcurr, 0,0,0,&nsol);
	free(vcurr);
	return nsol;
}
