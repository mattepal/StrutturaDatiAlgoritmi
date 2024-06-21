#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void PasswordRec(const char* str, int n,char *vcurr,int i,int *nsol) {
	if (i == n) {
		*nsol = *nsol + 1;
		for (int z = 0; z < n; z++) {
			printf("%c", vcurr[z]);
		}
		printf("\n");
		return;
	}
	for (int c = 0; c < (int)strlen(str); c++) {
		vcurr[i] = str[c];
		PasswordRec(str, n, vcurr, i + 1, nsol);
	}
}

int Password(const char* str, int n) {
	if (str == NULL || n<0) {
		return 0;
	}
	char* vcurr = calloc(n,sizeof(char));
	int nsol = 0;
	PasswordRec(str,n,vcurr,0,&nsol);
	free(vcurr);
	return nsol;
}

//int main() {
//	
//	Password("a1", 1);
//	return 0;
//}