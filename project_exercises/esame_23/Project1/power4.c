#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ispow(int is_pow, int ris,int *cnt) {
	if (is_pow < ris)
		return false;
	if (is_pow == ris) {
		return true;
	}
	else {
		*cnt += 1;
		ispow(is_pow, ris * 4,cnt);
	}
}

int main(int argv, char* argc[]) {
	if (argv != 2)
		return 1;
	int is_pow = atoi(argc[1]);
	int cnt = 0;
	bool ris= ispow(is_pow,1,&cnt);
	if(ris)
		printf("4^%d = %d", cnt, is_pow);
	else
		printf("!p4");
	return 0;
}