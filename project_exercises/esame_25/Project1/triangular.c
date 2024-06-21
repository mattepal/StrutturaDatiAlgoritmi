#include <stdio.h>
#include <stdlib.h>

int triangolarRec(int n) {
	if (n == 0)
		return 0;
	if (n == 1) {
		return 1;
	}
	if (n == 2)
		return 3;
	if (n >= 3) {
		return 3 * triangolarRec(n - 1) - 3 * triangolarRec(n - 2) + triangolarRec(n - 3);
	}

}

int main(int argv, char* argc[]) {
	if (argv != 2) {
		return 1;
	}
	int n = atoi(argc[1]);
	if (n < 0)
		return 1;
	int c= triangolarRec(n);
	printf("%d", c);
	return 0;
}