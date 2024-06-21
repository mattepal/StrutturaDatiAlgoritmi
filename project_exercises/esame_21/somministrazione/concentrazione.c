#include <stdio.h>
#include <stdlib.h>

void rec(int n,float c) {
	if (n ==1) {
		printf("%f", c);
		return;
	}
	rec(n - 1, 0.3 * c + 0.2);
}

int main(int argc,char *argv[]) {
	if (argc != 2 || atoi(argv[1]) < 1)
		return 1;
	int n = atoi(argv[1]);
	rec(n,0);
	return 0;
}
