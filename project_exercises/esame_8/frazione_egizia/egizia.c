#include <stdio.h>

void FrazioneEgizia(int n, int d) {
	if (n <= 0 || d <= 0 || n >= d) {
		printf("Impossibile convertire la frazione data in frazione egizia");
		return;
	}
	int FUD = 0;
	FUD= (d / n) + 1;
	if (d % n == 0) {
		printf("1/%d", FUD-1);
		return;
	}
	printf("1/%d +", FUD);
	n = n * FUD - (1 * d);
	d = d * FUD;
	FrazioneEgizia(n, d);
}
//int main() {
//	int n = 7;
//	int d = 24;
//	FrazioneEgizia(n, d);
//	return 0;
//}