#include "list.h"

//const Item* CommonTail(const Item* i1, const Item* i2) {
//	if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
//		return ListCreateEmpty();
//	}
//	const Item* i1c = i1;
//	const Item* i2c = i2;
//	while (!ListIsEmpty(i1c)) {
//		i2c = i2;
//		while (!ListIsEmpty(i2c)) {
//			if (ElemCompare(&i1c->value , &i2c->value)) {
//				return i1c;
//			}
//			else if (i1c->next == i2c->next) {
//				return ListGetTail(i1c);
//			}
//			i2c = ListGetTail(i2c);
//		}
//		i1c = ListGetTail(i1c);
//	}
//	return ListCreateEmpty();
//}
const Item* CommonTail(const Item* i1, const Item* i2) {
	//If one is empty return an empty list
	if (ListIsEmpty(i1) || ListIsEmpty(i2)) {
		return ListCreateEmpty();
	}
	const Item* i1_copy = i1;
	const Item* i2_copy = i2;
	//For every element of the first list
	while (!ListIsEmpty(i1_copy)) {
		const Item* i2_copy = i2;
		//For every element of the second list
		while (!ListIsEmpty(i2_copy)) {
			//If the address of the first list is the same as the second
			//Return the remaining list
			if (&i1_copy->value == &i2_copy->value) {
				return i1_copy;
			}
			//If the next element of the list has the same address, return it
			if (i1_copy->next == i2_copy->next) {
				return ListGetTail(i1_copy);
			}
			//Check for the next element in i2
			i2_copy = ListGetTail(i2_copy);
		}
		//Check for the next element in i1
		i1_copy = ListGetTail(i1_copy);
	}
	//If no common tail is found
	return ListCreateEmpty();
}