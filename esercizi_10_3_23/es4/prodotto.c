int Prodotto(int a, int b) {
	if (a < 0 || b < 0) {
		return -1;
	}
	if (a == 0 || b == 0) {
		return 0;
	}
	if (b == 1) {
		return a;
	}
	else {
		return Prodotto(a,b-1)+a;
	}
}
