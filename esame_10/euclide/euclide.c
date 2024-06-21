int MCD(int m, int n) {
	if (n == 0) {
		return m;
	}
	return MCD(n, m % n);
}
//int main() {
//	int m = 3, n =12;
//	MCD(m, n);
//}