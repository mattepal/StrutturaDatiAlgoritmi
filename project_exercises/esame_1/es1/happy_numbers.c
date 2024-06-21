#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int estrai(int numero) {
	int tmp = 0;
	do  {
		tmp = tmp + pow((numero % 10), 2);
		numero = numero / 10;

	}while (numero > 0);
	return tmp;
}

void rec(int numero) {
	if (numero == 0 || numero == 4) {
		printf("Infelice");
		return;
	}
	if (numero == 1) {
		printf("Felice");
		return;
	}
	numero=estrai(numero);
	rec(numero);

}

int main(int argc,char *argv[]) {
	int numero = atoi(argv[1]);
	if (argc != 2 ||numero<0)
		return 1;
	rec(numero);
	return 0;
}