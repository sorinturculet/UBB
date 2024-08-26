#pragma once
#include "list/listamea.h"

typedef struct{
    MyList* l;
    MyList* undo;
}ManagerLists;

ManagerLists createManagerList();

void destroyManagerList(ManagerLists* store);

void add(ManagerLists* store, char nume[], char prod[], int cant);

int cauta(ManagerLists* store, char nume[]);

void update(ManagerLists* store, int cant, int index);

void remove_prod(ManagerLists* store, int index);

int undoFunction(ManagerLists* store);

void ordonare(ManagerLists* store,MyList * aux,int(*func)(Produs , Produs));

void modificare(ManagerLists* store, int index, int cant);

void filtr_litera(ManagerLists* store, MyList* aux, const char litera[]);

void filtr_cantitate(ManagerLists* store, MyList* aux, int cant);

void filtr_producator(ManagerLists* store, MyList* aux, char prod[]);

int validare_cantitate(int cantitate);

int validare_nume(char nume[]);

int validare_producator(char producator[]);

int criteriu_nume_cresc(Produs a, Produs b);

int criteriu_nume_descr(Produs a, Produs b);

int criteriu_cant_cresc(Produs a, Produs b);

int criteriu_cant_descr(Produs a, Produs b);