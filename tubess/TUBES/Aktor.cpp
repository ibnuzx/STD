#include "Aktor.h"
#include "infotype.h"

void createList_Aktor(List_Aktor &L){
    first(L)=NULL;
    last(L)=NULL;
}

address_A allocate_A(infotype_p1 X) {
    address_A P=new elmlist_Aktor;
    info(P)=X;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void deallocate_A(address_A &P) {
    delete P;
    P=NULL;
}

//void printInfo_(List_customer L) {
//    cout<<"Daftar user:"<<endl;
//    int i=1;
//    address_c P=first(L);
//    if((first(L)==NULL)&&(last(L)==NULL)){
//        cout<<"[Kosong]"<<endl;
//    }else{
//        while(P!=NULL){
//            cout<<i<<". "<<(info(P))<<endl;
//            P=next(P);
//            i++;
//        }
//    }
//}

void insertFirst(List_Aktor &L , address_A P) {
    if((first(L)==NULL)&&(last(L)==NULL)){
        first(L)=P;
        last(L)=P;
    }else{
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void insertAfter(List_Aktor &L, address_A Prec, address_A P){
    if(Prec!=NULL) {
        if(next(Prec)==NULL) {
            next(Prec)=P;
            prev(P)=Prec;
            last(L)=P;
        } else {
            next(P)=next(Prec);
            prev(P)=Prec;
            prev(next(Prec))=P;
            next(Prec)=P;
        }
    }
}

void insertBefore(List_Aktor &L , address_A Prec, address_A P){
    insertAfter(L,prev(Prec),P);
}

void insertLast(List_Aktor &L, address_A P){
    if((first(L)!=NULL)&&(last(L)!=NULL)){
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }else if((first(L)==NULL)&&(last(L)==NULL)){
        first(L)=P;
        last(L)=P;
    }
}

void deleteFirst(List_Aktor &L, address_A &P) {
    if(first(L)!=NULL) {
        if(first(L)==last(L)){
            first(L)=NULL;
            last(L)=NULL;
        }else{
            P=first(L);
            first(L)=next(first(L));
            next(P)=NULL;
            prev(first(L))=NULL;
        }
    }
}

void deleteAfter(List_Aktor &L, address_A Prec, address_A &P) {
    if((first(L)!=NULL)&&(last(L)!=NULL)){
        if((Prec!=NULL)&&(Prec!=last(L))){
            if(next(Prec)==last(L)) {
                deleteLast(L,P);
            }else{
                P = next(Prec);
                next(Prec) = next(P);
                prev(next(P)) = Prec;
                prev(P) = NULL;
                next(P) = NULL;
            }
        }
    }
}

void deleteBefore(List_Aktor &L, address_A Prec, address_A &P) {
    deleteAfter(L,prev(prev(Prec)),P);
}

void deleteLast(List_Aktor &L, address_A &P) {
    if(first(L)!=NULL) {
        P = last(L);
        if(P==first(L)) {
            first(L)=NULL;
            last(L)=NULL;
        } else {
            last(L) = prev(last(L));
            prev(P) = NULL;
            next(last(L)) = NULL;
        }
    }
}

address_A findElm(infotype_p1 x, List_Aktor L){
    address_c p,q;
    bool t=false;
    p=first(L);
    while(p!=NULL){
        if(info(p)==x){
            t=true;
            q=p;
        }
        p=next(p);
    }
    if(t==true){
        return q;
    }else{
        return NULL;
    }
}

//void deleteParent(address_c p, List_customer &L){
//    if(p==NULL){
//        cout<<"Produk belum terdaftar"<<endl;
//    }else{
//        if(p==first(L)){
//            deleteFirst(L,p);
//        }else if(p==last(L)){
//            deleteLast(L,p);
//        }else{
//            deleteAfter(L,prev(p),p);
//        }deallocate_c(p);
//        cout<<"Berhasil"<<endl;
//    }
//}

void insertAktor(address_A p, List_Aktor &L){
    if(first(L)==NULL){
        insertFirst(L,p);
    }else if(first(L)!=NULL){
        address_c r=NULL;
        address_c q=first(L);
        while(q!=NULL){
            if(info(p)>=info(q)){
                r=q;
            }q=next(q);
        }
        if(r==NULL){
            insertFirst(L,p);
        }else{
            insertAfter(L,r,p);
        }
    }
}

//void deleteAktor(address_A p, List_Aktor &L){
//    if(p==NULL){
//        cout<<"Customer belum terdaftar"<<endl;
//    }else{
//        if(p==first(L)){
//            deleteFirst(L,p);
//        }else if(p==last(L)){
//            deleteLast(L,p);
//        }else{
//            deleteAfter(L,prev(p),p);
//        }deallocate_c(p);
//        cout<<"Berhasil"<<endl;
//    }
//}
