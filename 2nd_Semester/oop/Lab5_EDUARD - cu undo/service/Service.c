#include "Service.h"
#include <string.h>
#include <stdlib.h>

#pragma warning(disable: 6001)

ManagerLists createManagerList()
{
    ManagerLists store;
    store.l= createList((void (*)(void *)) destroyPr);
    store.undo=createList((void (*)(void *)) destroyList);
    return store;

}

void destroyManagerList(ManagerLists* store)
{

    destroyList(store->l);
    destroyList(store->undo);
}

void add(ManagerLists* store, char nume[], char prod[], int cant)
{
    ElemType p = crearePr(nume, prod, cant);
    addToList(store->undo, copyList(store->l));

    addToList(store->l, p);

}

int cauta(ManagerLists* store, char nume[]) {
    for (int j = 0; j < store->l->lungime; j++) {
        if (strcmp(nume,((Produs*) store->l->v[j])->denumire) == 0) return j;
    }
    return -1;
}

void update(ManagerLists* store, int cant, int index) {
    addToList(store->undo, copyList(store->l));
    ((Produs*)store->l->v[index])->cantitate += cant;
}

void remove_prod(ManagerLists* store, int index) {
    addToList(store->undo, copyList(store->l));
    free(((Produs*)store->l->v[index])->denumire);
    free(((Produs*)store->l->v[index])->producator);
    free(((Produs*)store->l->v[index]));
    for (int i = index; i < store->l->lungime-1; i++)
    {
        store->l->v[i] = store->l->v[i + 1];
    }
    store->l->lungime--;
}

int undoFunction(ManagerLists* store)
{
    if(store->undo->lungime>0) {
        destroyList(store->l);
        store->l = store->undo->v[store->undo->lungime - 1];
        store->undo->lungime--;
        return 0;
    }
    return 1;
}
void ordonare(ManagerLists* store,MyList * aux,int(*func)(Produs , Produs)) {
    //initializam aux
    for(int i=0;i<store->l->lungime;i++)
        addToList(aux, duplicatePr(store->l->v[i]));

    int ok = 1;
    while (ok)
    {
        ok = 0;
        for(int j = 0; j < aux->lungime - 1; j++)
            if (func( *(Produs*)aux->v[j], *(Produs*)aux->v[j + 1]) > 0)
            {
                Produs *temp = aux->v[j];
                aux->v[j] = aux->v[j + 1];
                aux->v[j + 1] = temp;
                ok = 1;
            }
    }
}

void modificare(ManagerLists* store, int index, int cant) {
    addToList(store->undo, copyList(store->l));
    ((Produs*)store->l->v[index])->cantitate = cant;
}

void filtr_litera(ManagerLists* store, MyList* aux, const char litera[]) {
    for (int j = 0; j < store->l->lungime; j++)
    {
        if (((Produs *)store->l->v[j])->denumire[0] == litera[0]){
            addToList(aux,store->l->v[j]);
        }
    }
}

void filtr_cantitate(ManagerLists* store, MyList* aux, int cant) {

    for (int j = 0; j < store->l->lungime; j++)
    {
        if ( ((Produs*)store->l->v[j])->cantitate < cant)  {
            addToList(aux,store->l->v[j]);
        }
    }
}
void filtr_producator(ManagerLists* store, MyList* aux, char prod[]) {

    for (int j = 0; j < store->l->lungime; j++)
    {
        if ( strcmp(((Produs*)store->l->v[j])->producator,prod)==0) {
            addToList(aux,store->l->v[j]);
        }
    }
}
int validare_cantitate(int cantitate)
{
    if(cantitate < 0) return 0;
    return 1;
}

int validare_nume(char nume[])
{
    if (strlen(nume) < 3) return 0;
    return 1;
}

int validare_producator(char producator[])
{
    if (strlen(producator) < 3) return 0;
    return 1;
}

int criteriu_nume_cresc(Produs a, Produs b) {
    return strcmp(a.denumire, b.denumire) > 0;
}

int criteriu_nume_descr(Produs a, Produs b) {
    return strcmp(a.denumire, b.denumire) < 0;
}

int criteriu_cant_cresc(Produs a, Produs b) {
    return a.cantitate > b.cantitate;
}

int criteriu_cant_descr(Produs a, Produs b) {
    return a.cantitate < b.cantitate;
}