#include "Service.h"
#include <string.h>
#include <stdlib.h>
#include "list/listamea.h"
#pragma warning(disable: 6001)

void add(Lista *lista, char nume[], char prod[], int cant)
{
    ElemType p = crearePr(nume, prod, cant);
    addToList(lista, p);
}

int cauta(Lista* lista, char nume[]) {
    for (int j = 0; j < lista->lungime; j++) {
        if (strcmp(nume,((Produs*) lista->v[j])->denumire) == 0) return j;
    }
    return -1;
}

void update(Lista * lista, int cant, int index) {
    ((Produs*)lista->v[index])->cantitate += cant;
}


void ordonare(Lista* lista, Lista* aux, int(*func)(Produs , Produs)) {
    //initializam aux
    for(int i=0;i<lista->lungime;i++)
        addToList(aux, duplicatePr(lista->v[i]));

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

void modificare(Lista *l, int index, int cant) {
    ((Produs*)l->v[index])->cantitate = cant;
}

void filtr_litera(Lista *lista, Lista* aux, char litera[]) {
    int i = 0;
    for (int j = 0; j < lista->lungime; j++)
    {
        if (((Produs *)lista->v[j])->denumire[0] == litera[0]) {
            if (i == aux->capacitate)
            {
                redim(aux);
            }
            aux->v[i] = lista->v[j];
            i++;
        }
    }
    aux->lungime = i;
}

void filtr_cantitate(Lista *lista, Lista* aux, int cant) {
    int i = 0;
    for (int j = 0; j < lista->lungime; j++)
    {
        if ( ((Produs*)lista->v[j])->cantitate < cant) {
            if(i == aux->capacitate)
            {
                redim(aux);
            }
            aux->v[i] = lista->v[j];
            i++;
        }
    }
    aux->lungime = i;
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