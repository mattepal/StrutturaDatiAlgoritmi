#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

void OmbrelloniRec(int k, int n, int i, bool* vcurr, int cnt, int* nsol) {
	if (i == n) {
		for (int j = 0; j < n - 1; j++) {
			if (vcurr[j] && vcurr[j + 1]) {
				return;
			}
		}

		if ( k == cnt) {
			(*nsol)++;
			printf("%4d",(*nsol));
			printf(")");
			for (int j = 0; j < n; j++) {
				printf(" %d", vcurr[j]);
			}
			printf("\n");
		}
		return;
	}

	vcurr[i] = 0;
	OmbrelloniRec(k, n, i + 1, vcurr, cnt, nsol);

	if (vcurr[i - 1] != 1) {
		vcurr[i] = 1;
		OmbrelloniRec(k, n, i + 1, vcurr, cnt + 1, nsol);
	}
}

int Ombrelloni(int k, int n) {
	int nsol = 0;
	if (k <= 0 || n <= 0) {
		return 0;
	}
	if ((k % 2 == 0 && n < k + 1) || (k % 2 != 0 && n < k + 2)) {
		return 0;
	}
	bool* vcurr = calloc(n, sizeof(bool));
	OmbrelloniRec(k, n, 0, vcurr, 0, &nsol);
	free(vcurr);
	return nsol;

}
