#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int nuovnum(int n){
	int i = n,num=0;
	num = i % 10;
	i = i / 10;
	n = abs(i - (2 * num));
	return n;
}

bool isdivisib(int n) {
	if (n <= 9) {
		if (n == 0 || n == 7) {
			return true;
		}
		else {
			return false;
		}
	}
	n = nuovnum(n);
	isdivisib(n);
}

int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	if (n < 0) {
		return 1;
	}
	bool div = false;
	div=isdivisib(n);
	if (div) {
		printf("Multiplo di 7.");
	}
	else {
		printf("Non multiplo di 7.");
	}
	return 0;
}