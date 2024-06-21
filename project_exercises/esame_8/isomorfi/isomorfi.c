#include "tree.h"

bool isomorfirec(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2)) {
		return true;
	}
	if ((!TreeIsEmpty(t1) && TreeIsEmpty(t2)) || (TreeIsEmpty(t1) && !TreeIsEmpty(t2))) {
		return false;
	}
	else
	{
		if (ElemCompare(TreeGetRootValue(t1),TreeGetRootValue(t2))==0)
			return (isomorfirec(TreeLeft(t1), TreeLeft(t2)) && isomorfirec(TreeRight(t1), TreeRight(t2))) || (isomorfirec(TreeLeft(t1), TreeRight(t2)) && isomorfirec(TreeRight(t1), TreeLeft(t2)));
		else return false;
	}

}

bool Isomorfi(const Node* t1, const Node* t2) {
	return isomorfirec(t1,t2);
	
}
