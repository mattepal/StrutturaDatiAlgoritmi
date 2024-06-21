#include <stdio.h>
#include <stdlib.h>

void MapRec(double x0,double r,int n) {
	if (n ==0) {
		printf("%f",x0);
		return;
	}
	x0 = r * x0 * (1 - x0);
	n = n - 1;
	MapRec(x0, r, n);
	
}


int main(int argc,char* argv[]) {
	if (argc != 4)
		return 1;
	double x0 = atof(argv[1]),r=atof(argv[2]);
	int n = atoi(argv[3]);
	if (x0 < 0 || x0>1 || r < 0 || n < 0)
		return 1;
	MapRec(x0,r,n);
	return 0;
}