#include <stdio.h>
#include <stdlib.h>

int IsPrime(int n ,int div,int cnt) {
	if (div == n) {
		return cnt+1;
	}
	if (n % div == 0) {
		cnt = cnt + 1;
	}
	IsPrime(n, div + 1, cnt);
}

int main(int argc, char* argv[]) {
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	int cnt = 0;
	if (n < 0)
		return 1;
	if (n == 0) {
		printf("false");
		return 0;
	}
	cnt=IsPrime(n,1,cnt);
	if (cnt == 2) {
		printf("true");
	}
	else {
		printf("false");
	}
	return 0;
}