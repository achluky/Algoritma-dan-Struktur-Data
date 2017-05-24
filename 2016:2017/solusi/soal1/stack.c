/*	Modul ADT STACK - Dimamis */
/*	Deklarasi stack yang diimplementasi dengan tabel kontigu alokasi statik dan ukuran sama dengan TOP adalah alamat elemen puncak. */
/*	FILE INCLUDE */

#include "boolean.h"
#include "stack.h"

/*	Definisi stack S kosong : S.TOP = Nil
		Elemen yang dipakai menyimpan nilai Stack T[1]..T[MaxEl]
		Jika S adalah Stack maka akses elemen :
		S.T[(S.TOP)] untuk mengakses elemen TOP
		S.TOP adalah alamat elemen TOP
		Definisi akses dengan Selektor : Isilah dengan selektor yang tepat */

/*	----- Prototype ----- */
/*	Konstruktor/Kreator */
void CreateEmpty (Stack *S, int Size)
/* I.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosong berkapasitas Size */
/* jadi indeksnya antara 1.. Size+1 karena 0 tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
{  /* Kamus Lokal */
   /* Algoritma */  
   (*S).T = (infotype *) malloc (Size * sizeof(infotype));
   if ((*S).T != NULL) {
      Top(*S) = Nil;
      Size(*S) = Size;
   } else { /* Alokasi gagal */
      Size(*S) = 0; 
   }
}

/* Destruktor */
void Destruct (Stack *S)
/* destruktor: dealokasi seluruh tabel memori sekaligus  */
{  /* Kamus Lokal */
   /* Algoritma */
   free((*S).T);
   Size(*S) = 0;
}


/*	----- Predikat Untuk test keadaan KOLEKSI ----- */
boolean IsEmpty (Stack S)
/* Mengirim true jika Stack kosong: lihat definisi di atas */
{  /* Kamus Lokal */

   /* Algoritma */
   return (Top(S)==Nil);
}

boolean IsFull(Stack S)
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
{  /* Kamus Lokal */

   /* Algoritma */
   return(Top(S)==Size(S));
}

/*	----- Operator Dasar Stack ----- */
void Push (Stack *S, infotype X) {
	/*	Menambahkan X sebagai elemen Stack S.
			I.S.	: S mungkin kosong, tabel penampung elemen stack TIDAK penuh
			F.S. 	: X menjadi TOP yang baru, TOP bertambah 1 */
	/*	Kamus */
	/*	Algoritma */
	// if (!IsFull(*S)) {
    	Top(*S)++;
		InfoTop(*S)=X;
	// }
}
void Pop (Stack *S, infotype *X) {
/*	Menghapus X dari Stack S.
		I.S. 		: S  tidak kosong
		F.S.		: X adalah nilai elemen TOP yang lama, TOP berkurang 1 */
	/*	Kamus */
	/*	Algoritma */
	if (!IsEmpty(*S)) {
	    *X = InfoTop(*S);
	    InfoTop(*S)=Nil;
	    Top(*S)--;
	}
}
