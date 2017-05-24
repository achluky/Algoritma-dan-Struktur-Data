#ifndef queue_h
#define queue_h

/*	ADT Queue – Alternatif III */
/*	Deklarasi Queue yang diimplementasi dengan tabel kontigu
	HEAD dan TAIL adalah alamat elemen pertama dan terakhir
	Queue mampu menampung MaxEl buah elemen */

/*	Konstanta */
#define Nil 0

/*	File Include */
#include "boolean.h"

/*	Definisi elemen dan address */
typedef float infotype;
typedef int address; /*	indeks tabel */

/*	Definisi Type Queue */
typedef struct {
	infotype *T; /* tabel penyimpanan elemen, tergantung bahasa */
	address HEAD; /* alamat penghapusan */
	address TAIL; /* alamat penambahan */
	int MaxEl; /* maksimum banyaknya elemen queue */
} Queue;

/*	Definisi Queue kosong: Head = Nil; TAIL = Nil.
	Catatan implementasi: T[0] tidak pernah dipakai */

/*	Akses (Selektor) */
#define Head(Q) (Q).HEAD
#define Tail(Q) (Q).TAIL
#define InfoHead(Q) (Q).T[(Q).HEAD]
#define InfoTail(Q) (Q).T[(Q).TAIL]
#define MaxEl(Q) (Q).MaxEl

/*	Predikat Pemeriksaan Kondisi Queue */
boolean IsEmpty (Queue Q);
/*	Mengirim true jika Q kosong */
boolean IsFull (Queue Q);
/*	Mengirim true jika tabel penampung elemen Q sudah penuh yaitu mengandung MaxEl elemen */
int NBElmt (Queue Q);
/*	Mengirimkan banyaknya elemen queue. Mengirimkan 0 jika Q kosong. */

/*	Konstruktor */
void CreateEmpty (Queue *Q, int Max);
/*	I.S.	: Max terdefinisi
	F.S. 	: Sebuah Q kosong terbentuk dan salah satu kondisi sbb :
			  Jika alokasi berhasil, tabel memori dialokasi berukuran Max 
			  atau jika alokasi gagal, Q kosong dengan Maksimum elemen = 0
	Proses 	: Melakukan alokasi memori dan membuat sebuah Q kosong */

/*	Destruktor */
void DeAlokasi (Queue *Q);
/*	Proses 	: Mengembalikan memori Q
	I.S.	: Q pernah dialokasi 
	F.S.	: Q menjadi tidak terdefinisi lagi, MaxEl(Q) diset 0 */

/*	Operator-Operator Dasar Queue */
void Add (Queue *Q, infotype X);
/*	Proses 	: Menambahkan X pada Q dengan aturan FIFO
	I.S.	: Q mungkin kosong, tabel penampung elemen Q TIDAK penuh 
	F.S.	: X menjadi TAIL yang baru, TAIL "maju".
			  Jika TAIL baru = MaxEl + 1, maka TAIL diset = 1. */
void Del (Queue *Q, infotype *X);
/*	Proses 	: Menghapus elemen pertama pada Q dengan aturan FIFO 
	I.S.	: Q tidak kosong
	F.S.	: X = nilai elemen HEAD pada I.S., Jika Queue masih isi : HEAD "maju".
			  Jika HEAD baru menjadi MaxEl + 1, maka HEAD diset = 1;
			  Jika Queue menjadi kosong, HEAD = TAIL = Nil. */
boolean Search (Queue * Q, infotype X);
/* Proses: Melakukan pencarian nilai X pada Q dengan aturan FIFO dengan mengembalikan nilai true  jika X terdapat pada Q dan sebaliknya */
/* I.S. Q mungkin kosong atau elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */

void PrintInfo(Queue * Q);
/* Proses: Menampilkan semua elemen / nilai pada Q dengan aturan FIFO */
/* I.S. Q mungkin kosong, tabel penampung elemen Q TIDAK penuh */
/* F.S. X menjadi TAIL yang baru, TAIL "maju" dengan mekanisme circular buffer */


#endif
