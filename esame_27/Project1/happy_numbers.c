#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

int numerofelice(int n) {
	int num = n;
	int ret = 0;
	while (num!=0)
	{
		ret = ret +(int)pow(num % 10, 2);
		num = num / 10;
	}
	return ret;
}

bool HappyRec(int n) {
	if (n == 0 || n == 4)
		return false;
	else if (n == 1)
		return true;
	n = numerofelice(n);
	HappyRec(n);
}

int main(int argc,char *argv[]) {
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	bool c=HappyRec(n);
	if (c)
		printf("Felice");
	else
		printf("Infelice");
	return 0;
}