#define _CRT_SECURE_NO_WARNINGS
#if !defined VETTORE_H
#define VETTORE_H

#include <stdlib.h>
#include "elemtype.h"
#include <stdio.h>
#include <string.h>

typedef struct {
    size_t capacity;
    size_t size;
    ElemType* data;
} Vector;

Vector* VectorRead(const char* filename);
Vector* VectorReadSorted(const char* filename);
void vectorpush(Vector* v, const ElemType e);
void vectorpush2(Vector* v,  ElemType e);
void vectorpush3(Vector* v, ElemType e);
void selectionsort(Vector* v);

#endif // !defined VETTORE_H
