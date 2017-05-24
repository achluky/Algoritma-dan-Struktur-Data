/*	File Include */
#include "queue.h"
#include "boolean.h"
#include <stdio.h>
#include <stdlib.h>

int main () {
  	int pil;
	Queue Q;
	infotype X;
	infotype N; // Ukuran Queue
	printf("  1. Create Empty\n  2. Is Empty\n  3. Is Full\n  4. NBElmt\n  5. DeAlokasi\n  6. Add\n  7. Del\n  8. PrintInfo\n  9. Exit\n 10. Search\n ");
	while (1) {
		printf("Pilih: ");
		scanf("%d",&pil);
		switch (pil) {
		  case 1: { // CreateEmpty
			printf("Ukuran Queue: ");
			scanf("%f",&N);
			CreateEmpty(&Q,N);
		    break;
		  }
		  case 2: { // IsEmpty
			printf("Is Empty: %d\n",IsEmpty(Q));
		    break;
		  }
		  case 3: { // IsFull
			printf("Is Full: %d\n",IsFull(Q));
		    break;
		  }
		  case 4: { // NBElmt
			printf("Jumlah elemen tersisa: %d\n",NBElmt(Q));
		    break;
		  }
		  case 5: { // DeAlokasi
			DeAlokasi(&Q);
		    break;
		  }
		  case 6: { // Add
		  	printf("Masukan Nilai:");
			scanf("%f",&X);
			Add(&Q,X);
		  	break;
		  }
		  case 7:{ // Del
			Del(&Q,&X);
			break;
		  }
		  case 8:{ // PrintInfo
		  	PrintInfo(&Q);
			break;
		  }
		  case 9:{ // Exit
		  	exit(0);
		  }
		  case 10:{ // Search
		  	printf("Masukan Nilai yang akan dicari:");
			scanf("%f",&X);
			if(Search(&Q,X)){
				printf("Ditemukan\n");
			} else {
				printf("Tidak ditemukan\n");
			}
		  }
		}
	}
	return 0;
}
