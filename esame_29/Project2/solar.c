#include <stdlib.h>
#include <math.h>

int* SolarCut(int A, size_t* sol_size) {
	int size = 0,nu=0;
	int *pannello = calloc(1,sizeof(int));
	while (A >0) {
		nu = (int)pow((int)sqrt(A), 2);
		pannello[size] =nu ;
		A = A - nu;
		size++;
		pannello = realloc(pannello, (size+1) * sizeof(int));
	}
	*sol_size = size;
	pannello = realloc(pannello, (size ) * sizeof(int));
	return pannello;
}	
//int main(){
//	size_t solsize = 0;
//	SolarCut(12,&solsize);
//	return 1;
//}