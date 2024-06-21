#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void CombinaMoneteRec(int b, const int* m, size_t m_size,int* vcurr,int i,int somma_monete,int *nsol) {
	if (i == m_size) {
		if (somma_monete == b) {
			*nsol = *nsol + 1;
			for (size_t f = 0; f < m_size; f++) {
				printf("%d ", vcurr[f]);
			}
			printf("\n");
		}
		return;
	}

	for (int c = 0;c<=b && i<m_size; c++) {
		vcurr[i] =c ;
		if(vcurr[i]!=0)
			somma_monete = somma_monete + m[i];
		if (somma_monete > b) {
			vcurr[i] = 0;
			return;
		}
		CombinaMoneteRec(b,m,m_size,vcurr,i+1,somma_monete,nsol);
	}
}

int CombinaMonete(int b, const int* m, size_t m_size){
	int* vcurr = calloc(m_size,sizeof(int));
	int nsol = 0;
	CombinaMoneteRec(b,m,m_size,vcurr,0,0,&nsol);
	free(vcurr);
	return nsol;
}
//int main() {
//	int m[] = { 1,3,23,5 };
//	size_t m_size = 4;
//	CombinaMonete(4, m, m_size);
//}

