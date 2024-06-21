#include "tree.h"

void LevelSumRec(const Node* t, size_t level, size_t l,int* somm) {
	if (TreeIsEmpty(t)) {
		return;
	}
	if (level == l) {
		*somm += t->value;
		return;
	}
	LevelSumRec(TreeLeft(t), level, l + 1, somm);
	LevelSumRec(TreeRight(t), level, l + 1, somm);
}

int LevelSum(const Node* t, size_t level) {
	if (TreeIsEmpty(t))
		return 0;
	if (level == 0)
		return t->value;
	size_t l = 0;
	int somm = 0;
	LevelSumRec(t,level,l,&somm);
	return somm;
}