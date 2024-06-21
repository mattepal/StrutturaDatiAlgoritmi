#include "prezzo.h"

void TrovaArticoliRec(const struct Articolo* a,int *vcurr, size_t a_size, int sum,int c,int summp) {
	if (summp==sum) {
		for (int i = 0; i < a_size; i++) {
			if (vcurr[i] == 1)
				printf("%s, ",a[i].nome);
		}
		printf("\n");
		return;
	}
	if (c>=(int)a_size ||summp>sum) {
		return;
	}
	vcurr[c] = 1;
	TrovaArticoliRec(a, vcurr, a_size, sum, c + 1, summp + a[c].prezzo);
	vcurr[c] = 0;
	TrovaArticoliRec(a,vcurr,a_size,sum,c+1,summp);
	
}

void TrovaArticoli(const struct Articolo* a, size_t a_size, int sum)
{
	int* vcurr =calloc(a_size,sizeof(int));
	TrovaArticoliRec(a, vcurr, a_size, sum,0,0);
	free(vcurr);
}

//int main(void) {
//	struct Articolo a[] = { { "Monopoli", 20 }, { "Carcassone", 30 }, { "Perudo", 20 } };
//	TrovaArticoli(a, 3, 50);
//
//	return 0;
//}
