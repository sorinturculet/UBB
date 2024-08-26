//
// Created by sorn on 18-Mar-24.
//

#ifndef C_LIST_H
#define C_LIST_H
#include"../domain/tranzactie.h"

typedef struct{
    Transaction** myList;
    int cap;
    int len;
}MyList;
/*
 *Creeaza o lista goala
 * returns Lista
 */
MyList* createList();
/*
 *Adauga o tranzactie la lista
 * param l:lista
 * param tr: Tranzactie
 */
void addTransaction(MyList* l,Transaction* Tr);
/*
 *Modifica o tranzactie dupa pozitie din lista
 * param l:lista
 * param pos:int
 * param tr: Tranzactie
 * returns 0:daca a functionat
 */
void modifyTransaction(MyList* l,int pos, Transaction* Tr);
/*
 *Sterge o tranzactie dupa pozitie din lista
 * param l:lista
 * param pos:int
 * returns 0:daca a functionat
 */
void deleteTransaction(MyList* l,int i);
/*
 *Sterge toate tranzactiile din liste
 * param l:lista
 * returns 0:daca a functionat
 */
int deleteAllTransaction(MyList* l);
/*
 *Sterge o lista
 * param l:lista
 * returns 0:daca a functionat
 */
int destroyList(MyList* l);

int validareDay(int day);
int validareSum(int day);


void testCreateList();
void testAddTransaction();
void testModifyTransaction();
void testDeleteTransaction();
#endif //C_LIST_H
