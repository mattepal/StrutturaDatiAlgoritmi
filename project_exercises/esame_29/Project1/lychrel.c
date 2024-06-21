#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>


int num(int n) {
	int nume = n;
	int ret=0;
	int resto;
	while (nume != 0) {
		resto = nume % 10;
		nume = nume / 10;
		ret = resto+ret*10;
	}
	return ret;
}
bool isPalindromo(int n) {
	if (n == num(n))
		return true;
	else
		return false;
}
bool Palindromo(int n,int i ,int c,bool f) {
	if (isPalindromo(n))
		f = true;
	if (i == c) {
		if (f)
			return f;
		else
			return f;
	}
	n = n + num(n);
	Palindromo(n, i, c + 1,f);
}

int main(int argv, char *argc[]) {
	if (argv != 3)
		return 1;
	int n =atoi(argc[1]);
	int i = atoi(argc[2]);
	if (n < 0)
		return 1;
	bool c=false;
	c=Palindromo(n, i, 0,c);
	if (c)
		printf("Non lychrel");
	else
		printf("Lychrel");
	return 0;
}