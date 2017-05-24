#include "b-tree.h"
#include <stdio.h>
#include <stdlib.h>

void CetakPohonBST(BinTree T){
/*  
    T adalah alamat root pohon pencarian biner. 
    T mungkin kosong. Setelah mengerjakan fungsi ini, semua informasi di dalam pohon 
    T tercetak dalam urutan menaik 
    T inorder
*/

    /* Algoritma */
	printf("(");
	if (IsTreeEmpty(P)) { /* Basis-0 */
		/* do nothing */
	} else {              /* Rekurens */
		PrintInorder(Left(P));
		printf("%d",Akar(P));
		PrintInorder(Right(P));
	}
	printf(")");

}