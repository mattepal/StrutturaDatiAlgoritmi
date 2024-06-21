#define _NO_CRT_SECURE_WARNINGS
#if !defined NEXT_GREATER_H
#define NEXT_GREATER_H

#include "list.h"
#include <limits.h>
#include <stdlib.h>

ElemType* NextGreater(const Item* list, size_t* answer_size);


#endif // !defined NEXT_GREATER_H
