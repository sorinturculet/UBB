#include "Multime.h"
#include "IteratorMultime.h"

#include <iostream>
using namespace std;
/*
 * Complexitate
 * Theta(n)
 */
void Multime::print() {
    for(int i=0;i<cp;i++)
        cout<<e[i]<<" ";
    cout<<endl;
    for(int i=0;i<cp;i++)
        cout<<urm[i]<<" ";
    cout<<endl;
    for(int i=0;i<cp;i++)
        cout<<prec[i]<<" ";
    cout<<endl;
    cout<<"prim: "<<prim<<" ultim: "<<ultim<<" prim liber: "<<primLiber<<endl;
    cout<<"dimensiune: "<<dim()<<" capacitate :"<<cp<<endl;
}

/*
 * Complexitate
 * Average case-Theta(n), trebuie sa verifice daca exista sau nu element, indiferent dupa este Theta(1) complexitatea adaugarii efective
 *si complexitate amortizata Theta(1) pentru redimensionare.
 */

bool Multime::adauga(TElem elem) {
   //exista deja elementul>
    if (cauta(elem)) {
        return false;
    }

    // este spatiu valabil?
    if (primLiber != -1) {
        int nextliber = urm[primLiber];

        if (prim == -1) {

            e[primLiber] = elem;
            urm[primLiber] = -1;
            prec[primLiber] = -1;

            prim = primLiber;
            ultim = primLiber;
            primLiber = nextliber;
        } else {

            e[primLiber] = elem;
            urm[primLiber] = -1;
            prec[primLiber] = ultim;

            urm[ultim] = primLiber;
            ultim = primLiber;
            primLiber = nextliber;
        }

        return true;
    } else {

        int new_cp = 2 * cp;
        int* e2 = new int[new_cp];
        int* urm2 = new int[new_cp];
        int* prec2 = new int[new_cp];

        // Copiem de avem
        for (int i = 0; i < cp; ++i) {
            e2[i] = e[i];
            urm2[i] = urm[i];
            prec2[i] = prec[i];
        }

        for (int i = cp; i < new_cp; ++i) {
            urm2[i] = i + 1; //refacem pozitiile de ordine
            prec2[i] = i - 1;
        }
        urm2[new_cp - 1] = -1;
        prec2[cp] = -1;


        delete[] e;
        delete[] urm;
        delete[] prec;


        e = e2;
        urm = urm2;
        prec = prec2;


        cp = new_cp;
        primLiber = cp / 2;

        //acum avem spatiu deci poate fi adaugat
        return adauga(elem);
    }
}

/*
 * Complexitate
 * Best case-Theta(1), primul element
 * Worst case-Theta(n), ultimul element
 * Average case- Theta(n)
 */

bool Multime::sterge(TElem elem) {
    if(!cauta(elem))
	    return false;
    //doua posibilitati, stergem primul sau un altul
    //incepem cu primu caz
    if(e[prim]==elem){
        //practic eliberam doar prima loc
        int i=prim;
        prim=urm[prim];
        if(prim!=-1) //
            prec[prim]=-1; //nu are prec

        dealoca(i);

    }
    else{

        int element=prim;
        while(e[element]!=elem) {//sigur se afla, s-a verificat
            element = urm[element];
        }

        urm[prec[element]]=urm[element];
        if (urm[element] != -1) //shiftam lista de urm si prec
            prec[urm[element]] = prec[element];
        dealoca(element);
        //ultimul
    }
    return true;
}

/*
 * Complexitate
 * Best case-Theta(1), primul element
 * Worst case-Theta(n), nu exista/ultimul element
 * Average case- Theta(n)
 */
bool Multime::cauta(TElem elem) const {
    if(vida())
        return false;

	int element=prim;
    while(urm[element]!=-1) {
        if (e[element] == elem)
            return true;
        element = urm[element];
    }

    if(e[element]==elem) //la ultimul nu intra in while.
        return true;
	return false;
}

/*
 * Complexitate
 * Best - Theta(1)- e vida, dar este tot egala cu Theta(n), n=1 deci Theta(n)
 * Complexitate
 * Theta(n), trece prin fiecare nod.
 */
int Multime::dim() const {

	if(vida())
	    return 0;
    int element=prim;
    int numberof=1;
    while(urm[element]!=-1) {
        element = urm[element];
        numberof++;
    }
    return numberof;
}
/*
 * Complexitate
 * Theta(1)
 */
bool Multime::vida() const {
	if(prim==-1)
	    return true;
    return false;
}

/*
 * Complexitate
 * Theta(n)-trece prin fiecare element al multimii
 */
int Multime::diferentaMaxMin() const{
    if(vida())
        return -1;
    int element=prim;
    int min=e[prim];
    int max=e[prim];
    while(urm[element]!=-1) {
        element = urm[element];
        if(min>e[element])min=e[element];
        if(max<e[element])max=e[element];
    }
    return max-min;

}
/*
 * Complexitate
 * Theta(1)
 */
IteratorMultime Multime::iterator() const {
	return IteratorMultime(*this);
}

