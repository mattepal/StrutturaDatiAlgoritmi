
#include "list.h"

Item* Diff(const Item* i1, const Item* i2) {
	Item* L = ListCreateEmpty();
	int found = 0;
	for (const Item* tmp1 = i1; !ListIsEmpty(tmp1);tmp1=ListGetTail(tmp1)) {
		for (const Item * tmp2 = i2; !ListIsEmpty(tmp2);tmp2=ListGetTail(tmp2)) {
			if (ElemCompare(ListGetHeadValue(tmp1),ListGetHeadValue(tmp2)) == 0) {
				found = 1;
				break;
			}
		}
		if (found == 0) {
			L = ListInsertBack(L, ListGetHeadValue(tmp1));
		}
		found = 0;
	}
	return L;
}
//void main() {
//	    ElemType e1[] = { 3, 4, 2, 0, 45, 1, 3 };
//	    size_t e1_size = sizeof(e1)/sizeof(ElemType);
//	
//	    Item *l1 = ListCreateEmpty();
//	    for(size_t i = 0; i < e1_size; ++i){
//	        l1= ListInsertBack(l1, e1 + i);
//	    }
//	
//	    ElemType e2[] = { 8, 5, 2, 3, 45, };
//	    size_t e2_size = sizeof(e1) / sizeof(ElemType);
//	
//	    Item *l2 = ListCreateEmpty();
//	    for (size_t i = 0; i < e2_size; ++i) {
//	        l2 = ListInsertBack(l2, e2 + i);
//	    }
//	    
//	    Item *ris = Diff(l1, l2);
//	
//	    ListDelete(l1);
//	    ListDelete(l2);
//	    ListDelete(ris);
//		return 0;
//}