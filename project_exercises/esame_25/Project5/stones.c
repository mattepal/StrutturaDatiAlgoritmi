#define _NO_CRT_SECURE_WARNINGS

#include "maxheap.h"
#include <stdlib.h>

void Pop(Heap* h, ElemType* popped) {
    if (h->size == 0) {
        popped = NULL;
        return;
    }
    *popped = ElemCopy(&h->data[0]);
    ElemSwap(&h->data[0], &h->data[h->size - 1]);
    h->size--;
    h->data = realloc(h->data, sizeof(ElemType) * h->size);
    HeapMaxMoveDown(h, 0);
    return;
}


int LastStoneWeight(Heap* h) {
    ElemType y;
    ElemType x;
    while (h->size >= 2) {
        Pop(h, &y);
        Pop(h, &x);
        y = y - x;
        HeapMaxInsertNode(h, &y);
    }
    if (h->size == 0)
        return 0;
    else
        return h->data[0];
}

//extern int LastStoneWeight(Heap* h);
//int main(void) {
//    Heap* h = HeapCreateEmpty();
//    ElemType x = 77;
//    HeapMaxInsertNode(h, &x);
//    x = 21;
//    HeapMaxInsertNode(h, &x);
//    x = 18;
//    HeapMaxInsertNode(h, &x);
//    HeapWriteStdout(h);
//    printf("%d", LastStoneWeight(h));
//    return 0;
//}