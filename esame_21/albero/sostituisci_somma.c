#include "tree.h"

int SostituisciSommaRec(Node* t) {
	while (!TreeIsEmpty(t)) {
		if (TreeIsLeaf(t)) {
			return t->value;
		}
		else {
			t->value =t->value+ SostituisciSommaRec(TreeLeft(t)) + SostituisciSommaRec(TreeRight(t));
			return t->value;
		}
	}
}

void SostituisciSomma(Node* t) {

	t=SostituisciSommaRec(t);
}