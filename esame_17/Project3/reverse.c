#include "list.h"

Item* Reverse(Item* i) {
    Item* tmp = i;
    Item* fine = NULL;
    Item* next = NULL;
    while (!ListIsEmpty(tmp)) {
        next = tmp->next;
        tmp->next = fine;
        fine = tmp;
        tmp = next;
    }

    return fine;
}
//Item* ListCreateFromVector(const int* v, size_t v_size) {
//    Item* list = ListCreateEmpty();
//    for (size_t i = 0; i < v_size; ++i) {
//        list = ListInsertBack(list, &v[i]);
//    }
//    return list;
//}
//int main(void) {
//    int v[] = { 1,3,4,7,8 };
//    size_t v_size = sizeof(v) / sizeof(int);
//    Item* list = ListCreateFromVector(v, v_size);
//    ListWriteStdout(list);
//    list = Reverse(list);
//    ListWriteStdout(list);
//    ListDelete(list);
//
//    return 0;
//}