#include "tree.h"

int CountDominant(const Node* t) {
	if (TreeIsLeaf(t))
		return;
	int cont = 0;
	ElemType som = *TreeGetRootValue(t->right) + *TreeGetRootValue(t->left);
	if (ElemCompare(TreeGetRootValue(t), &som) > 0)
		cont += 1;
	CountDominant(t->left);
	CountDominant(t->right);
	return cont;
}

