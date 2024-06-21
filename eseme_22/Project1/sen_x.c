#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double fatt(int y) {
	double fatt = 1;
	for (int t = 1; t <= y; t++) {
		fatt = fatt * t;
	}
	return fatt;
}

double senX(double x,int i,double sen,int c) {
	if (i < c) {
		return sen;
	}
	double den = fatt(2*c+1);
	sen = sen+((pow(-1, c) / den) * pow(x, 2 * c + 1));
	senX(x, i, sen, c + 1);
}

int main(int argv,char* argc[]) {
	if (argv != 3) {
		return 1;
	}
	double sen = 0;
	double x = atof(argc[1]);
	int i = atoi(argc[2]);
	if (i < 0)
		return 1;
	sen=senX(x,i,sen,0);
	printf("%lf", sen);
	return 0;
}