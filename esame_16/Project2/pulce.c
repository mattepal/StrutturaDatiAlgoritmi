#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool proib(const int* f, size_t f_size,int pos) {
	for (size_t c = 0; c < f_size; c++) {
		if (f[c] == pos)
			return true;
	}
	return false;
}

void GuidaLaPulceRec(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size,char *vcurr,int i,int pos,char *vbest) {
	if (i == n || pos < 0 || proib(f, f_size, pos)) {
		return;
	}
	if (pos == h) {
		if (i < (int)*ret_size) {
			*ret_size = i;
			for (int j = 0; j < n;j++) {
				vbest[j] = vcurr[j];
			}
		}
		return;
	}

	vcurr[i] = 'a';
	GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, vcurr, i+1, pos+a, vbest);
	if (vcurr[i-1] != 'b' ) {
		vcurr[i] = 'b';
		GuidaLaPulceRec(f, f_size, a, b, n, h, ret_size, vcurr, i + 1, pos - b, vbest);
	}
	vcurr[i] = 'a';
}

char* GuidaLaPulce(const int* f, size_t f_size, int a, int b, int n, int h, size_t* ret_size) {
	char* vcurr = calloc(n+1, sizeof(char));
	char* vbest = calloc(n + 1, sizeof(char));
	*ret_size = n + 4;
	GuidaLaPulceRec(f,f_size,a,b,n,h,ret_size,vcurr,0,0,vbest);
	if (*ret_size == (n + 4)) {
		*ret_size = 0;
		free(vcurr);
		free(vbest);
		return NULL;
	}
	free(vcurr);
	return vbest;
}
//int main() {
//	const int f[] = { 12,4,7,1,15 };
//	int a = 3,b=15,h=9,n=5;
//	size_t ret_size = 0;
//	char* vbest = calloc(n + 1, sizeof(char));
//	vbest=GuidaLaPulce(f, 5, a, b, n, h, &ret_size);
//	return 0;
//
//}