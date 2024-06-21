#include "tree.h"

void TreePreOrderDelete(Node* t) {
	if (TreeIsEmpty(t))
		return;
	printf("%d ", t->value);
	Node* r = TreeRight(t);
	Node* l = TreeLeft(t);
	ElemDelete(t);
	TreePreOrderDelete(l);
	TreePreOrderDelete(r);
}

bool TreeIsMirrorRec(Node* t1, Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return true;
	if (TreeIsEmpty(t1) && !TreeIsEmpty(t2))
		return false;
	if (TreeIsEmpty(t2) && !TreeIsEmpty(t1))
		return false;
	return ElemCompare(TreeGetRootValue(t1), TreeGetRootValue(t2)) == 0 && TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2)) && TreeIsMirrorRec(TreeRight(t1), TreeLeft(t2));
}

bool  TreeIsMirror(Node* t) {
	return TreeIsMirrorRec(TreeLeft(t), TreeRight(t));
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
//	
//		TreePreOrderDelete(t);
//	    TreeDelete(t);
//	    return 0;
//	
//	}