#include "tree.h"

Node* BstInsert(const ElemType* e, Node* n) {
    return;
}
Node* BstInsertRec(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		TreeCreateRoot(e, NULL, NULL);
	}
	if (ElemCompare(e, TreeGetRootValue(n)) <= 0) {
		n->left = BstInsert(e, TreeLeft(n));
	}
	else {
		n->right = BstInsertRec(e, TreeRight(n));
	}
	return n;
}

int CountDominant(const Node* t){
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

//int main(void) {
//    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
//
//    //      15
//    //     /  \
//    //    10   21
//    //   / \    
//    //  3  12  
//
//    Node* t = TreeCreateRoot(e + 15,
//        TreeCreateRoot(e + 4,
//            TreeCreateRoot(e + 3, NULL, NULL),
//            TreeCreateRoot(e + 12, NULL, NULL)),
//        TreeCreateRoot(e + 6, NULL, NULL));
//
//    int i = CountDominant(t);
//
//    // Dopo l'inserimento dei valori 22 e 21 otteniamo l'albero seguente:
//    //      15
//    //      / \
//    //     /   \
//    //    10   21
//    //   / \   / \
//    //  3  12 21 22
//
//   /* const ElemType* res = TreeMaxV2(t);*/
//    TreeDelete(t);
//    return i;
//
//}