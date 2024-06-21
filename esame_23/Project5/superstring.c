#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

static char* Overlap(const char* str1, const char* str2, int* overlapping) {
    const int len1 = (int)strlen(str1);
    const int len2 = (int)strlen(str2);
    const int lenShort = len1 < len2 ? len1 : len2;
    const int lenLong = len1 < len2 ? len2 : len1;
    const char* strShort = len1 < len2 ? str1 : str2;
    const char* strLong = len1 < len2 ? str2 : str1;
    // Check if strShort is a substring of strLong
    if (strstr(strLong, strShort) != NULL) {
        char* res = malloc(lenLong + 1);
        strcpy(res, strLong);
        *overlapping = lenShort;
        return res;
    }
    int maxOverlap = 0;
    bool longGoesFirst = true;
    // Try to put strShort at the end of strLong
    for (int i = lenShort - 1; i > 0; --i) {
        if (strncmp(strLong + lenLong - i, strShort, i) == 0) {
            maxOverlap = i;
            break;
        }
    }
    // Try to put strLong and the end of strShort
    for (int i = lenShort - 1; i > maxOverlap; --i) {
        if (strncmp(strLong, strShort + lenShort - i, i) == 0) {
            if (i > maxOverlap) {
                maxOverlap = i;
                longGoesFirst = false;
            }
            break;
        }
    }
    char* res = malloc(lenLong + lenShort - maxOverlap + 1);
    if (longGoesFirst) {
        strcpy(res, strLong);
        strcpy(res + lenLong, strShort + maxOverlap);
    }
    else {
        strcpy(res, strShort);
        strcpy(res + lenShort, strLong + maxOverlap);
    }
    *overlapping = maxOverlap;
    return res;
}

void solveRec(const char **v, char* vbest,char*vcurr,size_t v_size,int str1,int str2,int o,int over,bool *used) {
    int overlap = 0;
    if (o == v_size) {
        return;
    }
    for (size_t i = 0; i < v_size; i++) {
        if (used[i])
            break;
        for (size_t c = i+1; c < v_size; c++) {
            if (used[c]) {
                break;
            }
            vcurr = Overlap(v[i], v[c], &overlap);
            if (overlap >= over) {
                over = overlap;
                str1 = i;
                str2 = c;
                vbest = vcurr;
            }
        }
    }
    used[str1] = true;
    used[str2] = true;
    solveRec(v, vbest, vcurr, v_size, 0, 0, o + 1, 0, used);
}

char* SolveSuperstring(const char** v, size_t v_size) {
    char* vcurr = calloc(1, sizeof(char));
    bool* used = calloc(v_size, sizeof(bool));
    char* vbest = calloc(1, sizeof(char));
    solveRec(v, vbest,vcurr, v_size, 0, 0, 0,0,used);
    free(vcurr);
    free(used);
    return vbest;
}
int main(void) {
    char** a = calloc(3, sizeof(char));
    a[0] = calloc(20, 1);
    a[1] = calloc(20, 1);
    a[2] = calloc(20, 1);

    a[0] = "FEDERICO";
    a[1] = "MAURIZIO";
    a[2] = "GIANPAOLO";
    char* res = SolveSuperstring(a, 3);
    printf("%s", res);
    free(res);
    return 0;
}