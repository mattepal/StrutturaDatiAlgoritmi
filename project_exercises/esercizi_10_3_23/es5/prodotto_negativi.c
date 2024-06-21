#include <math.h>

int ProdottoNegativi(int a, int b) {
	if (a == 0 || b == 0) {
		return 0;
	}
	if(b == 1) {
		return a;
	}
	if (b == -1) {
		return -a;
	}
	if (a < 0) {
		if (b> 0) {
			return ProdottoNegativi(a, b -1) +a;
		}
		if (b < 0) {
			return ProdottoNegativi(a, b+ 1) -a;
		}
	}
	if (a > 0) {
		if (b > 0) {
			return ProdottoNegativi(a, b - 1) +  a;
		}
		if (b < 0) {
			return ProdottoNegativi(a, b + 1) - a;
		}
	}
}


