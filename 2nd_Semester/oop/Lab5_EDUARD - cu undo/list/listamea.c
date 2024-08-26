#include "listamea.h"
#include <stdlib.h>

void addToList(MyList* lista, ElemType p)
{
	if (lista->lungime == lista->capacitate) redim(lista);

	lista->v[lista->lungime] = p;
	if(lista->v[lista->lungime] != NULL)
		lista->v[lista->lungime] = p;
	
	lista->lungime++;
}

			
void destroyList(MyList* l)
{
	for (int i = 0; i < l->lungime; i++)
	{
        l->destroyElement(l->v[i]);
	}
	eliberator(l);

}
void eliberator(MyList* l)
{
    free(l->v);
    l->lungime = 0;
    l->capacitate = 0;
    free(l);
}

void redim(MyList* l)
{
    int new_cap = l->capacitate * 2;
    ElemType * aux = malloc(sizeof(ElemType ) * new_cap);
    for (int i = 0; i < l->lungime; ++i) {
        aux[i] = l->v[i];
    }
    free(l->v);
    l->v = aux;
    l->capacitate = new_cap;

}

MyList* createList(void (*destroyElement)(void*))
{
    MyList* lista=(MyList*)malloc(sizeof (MyList));
	lista->lungime = 0;
	lista->capacitate = 1;
	lista->v = (ElemType *)malloc(sizeof(ElemType ) * lista->capacitate);
    lista->destroyElement=destroyElement;
    return lista;
}
#include<stdio.h>
MyList* copyList(MyList* l)
{
    MyList* copy= createList(l->destroyElement);
    for(int i=0;i<l->lungime;i++)
    {
        addToList(copy, duplicatePr(l->v[i]));
    }
    return copy;
}