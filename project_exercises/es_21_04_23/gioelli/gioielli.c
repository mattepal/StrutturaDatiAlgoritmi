#include "gioielli.h"

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size)
{
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	if (budget <= 0) {
		fclose(f);
		return NULL;
		
	}

	int code = 0;
	float prezzo = 0;
	float peso = 0;
	int cont = 0;
	Gioiello* vett = calloc(1, sizeof(Gioiello));
	Gioiello* bestg = calloc(1, sizeof(Gioiello));
	while (1) {
		if (fscanf(f, "%d%f%f\n", &code, &peso, &prezzo)!=3) {
			break;
		}
		vett[cont].codice = code;
		vett[cont].peso = peso;
		vett[cont].prezzo = prezzo;
		cont++;
		vett = realloc(vett, (cont + 1)* sizeof(Gioiello));
	}
	vett = realloc(vett, cont * sizeof(Gioiello));

	
	float rimasti = budget;
	float rpp = 0;
	int best;
	for (int i = 0; i < cont; i++) {
		rpp = vett[i].peso / vett[i].prezzo;
		for (int u =0 ; u < cont; u++) {
			if (rpp < (vett[u].peso / vett[u].prezzo) && rimasti-vett[u].prezzo>=0) {
				rpp = vett[u].peso / vett[u].prezzo;
				best = vett[u].codice;
			}
		}
		rimasti = rimasti - vett[best-1].prezzo;
		if (rimasti < 0)
			break;
		bestg[i] = vett[best - 1];
		vett[best-1].peso =1000;
		*ret_size += 1;
		bestg = realloc(bestg, (*ret_size + 1) * sizeof(Gioiello));
	}
	bestg = realloc(bestg, (*ret_size) * sizeof(Gioiello));
	free(vett);
	fclose(f);
	return bestg;
}
//int main(void) {
//	size_t ret_size=0;
//	Gioiello* sol = CompraGioielli("gioielli_1.txt", 121, &ret_size);
//	return 0;
//}