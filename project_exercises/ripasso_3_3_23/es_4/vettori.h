#define NO_SECURE_WARNINGS_CRT
#if !defined VETTORI_H
#define VETTORI_H

#include <string.h>
#include <stdlib.h>

struct vettore {
    int* data;
    size_t size;
};
 void Push(struct vettore* v, int d);
 int Pop(struct vettore* v);

#endif