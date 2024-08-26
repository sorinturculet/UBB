#pragma once
#ifndef LISTAMEA_h
#define LISTAMEA_h
#include"domain/domain.h"
typedef void* ElemType;
	typedef struct {
		ElemType* v;
		int lungime;
		int capacitate;
        void(*destroyElement)(void*);
	} Lista;

	// lista - Lista
	// p - produs
	// Functia addToList un nou produs in lista
	void addToList(Lista* lista, ElemType p);
    // lista - Lista
    // index - int
    // Functia sterge elementul de pe pozitia index din lista
    void removeFromList(Lista* lista, int index);
	// lista - Lista
	// Functia initializeaza o noua lista vida
	Lista* createList();

	// lista - Lista
	// Functia redimensioneaza lista
	void redim(Lista* l);

	// lista - Lista
	// Functia distruge lista
	void destroy(Lista* l);
    //elibereaza lista
    void eliberator(Lista* l);
#endif