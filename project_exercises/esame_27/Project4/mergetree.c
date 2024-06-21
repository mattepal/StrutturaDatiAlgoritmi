#include "tree.h"

Node* TreeCopy(const Node* t) {
	if (TreeIsEmpty(t)) {
		return NULL;
	}
	Node* n = TreeCreateRoot(TreeGetRootValue(t), NULL, NULL);
	n->left = TreeCopy(TreeLeft(t));
	n->right = TreeCopy(TreeRight(t));
	return n;
}

Node* MergeTree(const Node* t1, const Node* t2) {
	Node* ret = TreeCreateEmpty();
	ElemType node = 0;
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return ret;
	else if (TreeIsEmpty(t1)) {
		ret=TreeCopy(t2);
		return ret;
	}
	else if (TreeIsEmpty(t2)) {
		ret = TreeCopy(t1);
		return ret;
	}
	else {
		node = t1->value + t2->value;
		TreeCreateRoot(&node,MergeTree(TreeLeft(t1),TreeLeft(t2)), MergeTree(TreeRight(t1), TreeRight(t2)));
	}
	return ret;
}

//int main(void) {
//	    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
//
//	    Node* t = TreeCreateRoot(e + 15,
//	        TreeCreateRoot(e + 10,
//	            TreeCreateRoot(e + 3, NULL, NULL),
//	            TreeCreateRoot(e + 12, NULL, NULL)),
//	        TreeCreateRoot(e + 21, NULL, TreeCreateRoot(e+6,NULL,NULL)));
//		Node* t1 = TreeCreateRoot(e + 5,
//			TreeCreateRoot(e + 0,
//				TreeCreateRoot(e + 3, TreeCreateRoot(e+3,NULL,NULL), NULL),
//				TreeCreateRoot(e + 12, NULL, NULL)),
//			TreeCreateRoot(e + 21, NULL, NULL));
//		MergeTree(t, t1);
//	    TreeDelete(t);
//		TreeDelete(t1);
//	    return 0;
//	
//	}
