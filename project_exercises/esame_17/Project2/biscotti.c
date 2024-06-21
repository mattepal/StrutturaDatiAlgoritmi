#include <stdlib.h>
#include <stdbool.h>

int BiscottiRec(const int *bam,size_t bam_size,const int *bis,size_t bis_size,bool *vcurr,bool *presibis,bool *presibam,int i,int goloso,int bambini,int* ret) {
	if (i == (int)bis_size && bambini<bam_size) {
		int k = 0;
		for (size_t f = 0; f < bam_size; f++) {
			if (vcurr)
				k++;
		}
		if (*ret < k)
			*ret = k;
		return;
	}
	for (size_t c = 0; c < bis_size; c++) {
		}
}

int AssegnaBiscotti(const int* bam, size_t bam_size, const int* bis, size_t bis_size) {
	bool* vcurr = calloc(bam_size, sizeof(bool));
	bool* presibam = calloc(bam_size, sizeof(bool));
	bool* presibis = calloc(bis_size, sizeof(bool));
	for (size_t h = 0; h < bis_size; h++) {
		presibis[h] = false;
	}
	for (size_t h = 0; h < bam_size; h++) {
		presibam[h] = false;
	}
	int ret = 0;
	BiscottiRec(bam,bam_size,bis,bis_size,vcurr,presibis,presibam,0,0,0,&ret);
	return ret;
}

int main(void) {
	int bam[] = { 10, 20, 30 };
	int bis[] = { 10, 50 };
	int res = AssegnaBiscotti(bam, 3, bis, 2);
	return 0;
}