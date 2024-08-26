//
// Created by sorn on 18-Mar-24.
//

#include "list.h"
#include<assert.h>
#include<string.h>
#include<stdlib.h>

MyList* createList(){
    MyList* l=(MyList*)malloc(sizeof(MyList));
    if(l) {
        l->cap = 2;
        l->len = 0;
        l->myList = (Transaction **)malloc(sizeof(Transaction*) * l->cap);
    }
    return l;
}
/*
void addTransaction(MyList* l, Transaction* Tr){
    l->myList[l->len]=Tr;
    l->len=(l->len)+1;
}
 */
void addTransaction(MyList* l, Transaction* Tr) {
    if (l->len == l->cap) {
        int new_cap = l->cap * 2;
        Transaction ** aux = malloc(sizeof(Transaction*) * new_cap);
        for (int i = 0; i < l->len; ++i) {
            aux[i] = l->myList[i];
        }
        free(l->myList);
        l->myList = aux;
        l->cap = new_cap;
    }
    l->myList[l->len] = Tr;
    l->len++;
}
void modifyTransaction(MyList* l,int pos, Transaction* tr){
    Transaction* new_tr = createTransaction(tr->day, tr->sum, tr->type, tr->description);

    destroyTransaction(l->myList[pos]);
    destroyTransaction(tr);

    l->myList[pos] = new_tr;
}
void deleteTransaction(MyList* l,int pos){
    destroyTransaction(l->myList[pos]);
    for(int i=pos;i<l->len-1;i++)
        l->myList[i]=l->myList[i+1];
    l->len-=1;
}
int deleteAllTransaction(MyList* l){
    for (int i = 0; i < l->len; i++) {
        destroyTransaction(l->myList[i]);
    }
    destroyList(l);
    return 0;
}
int destroyList(MyList* l){
    free(l->myList);
    free(l);
    return 0;
}
void testCreateList(){
    MyList* l=createList();
    assert(l->len==0);
    deleteAllTransaction(l);

}
void testAddTransaction(){
    MyList* l=createList();
    Transaction* Tr= createTransaction(1,30,"Intrare","Bani");
    addTransaction(l,Tr);
    assert(l->len==1);
    assert(l->cap==2);
    Transaction* Tr2= createTransaction(1,30,"Intrare","Bani");
    addTransaction(l,Tr2);
    assert(l->len==2);
    assert(l->cap==2);
    Transaction* Tr3= createTransaction(1,30,"Intrare","Bani");
    addTransaction(l,Tr3);
    assert(l->len==3);
    assert(l->cap==4);
    deleteAllTransaction(l);
}
void testModifyTransaction(){
    MyList* l=createList();
    Transaction* Tr= createTransaction(1,30,"Intrare","Bani");
    addTransaction(l,Tr);
    assert(l->len==1);
    assert(l->myList[0]->sum==30);
    assert(strcmp(l->myList[0]->type,"Intrare")==0);
    Transaction* new_Tr=createTransaction(1,20,"Iesire","Bani");
    modifyTransaction(l,0,new_Tr);
    assert(l->myList[0]->sum==20);
    assert(strcmp(l->myList[0]->type,"Iesire")==0);

    deleteAllTransaction(l);
}

void testDeleteTransaction(){
    MyList* l=createList();
    Transaction* Tr= createTransaction(1,30,"Intrare","Bani");
    Transaction* Tr2= createTransaction(1,30,"Iesire","Bani");
    addTransaction(l,Tr);
    addTransaction(l,Tr2);
    assert(l->len==2);
    deleteTransaction(l,0);
    assert(l->len==1);


    deleteAllTransaction(l);
}