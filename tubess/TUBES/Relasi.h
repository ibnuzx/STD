#ifndef RELASI_H_INCLUDED
#define RELASI_H_INCLUDED

#include <iostream>
#include "infotype.h"
#define first(L) L.first
#define next(P) P->next
#define info(P) P->info
#include "Film.h"

using namespace std;

typedef struct elmlist_Relasi *address_R;
struct elmlist_Relasi{
    infotype_R info;
    address_R next;
};
struct List_Relasi {
    address_R first;
};

//struct typedefavg{
//    infotype_p2 prod[100];
//    int rate[100];
//};

void createList_Relasi(List_Relasi &L);
address_R allocate_R(infotype_R x);
void deallocate_R(address_R &P);
void printInfo_R(List_Relasi L);
void insertFirst(address_R P, List_Relasi &L);
void insertAfter(List_Relasi &L, address_R Prec, address_R P);
void insertLast(List_Relasi &L, address_R P);
void deleteFirst(List_Relasi &L, address_R &P);
void deleteLast(List_Relasi &L, address_R &P);
void deleteAfter(List_Relasi &L, address_R Prec, address_R &P);
address_r findProd(string x, List_Relasi L);
void insertRating(address_A p, address_F q, List_Relasi &L, List_Relasi &K, int x);
void rateEveryProd(List_Film p, List_Relasi L);
int rateAverageProd(address_F p, List_Relasi L);
address_r findCustomerProd(string y, string x, List_Relasi L);
int banyakarray(typedefavg x);
address_r findNextProd(address_R x, List_Relasi L);
void rateProd(List_Film p, List_Relasi L);
void printInfoAkun_r(List_Relasi L, address_A q);

#endif // RELASI_H_INCLUDED
