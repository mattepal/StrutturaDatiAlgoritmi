#include "tree.h"
#include <limits.h>

void MaxNode(const Node *t,ElemType *max) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (ElemCompare(&t->value, max) > 0) {
		*max = t->value;
	}
	MaxNode(TreeRight(t),max);
	MaxNode(TreeLeft(t),max);
}

void SuccessoreRec(const Node *t,const Node *n,Node *ret,bool *trovato) {
	if (TreeIsEmpty(t))
		return;
	if (ElemCompare(&t->value, &n->value) > 0 && ElemCompare(&t->value, &ret->value) <= 0) {
		*ret = *t;
		*trovato = true;
	}
	SuccessoreRec(TreeRight(t), n, ret,trovato);
	SuccessoreRec(TreeLeft(t), n, ret,trovato);
	return;
}

const Node* Successore(const Node* t, const Node* n) {
	if (TreeIsEmpty(t))
		return NULL;
	ElemType max = t->value;
	MaxNode(t, &max);
	Node* ret = TreeCreateRoot(&max, NULL, NULL);
	bool trovato = false;
	SuccessoreRec(t, n,ret,&trovato);
	if (!trovato) {
		return NULL;
	}
	return ret;
}


