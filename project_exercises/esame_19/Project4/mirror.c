#include "tree.h"

bool TreeIsMirrorRec(Node* t1,Node *t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	else if (TreeIsEmpty(t2) && !TreeIsEmpty(t1))
		return false;
	else if (TreeIsEmpty(t1) && !TreeIsEmpty(t2))
		return false;
	return ElemCompare(&t1->value, &t2->value) == 0 && TreeIsMirrorRec(TreeLeft(t1), TreeRight(t2)) && TreeIsMirrorRec(TreeLeft(t2), TreeRight(t1));
}

bool TreeIsMirror(Node* t) {
	if (TreeIsEmpty(t))
		return true;
	if (TreeIsLeaf(t))
		return true;
	return TreeIsMirrorRec(TreeRight(t), TreeLeft(t));
}
 /*                               ( 0)                                            
                  +--------------+----------------+                             
                ( 1)                            ( 1)                            
      +----------+--------+               +------+------------+                 
    ( 3)                ( 4)            ( 4)                ( 3)                
  +--+--------+       +--+----+       +--+----+       +------+----+             
( 5)        ( 6)    ( 7)    ( 8)    ( 8)    ( 7)    ( 6)        ( 5)            
          +---+                                      +----+                     
        ( 9)                                           ( 9)  */                   
//int main(void) {
//	    ElemType e[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22 };
//	
//	    //      15
//	    //     /  \
//	    //    10   21
//	    //   / \    
//	    //  3  12  
//	
//		Node* t = TreeCreateRoot(e,
//			TreeCreateRoot(e + 1,
//				TreeCreateRoot(e + 3, TreeCreateRoot(e + 5, NULL, NULL), TreeCreateRoot(e + 6, TreeCreateRoot(e + 9, NULL, NULL), NULL)),
//				TreeCreateRoot(e + 4, NULL, NULL)),
//			TreeCreateRoot(e + 1, TreeCreateRoot(e + 4, NULL, NULL), TreeCreateRoot(e + 3, TreeCreateRoot(e + 6, TreeCreateRoot(e + 9, NULL,NULL), TreeCreateRoot(e+5,NULL,NULL)), NULL)));
//		bool c=TreeIsMirror(t);
//	    TreeDelete(t);
//	    return 0;
//	
//	}
