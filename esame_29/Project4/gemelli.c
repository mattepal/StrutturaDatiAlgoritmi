#include "tree.h"

bool TreesAreTwinsRec(const	Node* t1, const	Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return true;
	else if (TreeIsEmpty(t1) && !TreeIsEmpty(t2))
		return false;
	else if (TreeIsEmpty(t2) && !TreeIsEmpty(t1))
		return false;
	return TreesAreTwinsRec(TreeRight(t1), TreeRight(t2)) && TreesAreTwinsRec(TreeLeft(t1), TreeLeft(t2));
}

bool TreesAreTwins(const Node* t1, const Node* t2) {
	if (TreeIsEmpty(t1) && TreeIsEmpty(t2))
		return true;
	return TreesAreTwinsRec(t1, t2);
}
