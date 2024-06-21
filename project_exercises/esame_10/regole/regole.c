#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printff(int *fine,size_t lung) {
	for (size_t k = 0; k < lung; k++) {
		printf("%d", fine[k]);
	}
	printf("\n");
}
void RegoleRec(const char* r,int *vcurr,size_t lung,int i,int m) {
	int cont = 0;
	if (i == lung) {
		printff(vcurr,lung);
	}

					RegoleRec(r, vcurr, fine, lung, i + 1, m + 1);

				}
			}
		}
	}
}
void Regole(const char* r) {
	if (strcmp(r, "") == 0) {
		printf("1");
		return;
	}
	int i = 0, m = 0;
	size_t lung = strlen(r) + 1;
	int* vcurr = calloc(lung, sizeof(int));
	RegoleRec(r, vcurr,lung, i, m);
	free(vcurr);
	return;
}
int main() {
	char r[] = "DI";
	Regole(r);
}
