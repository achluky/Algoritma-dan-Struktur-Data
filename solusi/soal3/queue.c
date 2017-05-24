/*	File Include */
#include "queue.h"
#include "boolean.h"
#include <stdlib.h>
#include <stdio.h>

/*	Predikat Pemeriksaan Kondisi Queue */
boolean IsEmpty (Queue Q) {
	/* Kamus */
	/* Algoritma */
	return ((Head(Q)==0)&&(Tail(Q)==0));
}
boolean IsFull (Queue Q) {
	/* Kamus */
	/* Algoritma */
	return (NBElmt(Q)==MaxEl(Q));
}
int NBElmt (Queue Q) {
	/* Kamus */
	/* Algoritma */
	if (IsEmpty(Q)) {
	 	return 0;
	} else if (Tail(Q)>Head(Q)) {
		return Tail(Q)-Head(Q)+1;
	} else if (Tail(Q)<Head(Q)) {
		return (MaxEl(Q)+Tail(Q))-Head(Q)+1;
	} else {
		return 1;
	}
}

/*	Konstruktor */
void CreateEmpty (Queue *Q, int Max) {
	/* Kamus */
	/* Algoritma */
	if (Max>0) {
		(*Q).T=(infotype *) malloc ((Max+1)*sizeof (infotype));
		MaxEl(*Q)=Max;
	} else {
		MaxEl(*Q)=0;
	}
	Head(*Q)=0;
	Tail(*Q)=0;
}

/*	Destruktor */
void DeAlokasi (Queue *Q) {
	/* Kamus */
	/* Algoritma */
	free((*Q).T);
	MaxEl(*Q)=0;
}

/*	Operator-Operator Dasar Queue */
void Add (Queue *Q, infotype X) {
	/* Kamus */
	/* Algoritma */
	if (!IsFull(*Q)) {
		if (IsEmpty(*Q)) {
			Head(*Q)=1;
			Tail(*Q)=1;
			InfoTail(*Q)=X;
		} else { 
			Tail(*Q)++;
			if (Tail(*Q)>MaxEl(*Q)) {
				Tail(*Q)=Tail(*Q)%MaxEl(*Q);
				InfoTail(*Q)=X;
			} else {
				InfoTail(*Q)=X;
			}
		}	
	}
}
void Del (Queue *Q, infotype *X) {
	/* Kamus */
	/* Algoritma */
	if (!IsEmpty(*Q)) {
		(*X)=InfoHead(*Q);
		if (NBElmt(*Q)==1) {
			Head(*Q)=0;
			Tail(*Q)=0;
		} else {
			Head(*Q)++;
			if (Head(*Q)>MaxEl(*Q)) {
				Head(*Q)=Head(*Q)%MaxEl(*Q);
			}
		}
	}
}
void PrintInfo(Queue *Q){
	int head = Head(*Q);
	int tail = Tail(*Q);

	for (int i = head; i <= tail; ++i){
		if (i == head && i==tail){
			printf("%f --> Head --> Tail \n", (*Q).T[i]);
		} else if (i == head){
			printf("%f --> Head \n", (*Q).T[i]);
		} else if (i == tail){
			printf("%f --> Tail \n", (*Q).T[i]);
		} else {
			printf("%f\n", (*Q).T[i]);
		}
			
	}
}

boolean Search (Queue * Q, infotype X){
	/* Kamus */
	/* Algoritma */
	int head = Head(*Q);
	int tail = Tail(*Q);

	for (int i = head; i <= tail; ++i){
		if( (*Q).T[i] == X ){
			return 1;
		}
	}
	return 0;
}