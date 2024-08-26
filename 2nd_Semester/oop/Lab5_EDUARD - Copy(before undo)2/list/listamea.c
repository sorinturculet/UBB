#include "listamea.h"
#include <stdlib.h>

void addToList(Lista* lista, ElemType p)
{
	if (lista->lungime == lista->capacitate) redim(lista);

	lista->v[lista->lungime] = p;
	if(lista->v[lista->lungime] != NULL)
		lista->v[lista->lungime] = p;
	
	lista->lungime++;
}
void removeFromList(Lista *lista, int index) {
    free(((Produs*)lista->v[index])->denumire);
    free(((Produs*)lista->v[index])->producator);
    free(((Produs*)lista->v[index]));
    for (int i = index; i < lista->lungime; i++)
    {
        lista->v[i] = lista->v[i + 1];
    }
    lista->lungime--;
}

			
void destroy(Lista* l)
{
	for (int i = 0; i < l->lungime; i++)
	{
        destroyPr(l->v[i]);
	}
	eliberator(l);

}
void destroyUndo(Lista* l)
{
    for(int i=0;i<l->lungime;i++)
        destroy(l->v[i]);
    eliberator(l);
}

void eliberator(Lista* l)
{
    free(l->v);
    l->lungime = 0;
    l->capacitate = 0;
    free(l);
}

void redim(Lista* l)
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

Lista* createList()
{
    Lista* lista=(Lista*)malloc(sizeof (Lista));
	lista->lungime = 0;
	lista->capacitate = 1;
	lista->v = (ElemType *)malloc(sizeof(ElemType ) * lista->capacitate);
    return lista;
}