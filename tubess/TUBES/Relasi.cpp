#include "Relasi.h"
#include "infotype.h"
#include <iostream>
#include "Aktor.h"
#include "Film.h"

void createList_Relasi(List_Relasi &L){
    first(L)=NULL;
}

address_R allocate_R(infotype_R x){
    address_R P=new elmlist_Relasi;
    info(P)=x;
    next(P)=NULL;
    return P;
}

void deallocate_R(address_R &P) {
    delete P;
    P = NULL;
}

void printInfo_R(List_Relasi L) {
    address_R P=first(L);
    if(first(L)!=NULL) {
        int i=1;
        cout<<"Semua Rating: "<<endl<<endl;
        do{
            cout<<i<<endl;
            cout<<"   Aktor: "<<info(info(P).Aktor)<<endl;
            cout<<"   Rating  : "<<info(P).Rating<<endl;
            cout<<"   Film  : "<<info(info(P).Film)<<endl;
            P=next(P);
            i++;
        }while(P!=first(L));
    }
    cout<<endl;
}

void printInfoAkun_R(List_Relasi L, address_A q){
    address_R P = first(L);
    if(first(L)!=NULL) {
        int i=1;
        cout<<"Semua Rating ["<<info(q)<<"]: "<<endl<<endl;
        do{
            if(info(info(P).Aktor)==info(q)){
                cout<<i<<endl;
                cout<<"   Rating  : "<<info(P).rating<<endl;
                cout<<"   Film  : "<<info(info(P).Film)<<endl;
                i++;
            }
            P=next(P);
        }while(P!=first(L));
    }
    cout<<endl;
}

void insertFirst(address_R P, List_Relasi &L){
    if(first(L)==NULL){
        first(L)=P;
        next(P)=P;
    }else{
        address_r Q=first(L);
        do{
            Q=next(Q);
        }while(next(Q)!=first(L));
        next(Q)=P;
        next(P)=first(L);
        first(L)=P;
    }
}

void insertAfter(List_Relasi &L, address_R Prec, address_R P){
    if(Prec!=NULL) {
        if(next(Prec)==first(L)) {
            insertLast(L, P);
        } else {
            next(P) = next(Prec);
            next(Prec) = P;
        }
    }
}

void insertLast(List_Relasi &L, address_R P) {
    if(first(L) == NULL) {
        first(L) = P;
        next(P) = P;
    } else {
        address_r Q = first(L);
        while (next(Q)!=first(L)){
            Q = next(Q);
        }
        next(Q) = P;
        next(P) = first(L);
    }
}

void deleteFirst(List_Relasi &L, address_R &P) {
    if(first(L)!=NULL){
        P=first(L);
        if(next(P)==first(L)){
            next(P)=NULL;
            first(L)=NULL;
        }else{
            address_r Q=first(L);
            while(next(Q)!=first(L)){
                Q=next(Q);
            }
            next(Q)=next(first(L));
            first(L)=next(first(L));
            next(P)=NULL;
        }
    }
}

void deleteLast(List_Relasi &L, address_R &P) {
    if(first(L)!=NULL) {
        P = first(L);
        if(next(P)==first(L)) {
            next(P) = NULL;
            first(L) = NULL;
        } else {
            address_r Q = first(L);
            while (next(next(Q))!=first(L)) {
                Q = next(Q);
            }
            P = next(Q);
            next(Q) = next(P);
            next(P) = NULL;
        }
    }
}

void deleteAfter(List_Relasi &L, address_R Prec, address_R &P) {
    if(next(Prec)==first(L)){
        deleteFirst(L, P);
    }else{
        P=next(Prec);
        next(Prec)=next(P);
        next(P)=NULL;
    }
}

address_r findProd(string x, List_Relasi L){
    address_r p,q;
    bool t=false;
    p=first(L);
    if(first(L)!=NULL){
        if(x==info(info(first(L)).Film)){
            return p;
        }else{
            do{
                if(info(info(next(p)).Film)==x){
                    t=true;
                    q=next(p);
                }
                p=next(p);
            }while(p!=first(L));
        }
    }
    if(t==true){
        return q;
    }else{
        return NULL;
    }
}

address_r findNextProd(address_R x, List_Relasi L){
    address_r p,q;
    bool t=false;
    p=first(L);
    if(first(L)!=NULL){
        if(x==first(L)){
            return p;
        }else{
            do{
                if(next(next(p))==x){
                    t=true;
                    q=p;
                }
                p=next(p);
            }while(p!=first(L));
        }
    }
    if(t==true){
        return q;
    }else{
        return NULL;
    }
}

address_r findCustomerProd(string y, string x, List_Relasi L){
    address_r p,q;
    bool t=false;
    p=first(L);
    if(first(L)!=NULL){
        if((x==info(info(first(L)).Film))&&(y==info(info(first(L)).Aktor))){
            return p;
        }else{
            do{
                if((x==info(info(p).Film))&&(y==info(info(p).Aktor))){
                    t=true;
                    q=next(p);
                }
                p=next(p);
            }while(p!=first(L));
        }
    }
    if(t==true){
        return q;
    }else{
        return NULL;
    }
}

void insertRating(address_A p, address_F q, List_Relasi &L, List_Relasi &K, int x){
    infotype_r n;
    n.Aktor=p;
    n.Film=q;
    n.rating=x;
    insertFirst(allocate_r(n),L);
    insertFirst(allocate_r(n),K);
}

int banyakarray(typedefavg x){
    int i=0;
    while(x.prod[i]!=""){
        i++;
    }return i;
}

//void rateProd(List_Film p, List_Relasi L){
//    typedefavg avg;
//    address_p q=first(p);
//    int i=0;
//    while(q!=NULL){
//        avg.prod[i]=info(q);
//        avg.rate[i]=rateAverageProd(q,L);
//        i++;
//        q=next(q);
//    }
//    cout<<"Rate Average Product:"<<endl<<endl;
//    i=0;
//    while(i!=banyakarray(avg)){
//        cout<<i+1<<". Rata-rata product ["<<avg.prod[i]<<"]: "<<avg.rate[i]<<endl;
//        i++;
//    }
//
//}

//void rateEveryProd(List_Film p, List_Relasi L){
//    typedefavg avg;
//    int i=0;
//    address_p q=first(p);
//    cout<<"Top-10 Rate Product:"<<endl;
//    while(q!=NULL){
//        avg.prod[i]=info(q);
//        avg.rate[i]=rateAverageProd(q,L);
//        i++;
//        q=next(q);
//    }
//    cout<<endl;
//    int z=i-1;
//    string prodrate="";
//    int maxrate=0;
//    int j;
//    int w;
//    i=0;
//    while(i!=z+1){
//        j=0;
//        while(j!=z+1){
//            if(avg.rate[j]>maxrate){
//                prodrate=avg.prod[j];
//                maxrate=avg.rate[j];
//                w=j;
//            }j++;
//        }cout<<i+1<<". Rata-rata product ["<<prodrate<<"]: "<<maxrate<<endl;
//        int k=w;
//        while(k!=z+1){
//            if(k==z){
//                avg.prod[k]="";
//                avg.rate[k]=0;
//            }else{
//                avg.prod[k]=avg.prod[k+1];
//                avg.rate[k]=avg.rate[k+1];
//            }
//            k++;
//        }
//        maxrate=-1;
//        i++;
//    }
//}

//int rateAverageProd(address_p p, List_relasi L){
//    if(first(L)!=NULL){
//        int i=0;
//        int tot=0;
//        int avg=0;
//        if(next(first(L))==first(L)){
//            if(info(info(first(L)).product)==info(p)){
//                tot=tot+info(first(L)).rating;
//                i++;
//                avg=tot/i;
//            }
//        }else{
//            address_r n=first(L);
//            do{
//                if(info(info(n).product)==info(p)){
//                    tot=tot+info(n).rating;
//                    i++;
//                }
//                n=next(n);
//            }while(n!=first(L));
//            if(i==0){
//                i=1;
//            }
//            avg=tot/i;
//        }
//        return avg;
//    }
//}
