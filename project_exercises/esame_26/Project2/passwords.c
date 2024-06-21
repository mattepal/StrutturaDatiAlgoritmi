#define _NO_CRT_SECURE_WARNINGS
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

bool isin(int* vcurr, int n) {
	int cnt = 0;
	for (int s = 0; s < n; s++) {
		for (int i = 0; i < n; i++) {
			if (vcurr[i] == vcurr[s]) {
				cnt += 1;
			}
		}
		cnt -= 1;
	}

	if (cnt > 1) {
		return true;
	}
	else {
		return false;
	}
}

bool dec(int* vcurr, int n) {
	for (int i = 1; i < n; i++) {
		if (vcurr[i] < vcurr[i - 1]) {
			return false;
		}
	}
	return true;
}

void PasswordsRec(int n, int* vcurr, int i, int * nsol) {
	if (i == n) {
		if (dec(vcurr, n) && isin(vcurr, n)) {
			*nsol =*nsol+ 1;
			printf("%d) ", *nsol);
			for (int i = 0; i < n; i++) {
				printf("%d", vcurr[i]);
			}
			printf("\n");
		}
		return;
	}
	for (int c = 0; c <= 9; c++) {
		vcurr[i] = c;
		PasswordsRec(n, vcurr, i + 1, nsol);
	}
}

void Passwords(int n) {
	if (n <= 1)
		return;
	int* vcurr = calloc(n, sizeof(int));
	int nsol = 0;
	PasswordsRec(n, vcurr, 0,&nsol);
	free(vcurr);
	return;
}
//int main() {
//	Passwords(2);
//	return 0;
//}