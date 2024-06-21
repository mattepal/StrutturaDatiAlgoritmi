#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <math.h>

void ValidTimesRec(uint8_t n, int *vcurr,int i,int cnt) {
	int h = 0, m = 0;
	int f = 0;
	if (i == 11){
		if (cnt == n) {
			for (int j = 0; j < 11; j++) {
				if (j < 5) {
					if (vcurr[j] == 1) {
						h = h + pow(2, j);
					}
				
				}
				if (j >= 5) {
					if (vcurr[j] == 1) {
						m = m + pow(2, f);
					}
					f += 1;
				}

			}
			if (h <= 24 && m <= 59) { 
				printf("%02d:%02d, ", h, m); 
			}
		}
		return;
	}

		vcurr[i] = 1;
		ValidTimesRec(n, vcurr, i + 1, cnt + 1);
		vcurr[i] = 0;
		ValidTimesRec(n, vcurr, i + 1, cnt);
}

void ValidTimes(uint8_t n) {
	if (n > 11)
		return;
	int* vcurr = calloc(11,sizeof(int));
	ValidTimesRec(n, vcurr, 0,0);
	free(vcurr);
	return;
}

//int main() {
//	ValidTimes(8);
//	return;
//}