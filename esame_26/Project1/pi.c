#include <stdint.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void PiRec(int n,double p) {
	if (n == 0) {
		p = p + 4;
		printf("%lf", p);
		return;
	}
	else {
			p = p + (4 * pow(-1, n)) / (2 * n + 1);
	}	
	PiRec(n - 1, p);
}

int main(int argv, char* argc[]) {
	if (argv != 2)
		return 1;
	int n = atoi(argc[1]);
	if (n < 0) {
		return 1;
	}
	PiRec(n,0);
	return 0;
}

