#include "tree.h"

bool Target(Node *t,ElemType i,const ElemType *target ) {
	if (TreeIsLeaf(t)) {
		i = i + t->value;
		if (ElemCompare(&i, target) == 0)
			return true;
		else
			return false;
	}
	i = i + t->value;
	bool ret1,ret2;
	if (!TreeIsEmpty(t->right))
		ret1=Target(TreeRight(t), i, target);
	if(!TreeIsEmpty(t->left))
		ret2=Target(TreeLeft(t), i, target);
	return ret1 || ret2;
	}



bool PercorsoSomma(Node* t, const ElemType* target) {
	if (TreeIsEmpty(t))
		return false;
	return Target(t, 0, target);
}
//int main(void) {
//	    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
//	
//	          15
//	         /  \
//	        10   21
//	       / \    
//	       3  12  
//	
//	    Node* t = TreeCreateRoot(e + 15,
//	        TreeCreateRoot(e + 10,
//	            TreeCreateRoot(e + 3, NULL, NULL),
//	            TreeCreateRoot(e + 12, NULL, NULL)),
//	        TreeCreateRoot(e + 21, NULL, NULL));
//		ElemType ta = 36;
//		PercorsoSomma(t,&ta );
//	
//	    TreeDelete(t);
//	    return 0;
//	
//	}
