//
//#include <stdlib.h>
//#include <stdbool.h>
//
//void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, unsigned int i, bool* vcurr, bool* vbest, int* max, int cnt, int sum) {
//	if (i == pacchi) {
//		for (int c = 0; c < pacchi; c++) {
//			if (vcurr[c] == true) {
//				cnt = cnt +(pacchi_size+c);
//			}
//		}
//		if (cnt > max) {
//			for (int b = 0; b < pacchi; b++) {
//				vbest[b] = vcurr[b];
//			}
//			max = cnt;
//		}
//		return;
//	}
//	for (int e = i; e < pacchi; e++) {
//		vcurr[e] = true;
//		BabboNataleRec(pacchi,pacchi_size,p,i+1,vcurr,vbest,max,cnt,sum);
//		vcurr[e] = false;
//	}
//}
//
//void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
//
//	bool* vcurr = calloc(pacchi, sizeof(bool));
//	bool* vbest = calloc(pacchi, sizeof(bool));
//		BabboNataleRec(pacchi, pacchi_size, p, 0, vcurr, vbest, 0, 0, 0);
//	
//}