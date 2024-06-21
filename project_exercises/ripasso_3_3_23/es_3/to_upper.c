#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ToUpper(char* str) {
	if (str == NULL) {
		return;
	}
	size_t lung = strlen(str);
	for (size_t i = 0; i < lung; i++) {
		if (*(str + i) >= 97 && *(str + i) <= 122) {
			*(str + i) = *(str + i) - 32;
		}
	}
}