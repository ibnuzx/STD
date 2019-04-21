#ifndef FILM_H_INCLUDED
#define FILM_H_INCLUDED

#include <iostream>
#include "infotype.h"
#define first(L) L.first
#define next(P) P->next
#define last(L) L.last
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

typedef struct elmList_Film *address_F;
struct elmList_Film {
    infotype_p2 info;
    address_F next;
    address_F prev;
};
struct List_Film{
    address_F first;
    address_F last;
};

void createList_Film(List_Film &L);
address_F allocate_p(infotype_p2 X);
void deallocate_F(address_F &P);
//void printInfo_F(List_Film L);
void insertFirst(List_Film &L , address_F P);
void insertAfter(List_Film &L, address_F Prec, address_F P);
void insertBefore(List_Film & L , address_F Prec, address_F P);
void insertLast(List_Film &L, address_F P);
void deleteFirst(List_Film &L, address_F &P);
void deleteAfter(List_Film &L, address_F Prec, address_F &P);
void deleteBefore(List_Film &L, address_F Prec, address_F &P);
void deleteLast(List_Film &L, address_F &P);
address_p findElm(infotype_p2 x, List_Film L);
//void deleteProduct(address_F p, List_Film &L);

#endif // FILM_H_INCLUDED
