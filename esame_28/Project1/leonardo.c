#include <stdio.h>
#include <stdlib.h>

int Leonardo(int n){
		if (n == 0)
			return 1;
		else if (n == 1)
			return 1;
		else
			return Leonardo(n - 1) + Leonardo(n - 2) + 1;
}


int main(int argc,char* argv[]) {
	if (argc != 2)
		return 1;
	int n = atoi(argv[1]);
	int i = 0;
	if (n < 0)
		return 1;
	while (i<=n) {
		printf("%d, ", Leonardo(i));
		i++;
	}
	return 0;
}
