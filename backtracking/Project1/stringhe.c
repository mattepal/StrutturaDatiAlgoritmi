#include <stdlib.h>
#include <stdio.h>

void BacktrackStrRec(int n,char *vcurr,int i) {
	if (i == n) {
		printf("{ ");
		for (int c = 0; c < n; c++) {
			printf("%c", vcurr[c]);
		}
		printf("}, ");
		return;
	}
	for (char j = 'a'; j < 'a' + n; ++j) {
		vcurr[i] = j;
		BacktrackStrRec(n, vcurr, i + 1);
	}

}

void BacktrakStr(int n) {

	if (n <= 0 || n > 26) {
		return;

	}
	char *vcurr = calloc(n, sizeof(int));
	BacktrackStrRec(n, vcurr, 0);
	free(vcurr);
}

//int main() {
//	BacktrakStr(3);
//	return 0;
//}