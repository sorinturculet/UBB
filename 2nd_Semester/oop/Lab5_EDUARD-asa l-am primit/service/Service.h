#pragma once
#include "list/listamea.h"

// lista - Lista
// nume - char []
// prod - char []
// cant - int
// Functia creaza un nou produs cu atributele: nume, prod, cant si il addToList in lista
void add(Lista *lista, char nume[], char prod[], int cant);

// lista - Lista
// nume - char []
// Functia cauta in lista variabila nume[]
int cauta(Lista* lista, char nume[]);

// lista - Lista
// nume - char []
// cant - int
// index - int
// Functia addToList la cantitatea initiala cantitatea nou introdusa cant, in lista pe pozitia index
void update(Lista* lista, int cant, int index);



// lista - Lista
// i - int
// j - int
// Functiile compara elementele de pe pozitia i si j din lista in functie de optiune si criteriu
int criteriu_nume_cresc(Produs a, Produs b);
int criteriu_nume_descr(Produs a, Produs b);
int criteriu_cant_cresc(Produs a, Produs b);
int criteriu_cant_descr(Produs a, Produs b);

// lista - Lista
// optiune - int
// monotonie - int
// Functia ordoneazaz elementele in functie de optiune si monotonie
// optiune - 1 == nume
// optiune - 2 == cantitate
// monotonie - 1 == crescator
// monotonie - 2 == descrescator
void ordonare(Lista* l, Lista* aux, int(*func)(Produs , Produs));

// lista - Lista
// index - int
// cant - int
// Functia modifica cantitatea de pe pozitia index din lista
void modificare(Lista* l, int index, int cant);

// lista - Lista
// litera - char[]
// Functia returneaza o lista cu toate instantele care contin litera litera[0] in denumire
void filtr_litera(Lista* lista, Lista* aux, char litera[]);

// lista - Lista
// cant - int
// Functia returneaza o lista cu toate instantele care contin o cantitate mai mica decat cea data in variabila cant
void filtr_cantitate(Lista* l, Lista* aux, int cant);

int validare_nume(char nume[]);
int validare_producator(char producator[]);
int validare_cantitate(int cantitate);