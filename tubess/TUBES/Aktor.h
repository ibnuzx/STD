#ifndef AKTOR_H_INCLUDED
#define AKTOR_H_INCLUDED

#include <iostream>
#include "infotype.h"
#define first(L) L.first
#define next(P) P->next
#define last(L) L.last
#define prev(P) P->prev
#define info(P) P->info

using namespace std;

typedef struct elmlist_Aktor *address_A;
struct elmlist_Aktor{
    infotype_p1 info;
    address_A next;
    address_A prev;
};
struct List_Aktor{
    address_A first;
    address_A last;
};

void createList_Aktor(List_Aktor &L);
address_A allocate_A(infotype_p1 X);
void deallocate_A(address_A &P);
//void printInfo_c(List_customer L);
void insertFirst(List_Aktor &L , address_A P);
void insertAfter(List_Aktor &L, address_A Prec, address_A P);
void insertBefore(List_Aktor & L , address_A Prec, address_A P);
void insertLast(List_Aktor &L, address_A P);
void deleteFirst(List_Aktor &L, address_A &P);
void deleteAfter(List_Aktor &L, address_A Prec, address_A &P);
void deleteBefore(List_Aktor &L, address_A Prec, address_A &P);
void deleteLast(List_Aktor &L, address_A &P);
address_c findElm(infotype_p1 x, List_Aktor L);
void insertCustomer(address_A p, List_Aktor &L);
//void deleteCustomer(address_c p, List_customer &L);

#endif // AKTOR_H_INCLUDED
