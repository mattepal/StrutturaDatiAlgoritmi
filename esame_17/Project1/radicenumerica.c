#include <stdio.h>
#include <stdlib.h>

int radice(int n) {
	int ret=0;
	while (n>0)
	{
		ret = ret + n % 10;
		n = n / 10;
	}
	return ret;
}

int RadiceRec(int n) {
	if (n < 10)
		return n;
	n = radice(n);
	RadiceRec(n);
}


int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;
	int n =atoi(argv[1]);
	if (n < 0)
		return 1;
	n=RadiceRec(n);
	printf("%d", n);
	return 0;
}