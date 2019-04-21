#include "Film.h"
#include "infotype.h"

void createList_Film(List_Film &L){
    first(L)=NULL;
    last(L)=NULL;
}

address_p allocate_p(infotype_p2 X) {
    address_p P=new elmList_Film;
    info(P)=X;
    next(P)=NULL;
    prev(P)=NULL;
    return P;
}

void deallocate_F(address_F &P) {
    delete P;
    P=NULL;
}

//void printInfo_F(List_Film L) {
//    cout<<"Daftar Produk:"<<endl;
//    int i=1;
//    address_p P=first(L);
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

void insertFirst(List_Film &L , address_F P) {
    if((first(L)==NULL)&&(last(L)==NULL)){
        first(L)=P;
        last(L)=P;
    }else{
        next(P)=first(L);
        prev(first(L))=P;
        first(L)=P;
    }
}

void insertAfter(List_Film &L, address_F Prec, address_F P){
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

void insertBefore(List_Film &L , address_F Prec, address_F P){
    insertAfter(L,prev(Prec),P);
}

void insertLast(List_Film &L, address_F P){
    if((first(L)!=NULL)&&(last(L)!=NULL)){
        next(last(L))=P;
        prev(P)=last(L);
        last(L)=P;
    }else if((first(L)==NULL)&&(last(L)==NULL)){
        first(L)=P;
        last(L)=P;
    }
}

void deleteFirst(List_Film &L, address_F &P) {
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

void deleteAfter(List_Film &L, address_F Prec, address_F &P) {
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

void deleteBefore(List_Film &L, address_F Prec, address_F &P) {
    deleteAfter(L,prev(prev(Prec)),P);
}

void deleteLast(List_Film &L, address_F &P) {
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

address_p findElm(infotype_p2 x, List_Film L){
    address_p p,q;
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

//void deleteProduct(address_p p, List_product &L){
//    if(p==NULL){
//        cout<<"Produk belum terdaftar"<<endl;
//    }else{
//        if(p==first(L)){
//            deleteFirst(L,p);
//        }else if(p==last(L)){
//            deleteLast(L,p);
//        }else{
//            deleteAfter(L,prev(p),p);
//        }deallocate_p(p);
//        cout<<"Berhasil"<<endl;
//    }
//}
