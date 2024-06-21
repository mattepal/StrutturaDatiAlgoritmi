int Divisione(int a, int b) {
	if (a < 0 || b <= 0 ) {
		return -1;
	}
	if (a < b) {
		return 0;
	}
	else {
		return Divisione(a-b, b)+1;
	}
}
