#pragma once
#ifndef LISTAMEA_h
#define LISTAMEA_h
#include"domain/domain.h"
typedef void* ElemType;
	typedef struct {
		ElemType* v;
		int lungime;
		int capacitate;
        void (*destroyElement)(void*);
	} MyList;

	// lista - MyList
	// p - produs
	// Functia addToList un nou produs in lista
	void addToList(MyList* lista, ElemType p);

	// lista - MyList
	// Functia initializeaza o noua lista vida
	MyList* createList(void (*destroyElement)(void*));

	// lista - MyList
	// Functia redimensioneaza lista
	void redim(MyList* l);

	// lista - MyList
	// Functia distruge lista
	void destroyList(MyList* l);
    //elibereaza lista
    void eliberator(MyList* l);
    //face o copie la o lista
    MyList* copyList(MyList* l);
#endif