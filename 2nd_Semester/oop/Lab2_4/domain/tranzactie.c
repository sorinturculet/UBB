//
// Created by sorn on 18-Mar-24.
//

#include "tranzactie.h"
#include<string.h>
#include<assert.h>
#include<stdlib.h>
Transaction* createTransaction(int day,int sum,char* type,char* description){
    Transaction* tr=(Transaction *)malloc(sizeof(Transaction));
    if(tr) {
        tr->day = day;
        tr->sum = sum;

        int nrc = (int) strlen(type) + 1;
        tr->type = malloc(nrc * sizeof(char));
        strcpy(tr->type, type);

        nrc = (int) strlen(description) + 1;
        tr->description = malloc(nrc * sizeof(char));
        strcpy(tr->description, description);

        return tr;
    }
    return NULL;
}

void destroyTransaction(Transaction* tr){
    free(tr->type);
    free(tr->description);
    free(tr);
}
void testTransaction(){
    Transaction* tr=createTransaction(2,250,"intrare","cumparaturi");
    assert(tr->day==2);
    assert(tr->sum==250);
    assert(strcmp(tr->type,"intrare")==0);
    assert(strcmp(tr->description,"cumparaturi")==0);
    destroyTransaction(tr);
}
void testDestroyTransaction(){
    Transaction* tr=createTransaction(2,250,"intrare","cumparaturi");
    destroyTransaction(tr);
}