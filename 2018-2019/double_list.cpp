#include <iostream>
#include <stdlib.h>
using namespace std;

typedef int infotype;
typedef struct TElmtList *address;
typedef struct TElmtList{
    infotype info;
    address next;
    address prev;
} ElmtList;

typedef struct  {
    address first;
    address last;
} List;

bool IsEmpty(List L) {
    return (((L).first == NULL) && ((L).last == NULL));
}

void CreateEmpty(List *L) {
    (*L).first = NULL;
    (*L).last = NULL;
}

void Deallocation(address hapus) {
    free(hapus);
}

address Allocation(infotype x) {
    address NewElmt;
    NewElmt = (ElmtList*) malloc (sizeof(ElmtList));
    NewElmt->info = x;
    NewElmt->next = NULL;
    NewElmt->prev = NULL;
    return NewElmt;
}

void InsertFirst(List *L, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);
    if (NewElmt != NULL) {
        NewElmt->next = (*L).first;
        if (!IsEmpty(*L)) {
        	((*L).first)->prev = NewElmt;
		} else {
			(*L).last = NewElmt;
		}
        (*L).first = NewElmt;
    } 
}

void InsertAfter(List *L, address *PredElmt, infotype x) {
    address NewElmt;
    NewElmt = Allocation(x);

    if (NewElmt != NULL) {
        if ((*PredElmt)->next != NULL) {
        	((*PredElmt)->next)->prev = NewElmt;
		} else {
			(*L).last = NewElmt;
		}
		
		NewElmt->next = (*PredElmt)->next;
		NewElmt->prev = *PredElmt;
        (*PredElmt)->next = NewElmt;
    }
}

void InsertLast(List *L, infotype x) {
   /* 
   		Buat Fungsi InsertLast
		Menambahkan elemen data (info) setelah elemen/node akhir
   */
}

void InsertAfterInfo(List *L, infotype y, infotype x){
	/* 
   		Buat Fungsi InsertAfterInfo
		Menambahkan elemen data (info) setelah nilai tertentu
   */
}

void DeleteFirst(List *L, infotype *hapus) {
    if (!IsEmpty(*L)) {
        address temp;
        temp = (*L).first;
        *hapus = temp->info;
        
        if ((*L).first == (*L).last) {
        	(*L).last = NULL;
		}
        (*L).first = (*L).first->next;
        ((*L).first)->prev = NULL;
        temp->next = NULL;
        
		Deallocation(temp);
    }
}

void DeleteAfter(address pred, infotype *hapus) {
    if (pred->next != NULL) {
        address temp;
        temp = pred->next;
		*hapus = temp->info;
		
        pred->next = temp->next;
        (temp->next)->prev = pred;
        temp->next = NULL;
        temp->prev = NULL;
        
        Deallocation(temp);
    }
}

void DeleteLast(List *L, infotype *hapus) {
    /* 
   		Buat Fungsi DeleteLast
		Menghapus elemen data (info) terakhir
   */
}



int main () {
	List L1, L2;
	infotype x;
	address P;
	CreateEmpty(&L1);
	int i;
	
	/* Isi 5 elemen ke L1 */
	printf("Isi 5 elemen ke  L1 = \n");
	for (i = 1; i <= 5; i++) {
		scanf("%d",&x);
		/* insert first */
		InsertFirst(&L1,x);
	}

	/* Cetak dari awal ke akhir */
	printf("Isinya L1 dibaca dari awal ke akhir = \n");
	P = L1.first;
	i = 1;
	while (P != NULL) {
		printf("[%d] %d\n", i, P->info);
		i++;
		P = P->next;
	}

	/* Cetak dari akhir ke awal */
	printf("Isinya L1 dibaca dari akhir ke awal = \n");
	P = L1.last;
	i = 1;
	while (P != NULL) {
		printf("[%d] %d\n", i, P->info);
		i++;
		P = P->prev;
	}


    /* Insert After */
	printf("Disisipkan angka 30 setelah elemen pertama \n");
    InsertAfter(&L1, &L1.first, 30);
	
    /* Cetak dari awal ke akhir */
	printf("Isinya L1 = \n");
	P = L1.first;
	i = 1;
	while (P != NULL) {
		printf("[%d] %d\n", i, P->info);
		i++;
		P = P->next;
	}


	/*
		Menggunakan fungsi InsertLast, InsertAfterInfo, DeleteLast 
		impelementasikan/gunakan fungsi-fungsi tersebut dalam fungsi main untuk memanipulasi data
	*/

	return 0;
}