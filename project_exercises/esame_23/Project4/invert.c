#include "tree.h"

void* invertirec(Node* t) {
	if (TreeIsEmpty(t)) {
		return;
	}
	Node* tl = TreeLeft(t);
	Node* tr = TreeRight(t);
	t->left = tr;
	t->right = tl;
	invertirec(tl);
	invertirec(tr);
}

Node* Invert(Node* t) {
	if (TreeIsEmpty(t)) {
		return TreeCreateEmpty();
	}
	invertirec(t);
	return t;
}
//int main(void) {
//	    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
//	
//	    //      15
//	    //     /  \
//	    //    10   21
//	    //   / \    
//	    //  3  12  
//	
//	    Node* t = TreeCreateRoot(e + 15,
//	        TreeCreateRoot(e + 10,
//	            TreeCreateRoot(e + 3, NULL, NULL),
//	            TreeCreateRoot(e + 12, NULL, NULL)),
//	        TreeCreateRoot(e + 21, NULL, NULL));
//		Invert(t);
//	
//	    TreeDelete(t);
//	    return 0;
//	
//	}