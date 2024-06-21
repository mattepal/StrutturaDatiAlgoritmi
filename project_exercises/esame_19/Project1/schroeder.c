#include <stdio.h>
#include <stdlib.h>

int SchroederRec(int n) {
	if (n == 0)
		return 1;
	else if (n == 1)
		return 2;
	int ret = (((6 * n-3) * SchroederRec(n - 1)) / (n + 1)) - (((n - 2) * SchroederRec(n - 2)) / (n + 1));
	return ret;
}

int main(int argv, char* argc[]) {
	if (argv != 2) {
		return 1;
	}
	int n = atoi(argc[1]);
	if (n < 0)
		return 1;
	int ret = 0;
	ret=SchroederRec(n);
	printf("%d",ret);
	return 0;
}