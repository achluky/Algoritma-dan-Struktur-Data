/* Program PakaiStack */
/* Membuat sebuah stack ukuran N > 0, lalu membaca 50 integer dari keyboard */
/* Menuliskan ulang isi stack dari top ke bottom */

#include "boolean.h"
#include "stack.h"
#include <stdio.h>


int main () {
	/* Kamus */
	Stack S;
	int N, i;
	infotype X;
	
	/* Algoritma */
	/* Membaca N dan membentuk stack ukuran N */
	scanf("%d",&N);
	CreateEmpty(&S,N);
	
	/* Baca 50 elemen. Jika N < 50, sisa integer diabaikan */
	/* Nilai 50 dapat diganti dengan nilai yang lebih kecil untuk testing program */
	for (i = 1; i <= 10; i++) {
		scanf("%d",&X);
		/* Nilai 50 dapat diganti dengan nilai yang lebih kecil untuk testing program */
		if(i>10-N){
			Push(&S,X);
		}
	}
	
	/* Mencetak isi S dari top ke bottom */
	/* Pakai do-while karena S pasti tidak kosong */
	printf("=======\n");
	
	do {
		Pop(&S,&X);
		printf("%d\n", X);
	} while (!IsEmpty(S));
	
	return 0;
}
