//
// Created by sorn on 18-Mar-24.
//

#include "service.h"

#include<assert.h>
#include<string.h>
#include <stdlib.h>

void testall() {
    testTransaction();
    testDestroyTransaction();
    testCreateList();
    testAddTransaction();
    testDeleteTransaction();
    testSort();
    testModifyTransaction();
    testAddTransactionToList();
    testmodifyTransactionInList();
    testDeleteAllTransaction();
    testDeleteTransactionFromList();
    testFilterByInt();
    testFilterByType();
}
int addTransactionToList(MyList* l,int day,int sum,char type[],char description[]){
    if(validareDay(day) && validareSum(sum)) {
        Transaction* tr = createTransaction(day, sum, type, description);
        addTransaction(l, tr);
    }
    return 0;
}
int modifyTransactionInList(MyList* l,int pos,int day,int sum,char type[],char description[]){
    if(validareDay(day) && validareSum(sum)) {
        Transaction* tr = createTransaction(day, sum, type, description);
        modifyTransaction(l, pos, tr);
    }
    return 0;
}
int deleteTransactionFromList(MyList* l,int pos){
    deleteTransaction(l,pos);
    return 0;
}
int deleteAllTransactionFromList(MyList* l){
    deleteAllTransaction(l);
    return 0;
}

MyList* filterByInt(MyList* l,char ord[],int suma){
    MyList* l_filter=createList();
    for(int i=0; i < l->len; i++){
        if(strcmp(ord,"M")==0)
        {
            if (l->myList[i]->sum > suma)
                addTransaction(l_filter, l->myList[i]);
        }
        if(strcmp(ord,"m")==0)
        {
            if (l->myList[i]->sum < suma)
                addTransaction(l_filter, l->myList[i]);
        }
    }
    return l_filter;
}
MyList* filterByType(MyList* l,char ord[])
{
    MyList* l_filter=createList();
    for(int i=0; i < l->len; i++){
        if(strcmp(l->myList[i]->type,ord)==0)
            addTransaction(l_filter,l->myList[i]);
    }
    return l_filter;
}
int cmpfunc_SC (const void * a, const void * b){
    Transaction *TranzactionA=*(Transaction **)a;
    Transaction *TranzactionB=*(Transaction **)b;
    return TranzactionA->sum-TranzactionB->sum;
}

int cmpfunc_SD (const void * a, const void * b){
    Transaction *TranzactionA=*(Transaction **)a;
    Transaction *TranzactionB=*(Transaction **)b;
    return TranzactionB->sum-TranzactionA->sum;
}

int cmpfunc_ZC (const void * a, const void * b){
    Transaction *TranzactionA=*(Transaction **)a;
    Transaction *TranzactionB=*(Transaction **)b;
    return TranzactionA->day-TranzactionB->day;
}

int cmpfunc_ZD (const void * a, const void * b){
    Transaction *TranzactionA=*(Transaction **)a;
    Transaction *TranzactionB=*(Transaction **)b;
    return TranzactionB->day-TranzactionA->day;
}

void orderList(MyList* l,int(*f)(const void*, const void *)){

            qsort(l->myList,l->len, sizeof(Transaction*),f);
}

int validareDay(int day){
    if(day<=0 || day>31)
        return 0;
    return 1;
}
int validareSum(int sum){
    if(sum<0)
        return 0;
    return 1;
}
void testAddTransactionToList(){
    MyList* l=createList();
    //Transaction* tr1= createTransaction(1,30,"Intrare","Bani");
    addTransactionToList(l,1,30,"Intrare","Bani");
    assert(l->len==1);
    addTransactionToList(l,40,100,"Intrare","Bani");
    assert(l->len==1);
    addTransactionToList(l,20,-20,"Intrare","Bani");
    assert(l->len==1);
    deleteAllTransaction(l);
}
void testmodifyTransactionInList(){
    MyList* l=createList();
    addTransactionToList(l,1,30,"Intrare","Bani");
    assert(l->len==1);
    assert(l->myList[0]->sum==30);
    assert(strcmp(l->myList[0]->type,"Intrare")==0);
    //Transaction new_Tr=createTransaction(1,20,"Iesire","Bani");
    modifyTransactionInList(l,0,1,20,"Iesire","Bani");
    assert(l->myList[0]->sum==20);
    assert(strcmp(l->myList[0]->type,"Iesire")==0);
    deleteAllTransaction(l);

}
void testDeleteTransactionFromList(){
    MyList* l=createList();
    //Transaction* tr1= createTransaction(1,30,"Intrare","Bani");
    addTransactionToList(l,1,30,"Intrare","Bani");
    assert(l->len==1);
    deleteTransactionFromList(l,0);
    assert(l->len==0);
    deleteAllTransaction(l);
}
void testDeleteAllTransaction(){
    MyList* l=createList();
    Transaction* tr1= createTransaction(1,30,"Intrare","Bani");
    Transaction* tr2= createTransaction(2,300,"Intrare","adidasi");
    Transaction* tr3= createTransaction(3,20,"Intrare","papuci");
    Transaction* tr4= createTransaction(4,900,"Intrare","cantina");
    addTransaction(l,tr1);
    addTransaction(l,tr2);
    addTransaction(l,tr3);
    addTransaction(l,tr4);
    deleteAllTransaction(l);

}
void testFilterByInt(){
    MyList*l=createList();
    addTransactionToList(l,1,30,"Intrare","Bani");
    addTransactionToList(l,2,300,"Intrare","adidasi");
    addTransactionToList(l,3,20,"Intrare","papuci");
    addTransactionToList(l,4,900,"Iesire","cantina");
    MyList* l_filter;
    l_filter=filterByInt(l,"M",100);
    assert(l_filter->len==2);
    MyList* l_filter2;
    l_filter2=filterByInt(l,"m",100);
    assert(l_filter2->len==2);
    deleteAllTransactionFromList(l);
    destroyList(l_filter);
    destroyList(l_filter2);
}
void testFilterByType(){
    MyList*l=createList();
    addTransactionToList(l,1,30,"Intrare","Bani");
    addTransactionToList(l,2,300,"Intrare","adidasi");
    addTransactionToList(l,3,20,"Intrare","papuci");
    addTransactionToList(l,4,900,"Iesire","cantina");
    MyList*l_filter;
    l_filter=filterByType(l,"Intrare");
    assert(l_filter->len==3);
    MyList* l_filter2;
    l_filter2=filterByType(l,"Iesire");
    assert(l_filter2->len==1);
    deleteAllTransactionFromList(l);
    destroyList(l_filter);
    destroyList(l_filter2);
}
void testSort(){
    MyList*l=createList();
    //Transaction* tr1= createTransaction(1,30,"Intrare","Bani");
    //Transaction* tr2= createTransaction(2,300,"Intrare","adidasi");
    //Transaction* tr3= createTransaction(3,20,"Intrare","papuci");
    //Transaction* tr4= createTransaction(4,900,"Intrare","cantina");
    addTransactionToList(l,1,30,"Intrare","Bani");
    addTransactionToList(l,2,300,"Intrare","adidasi");
    addTransactionToList(l,3,20,"Intrare","papuci");
    addTransactionToList(l,4,900,"Intrare","cantina");
    assert(l->len==4);

    int (*f)(const void*, const void*)=cmpfunc_SC;
    orderList(l,f);
    assert(l->myList[0]->sum==20);
    f=cmpfunc_SD;
    orderList(l,f);
    assert(l->myList[3]->sum==20);
    f=cmpfunc_ZC;
    orderList(l,f);
    assert(l->myList[0]->day==1);
    f=cmpfunc_ZD;
    orderList(l,f);
    assert(l->myList[3]->day==1);

    deleteAllTransactionFromList(l);

}
