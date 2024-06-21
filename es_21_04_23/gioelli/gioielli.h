#define _CRT_SECURE_NO_WARNINGS
#if !defined GIOIELLI_H
#define GIOIELLI_H

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int codice;
    float peso;
    float prezzo;
} Gioiello;

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size);

#endif // !defined GIOIELLI_H
