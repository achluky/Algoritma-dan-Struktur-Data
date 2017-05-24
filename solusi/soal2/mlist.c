#include "list.h"
#include <stdio.h>

int main() {
  List L;
  address P;
  CreateEmpty(&L);
  if (IsEmpty(L)) {
    printf("YUHU\n");
  }
  P = Alokasi(3);
  Next(P) = First(L);
  InsertFirst(&L,P);
  P = Alokasi(2);
  InsertFirst(&L,P);
  InsVFirst(&L,1);
  PrintInfo(L);
  printf("\n");
  DelFirst(&L,&P);
  DelFirst(&L,&P);
  DelFirst(&L,&P);
  printf("%d\n",Info(P));
  PrintInfo(L);
  printf("\n");
  InsVLast(&L,1);
  InsVLast(&L,2);
  InsVLast(&L,3);
  PrintInfo(L);
  printf("\n");
  DelP(&L,4);
  DelP(&L,3);
  DelP(&L,2);
  PrintInfo(L);
  printf("\n");
  return 0;
}
