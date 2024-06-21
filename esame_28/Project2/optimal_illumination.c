#include <stdbool.h>
#include <stdlib.h>

bool illuminato(int M, int R, const int* light, bool* vcurr) {



}

void OptimalIlluminatioRec(int M, int R, const int* light, size_t light_size,bool *vcurr,bool *vbest,int i) {
	if (illuminato(M,R,light,light_size,vcurr)) {}

}

bool* OptimalIllumination(int M, int R, const int* light, size_t light_size) {
	bool* vcurr = calloc(light_size,sizeof(bool));
	bool* vbest = calloc(light_size, sizeof(bool));

	OptimalIlluminatioRec( M, R, light, light_size, vcurr,vbest,0);
}