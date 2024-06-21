#include <stdlib.h>
#include <stdio.h>

BackstrackModRec(int n,int k,char* vcurr, int i) {
	if (i == k) {
		printf("{ ");
		for (int j = 0; j < k;j++) {
			printf("%c ", vcurr[j]);
		}
		printf("}, ");
		return;
	}
	for (char c = 'a'; c < 'a' + n; c++) {
		vcurr[i] = c;
		BackstrackModRec(n,k,vcurr,i+1);
	}
}

void BackstrackMod(int n, int k) {
	if (k <= 0 || k > 26 ||n<=0)
		return;
	char* vcurr = calloc(n,sizeof(int));
	BackstrackModRec(n, k, vcurr, 0);
	free(vcurr);
}
//int main() {
//		BackstrackMod(3,1);
//		return 0;
//	}