#include "Teste.h"
#include <assert.h>
#include "service/Service.h"
#include <string.h>
#include "list/listamea.h"

void test_adaugare()
{
    ManagerLists store=createManagerList();
	add(&store, "Zahar", "Tarom", 100);
	add(&store, "Sare", "Wizz", 200);
	add(&store, "Miere", "Asus", 300);
	destroyManagerList(&store);
}

void test_cautare()
{
	ManagerLists store=createManagerList();
    add(&store, "Zahar", "Tarom", 100);
	add(&store, "Sare", "Wizz", 200);
	add(&store, "Miere", "Asus", 300);
	assert(cauta(&store, "Miere") == 2);
	assert(cauta(&store, "Paine") == -1);
    destroyManagerList(&store);
}

void test_update()
{
    ManagerLists store=createManagerList();
    add(&store, "Zahar", "Tarom", 100);
	int index = cauta(&store, "Zahar");
	update(&store, 150, index);
	assert(((Produs*)store.l->v[0])->cantitate == 250);
    destroyManagerList(&store);
}

void test_remove()
{
    ManagerLists store=createManagerList();
    add(&store, "Zahar", "Tarom", 100);
	add(&store, "Sare", "Wizz", 200);
	add(&store,"Miere", "Asus", 300);
	int index = cauta(&store, "Zahar");
	remove_prod(&store, index);
	assert(store.l->lungime == 2);
    destroyManagerList(&store);
}

void test_ordonare() {
    ManagerLists store=createManagerList();
    add(&store,"Zahar", "Tarom", 100);
	add(&store,"Sare", "Wizz", 200);
	add(&store,"Miere", "Asus", 300);

	MyList* aux= createList((void (*)(void *)) destroyPr);
	ordonare(&store, aux, criteriu_nume_cresc);
	assert(strcmp(((Produs*)aux->v[0])->denumire, "Miere") == 0);
    destroyList(aux);

    aux= createList((void (*)(void *)) destroyPr);
	ordonare(&store, aux, criteriu_nume_descr);
	assert(strcmp(((Produs*)aux->v[0])->denumire, "Zahar") == 0);
    destroyList(aux);

	aux= createList((void (*)(void *)) destroyPr);
	ordonare(&store, aux, criteriu_cant_cresc);
	assert(((Produs*)aux->v[0])->cantitate == 100);
    destroyList(aux);

	aux= createList((void (*)(void *)) destroyPr);
	ordonare(&store, aux, criteriu_cant_descr);
	assert(((Produs*)aux->v[0])->cantitate == 300);
    destroyList(aux);

    destroyManagerList(&store);
}

void test_modificare() {
    ManagerLists store=createManagerList();
    add(&store, "Zahar", "Tarom", 100);
	add(&store, "Sare", "Wizz", 200);
	add(&store, "Miere", "Asus", 300);

	int index = cauta(&store, "Sare");
	modificare(&store, index, 150);
	assert(((Produs*)store.l->v[index])->cantitate == 150);
    destroyManagerList(&store);
}

void test_filtrLit() {
    ManagerLists store=createManagerList();
    add(&store, "Zahar", "Tarom", 100);
	add(&store,"Sare", "Wizz", 200);
	add(&store,"Zanzibar", "Bolt", 150);
	add(&store,"Miere", "Asus", 300);
	MyList* aux= createList((void (*)(void *)) destroyPr);

	filtr_litera(&store, aux, "Z");
	assert(aux->lungime == 2);
	eliberator(aux);

	aux= createList((void (*)(void *)) destroyPr);
	filtr_litera(&store, aux, "B");
	assert(aux->lungime == 0);
    eliberator(aux);

    destroyManagerList(&store);
}

void test_filtrCant() {
    ManagerLists store=createManagerList();
    add(&store,"Zahar", "Tarom", 100);
	add(&store,"Sare", "Wizz", 200);
	add(&store,"Miere", "Asus", 300);

	MyList* aux= createList((void (*)(void *)) destroyPr);
	filtr_cantitate(&store, aux, 100);
	assert(aux->lungime == 0);
    eliberator(aux);

	aux= createList((void (*)(void *)) destroyPr);
	filtr_cantitate(&store, aux, 400);
	assert(aux->lungime == 3);
    eliberator(aux);

    destroyManagerList(&store);
}
void test_filtrProd() {
    ManagerLists store=createManagerList();
    add(&store,"Zahar", "Tarom", 100);
    add(&store,"Sare", "Tarom", 200);
    add(&store,"Miere", "Asus", 300);

    MyList* aux= createList((void (*)(void *)) destroyPr);
    filtr_producator(&store, aux, "Tarom");
    assert(aux->lungime == 2);
    eliberator(aux);

    aux= createList((void (*)(void *)) destroyPr);
    filtr_producator(&store, aux, "asus");
    assert(aux->lungime == 0);
    eliberator(aux);

    destroyManagerList(&store);
}
void test_validare()
{
	assert(validare_cantitate(500));
	assert(!validare_cantitate(-100));
	assert(validare_nume("Zahar"));
	assert(!validare_nume("Ae"));
	assert(validare_producator("Tarom"));
	assert(!validare_producator("Ae"));
}
void test_liste_liste()
{
    MyList* l= createList((void (*)(void *)) destroyPr);
    MyList* undo= createList((void (*)(void *)) destroyPr);
    addToList(undo, l);
    assert(l->lungime==0);
    assert(undo->lungime==1);
    addToList(l, crearePr("zahar","producator",7));
    assert(l->lungime==1);
    assert(undo->lungime==1);
    destroyList(l);
    eliberator(undo);
}
//void printAll2(MyList* lista){
//    for (int j = 0; j < lista->lungime; j++)
//        printf("%s -- %s -- %d\n", ((Produs*)lista->v[j])->denumire, ((Produs*)lista->v[j])->producator, ((Produs*)lista->v[j])->cantitate);
//
//}
//void printAll3(MyList* undo){
//    for (int j = 0; j < undo->lungime; j++)
//        printAll2(undo->v[j]);
//}
void test_undo()
{
    ManagerLists store=createManagerList();

    add(&store, "zahar","producator",7);
    add(&store, "zahar","producator",7);
    assert(store.l->lungime==2);

    undoFunction(&store);
    assert(store.l->lungime==1);
    undoFunction(&store);
    assert(store.l->lungime==0);
    assert(undoFunction(&store)==1);

    add(&store, "zahar", "producator", 100);
    int index = cauta(&store, "zahar");

    update(&store, 150, index);
    assert(((Produs*)store.l->v[0])->cantitate == 250);
    undoFunction(&store);
    assert(((Produs*)store.l->v[0])->cantitate == 100);

    index = cauta(&store, "zahar");
    remove_prod(&store,index);
    assert(store.l->lungime==0);
    undoFunction(&store);
    assert(cauta(&store, "zahar")==0);
    assert(store.l->lungime==1);
    destroyManagerList(&store);
}
