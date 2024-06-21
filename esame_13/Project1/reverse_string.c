#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void* ReverseStringRec(const char *str,char *string,int i,size_t len) {
	if (i==(int)strlen(str))
		return ;
	string[len] = str[i];
	ReverseStringRec(str, string, i+1,len-1);
	return ;
}

char* ReverseString(const char* str) {
	if (str == NULL)
		return NULL;
	size_t len = strlen(str) - 1;
	char* string = calloc(len+1, sizeof(int));
	ReverseStringRec(str,string,0,len);
	return string;
}

//int main() {
//	ReverseString("cane");
//	return 0;
//}
//
