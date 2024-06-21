#include <stdlib.h>
#include <stdio.h>

int TempoTrasportoRec(int n, const int* t, int p, int cont,int *vett) {
	
	if (vett[n-1] == p) {
		return cont;
	}
	for (int o = n-2; o >=0;o--) {
		if (vett[o] != 0) {
			if (t[o] > vett[o]) {
				if (o + 1 < n) {
					vett[o + 1] += vett[o]; 
				}
				vett[o] = 0;
			}
			else if (t[o]<=vett[o]) {
				if (o + 1 < n) { 
					vett[o + 1] += t[o];
				}
				vett[o] =vett[o]-t[o];
			}
		
		}
	}
	return TempoTrasportoRec(n, t, p, cont+1, vett);
}

int TempoTrasporto(int n, const int* t, int p) {
	int cont = 0;
	int* vett = calloc(n,sizeof(int));
	vett[0] = p;
	int c= TempoTrasportoRec(n, t, p, cont,vett);
	free(vett);
	return c;
}
//int main(void) {
//	int t[] = { 3,2,4 };
//
//	printf("Tempo: %d", TempoTrasporto(4, t, 5));
//}