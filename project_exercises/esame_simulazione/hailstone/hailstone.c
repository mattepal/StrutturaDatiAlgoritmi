#include <stdio.h>
#include <stdlib.h>

int hailstonerec(int n, int cont) {
	if (n == 1) {
		printf("%d", n);
		return cont+1;
	}
	if (n % 2 == 0) {
		printf("%d, ", n);
		n = n / 2;
	}
	else if (n % 2 != 0) {
		printf("%d, ", n);
		n = 3 * n + 1;
	}
	cont = cont + 1;
	hailstonerec(n,cont);
}

int main(int argc,char *argv[]) {
	if (argc != 2)
		return -1;
	if (atoi(argv[1]) <= 0)
		return 0;
	int n = atoi(argv[1]);
	int cont = 0;
	cont=hailstonerec(n,cont);
	return cont;
}

