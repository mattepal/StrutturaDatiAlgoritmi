#include "list.h"

#include <stdlib.h>

//extern Item *Intersect(const Item *i1, const Item *i2);
//
//int main(void){
//    ElemType e1[] = { 3, 4, 2, 0, 45, 1, 3 };
//    size_t e1_size = sizeof(e1)/sizeof(ElemType);
//
//    Item *l1 = ListCreateEmpty();
//    for(size_t i = 0; i < e1_size; ++i){
//        l1= ListInsertBack(l1, e1 + i);
//    }
//
//    ElemType e2[] = { 8, 5, 2, 3, 45, };
//    size_t e2_size = sizeof(e1) / sizeof(ElemType);
//
//    Item *l2 = ListCreateEmpty();
//    for (size_t i = 0; i < e2_size; ++i) {
//        l2 = ListInsertBack(l2, e2 + i);
//    }
//    
//    Item *ris = Intersect(l1, l2);
//
//    ListDelete(l1);
//    ListDelete(l2);
//    ListDelete(ris);
//
//    return 0;
//}