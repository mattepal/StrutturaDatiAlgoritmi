#include <stdlib.h>

int *risolviProdottoRec(int n, const int *s,int *vcurr, int *vsol,int i ){
	if (i == n * n) {
	
	}
	for (int j = 0; j < n * n; j++) {
		vcurr[i] = s[j];
		risolviProdottoRec(n, s, vcurr, vsol, i + 1);
	}
}

int* RisolviProdotto(int n, const int* s) {

	int* vcurr = calloc(n * n, sizeof(int));
	int* vsol = calloc(n + n, sizeof(int));
	risolviProdottoRec(n, s, vcurr, vsol, 0);

}