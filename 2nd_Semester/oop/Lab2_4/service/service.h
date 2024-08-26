//
// Created by sorn on 18-Mar-24.
//

#ifndef C_SERVICE_H
#define C_SERVICE_H

#include"../domain/tranzactie.h"
#include"../list/list.h"
/*
 * testeaza toate datele
 */
void testall();
/*
 *Adauga o tranzactie la lista
 * param l:lista
 * param day:int
 * param sum:int
 * param type:char[]
 *
 * param description: char[]
 */
int addTransactionToList(MyList* l,int day,int sum,char type[],char description[]);
/*
 *Modifica o tranzactie dupa pozitie din lista
 * param l:lista
 * param pos:int
 * param tr: Tranzactie
 * returns 0:daca a functionat
 */
int modifyTransactionInList(MyList* l,int pos,int day,int sum,char type[],char description[]);
/*
 *Sterge o tranzactie dupa pozitie din lista
 * param l:lista
 * param pos:int
 * returns 0:daca a functionat
 */
int deleteTransactionFromList(MyList* l,int pos);
/*
 *Sterge toate tranzactiile din lista
 * param l:lista
 * returns
 * returns 0:daca a functionat
 */
int deleteAllTransactionFromList(MyList* l);
/*
 *Filtreaza lista dupa cum doreste uitilizatorul
 * param l:lista
 * param crt: sir de char
 * param ord:sit de char
 * param suma:int
 * returns newlist:MyList
 */
MyList* filterByInt(MyList* l,char ord[],int suma);
/*
  *Filtreaza lista dupa cum doreste uitilizatorul
 * param l:lista
 * param ord:sit de char
 * param suma:int
 * returns newList:MyList
 */
MyList* filterByType(MyList* l,char ord[]);
/*
 *Ordoneaza lista dupa un criteriu si o ordine data
 * param l:lista
 * param crt: tipul de criteriu: suma/zi
 * param ord: c/d pentru crescator respectiv descrescator
 */
void orderList(MyList* l,int(*f)(const void*, const void*));

int cmpfunc_ZD (const void * a, const void * b);
int cmpfunc_ZC (const void * a, const void * b);
int cmpfunc_SC (const void * a, const void * b);
int cmpfunc_SD (const void * a, const void * b);

void testFilterByInt();
void testFilterByType();
void testAddTransactionToList();
void testmodifyTransactionInList();
void testDeleteTransactionFromList();
void testDeleteAllTransaction();
void testSort();
#endif //C_SERVICE_H
