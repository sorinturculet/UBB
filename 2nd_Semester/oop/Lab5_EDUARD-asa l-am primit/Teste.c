#include "Teste.h"
#include <assert.h>
#include "service/Service.h"
#include <string.h>
#include "list/listamea.h"

void test_adaugare()
{
	Lista* lista= createList();
	add(lista, "Zahar", "Tarom", 100);
	add(lista, "Sare", "Wizz", 200);
	add(lista, "Miere", "Asus", 300);
	assert(lista->lungime == 3);
    destroy(lista);
}

void test_cautare()
{
	Lista* lista= createList();
	add(lista, "Zahar", "Tarom", 100);
	add(lista, "Sare", "Wizz", 200);
	add(lista, "Miere", "Asus", 300);
	assert(cauta(lista, "Miere") == 2);
	assert(cauta(lista, "Paine") == -1);
    destroy(lista);
}

void test_update()
{
	Lista* lista= createList();
	add(lista, "Zahar", "Tarom", 100);
	int index = cauta(lista, "Zahar");
	update(lista, 150, index);
	assert(((Produs*)lista->v[0])->cantitate == 250);
    destroy(lista);
}

void test_remove()
{
	Lista* lista= createList();
	add(lista, "Zahar", "Tarom", 100);
	add(lista, "Sare", "Wizz", 200);
	add(lista, "Miere", "Asus", 300);
	int index = cauta(lista, "Zahar");
    removeFromList(lista, index);
	assert(lista->lungime == 2);
    destroy(lista);
}

void test_ordonare() {
	Lista* lista= createList();
	add(lista, "Zahar", "Tarom", 100);
	add(lista, "Sare", "Wizz", 200);
	add(lista, "Miere", "Asus", 300);

	Lista* aux= createList();
	ordonare(lista, aux, criteriu_nume_cresc);
	assert(strcmp(((Produs*)aux->v[0])->denumire, "Miere") == 0);
    destroy(aux);

    aux= createList();
	ordonare(lista, aux, criteriu_nume_descr);
	assert(strcmp(((Produs*)aux->v[0])->denumire, "Zahar") == 0);
    destroy(aux);

	aux= createList();
	ordonare(lista, aux, criteriu_cant_cresc);
	assert(((Produs*)aux->v[0])->cantitate == 100);
    destroy(aux);

	aux= createList();
	ordonare(lista, aux, criteriu_cant_descr);
	assert(((Produs*)aux->v[0])->cantitate == 300);
    destroy(aux);

    destroy(lista);
}

void test_modificare() {
	Lista* lista= createList();
	add(lista, "Zahar", "Tarom", 100);
	add(lista, "Sare", "Wizz", 200);
	add(lista, "Miere", "Asus", 300);
	int index = cauta(lista, "Zahar");
	modificare(lista, index, 150);
	assert(((Produs*)lista->v[0])->cantitate == 150);
    destroy(lista);
}

void test_filtrLit() {
	Lista* lista= createList();
	add(lista, "Zahar", "Tarom", 100);
	add(lista, "Sare", "Wizz", 200);
	add(lista, "Zanzibar", "Bolt", 150);
	add(lista, "Miere", "Asus", 300);
	Lista* aux= createList();

	filtr_litera(lista, aux, "Z");
	assert(aux->lungime == 2);
	eliberator(aux);

	aux= createList();
	filtr_litera(lista, aux, "B");
	assert(aux->lungime == 0);
    eliberator(aux);

    destroy(lista);
}

void test_filtrCant() {
	Lista* lista= createList();
	add(lista, "Zahar", "Tarom", 100);
	add(lista, "Sare", "Wizz", 200);
	add(lista, "Miere", "Asus", 300);

	Lista* aux= createList();
	filtr_cantitate(lista, aux, 100);
	assert(aux->lungime == 0);
    eliberator(aux);

	aux= createList();
	filtr_cantitate(lista, aux, 400);
	assert(aux->lungime == 3);
    eliberator(aux);

    destroy(lista);
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
    Lista* l= createList();
    Lista* undo= createList();
    addToList(undo, l);
    assert(l->lungime==0);
    assert(undo->lungime==1);
    addToList(l, crearePr("zahar","producator",7));
    assert(l->lungime==1);
    assert(undo->lungime==1);
    destroy(l);
    eliberator(undo);
}
