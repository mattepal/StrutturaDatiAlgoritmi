#include "vettori.h"

void Push(struct vettore* v, int d)
{
	v->size + 1;
	v->data = realloc(v->data, v->size*sizeof(int));
	v->data[v->size-1] = d;
}

int Pop(struct vettore* v)
{
	return 0;
}

int main() {
	struct vettore s = { NULL,0 };
	Push(&s,4);
	Push(&s, 2);
	Push(&s, 1);
	return 0;
}
