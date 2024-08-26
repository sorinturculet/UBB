//
// Created by sorn on 18-Mar-24.
//

#ifndef C_TRANZACTIE_H
#define C_TRANZACTIE_H
typedef struct{
    int day;
    int sum;
    char* type;
    char* description;
}Transaction;
/*
 *Creeaza o tranzactie alocata dinamic
 * param: day:int
 * param sum:int
 * param type:char[]
 * param description:char[]
 * returns Tr:Transaction
 */
Transaction* createTransaction(int day,int sum,char type[],char description[]);
/*
 *Distruge o tranzactie(dealoca)
 * param Tr:Transaction
 */
void destroyTransaction(Transaction* tr);

void testTransaction();
void testDestroyTransaction();
#endif //C_TRANZACTIE_H
