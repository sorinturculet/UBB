#include "Dictionar.h"
#include "IteratorDictionar.h"
#include <utility>
#include<vector>
using namespace std;
/*
 * Complexitate:
 * Overall: Theta(1)
 */
Nod::Nod(TElem e, Pnod urm) {
    this->e=e;
    this->urm=urm;
}

TElem Nod::elem() {
    return e;
}

Pnod Nod::urmator() {
    return urm;
}
/*
 * Complexitate
 * Overall: Theta(n) - parcurg sirul,iar pushback are Theta(1);
 */
vector<TValoare> Dictionar::colecțiaValorilor() const {
    vector<TValoare> valori;
    Pnod p=primul;
    while(p!= nullptr){
        valori.push_back(p->elem().second);
        p=p->urmator();
    }
    return valori;
}
/*
 * Complexitate:
 * Overall: Theta(1)
 */
Dictionar::Dictionar() {
    primul= nullptr;
    ultimul= nullptr;
    n=0;
}
/*
 * Complexitate:
 * Overall: Theta(n), trece prin fiecare nod
 */
Dictionar::~Dictionar() {
	Pnod p=primul;
    while(p!= nullptr){
        Pnod urm=p->urmator();
        delete p;
        p=urm;
        n--;
    }
}
/*
 * Complexitate:
 * BC: Theta(1) - prima poz
 * WC: Theta(n) - nu exista cheia
 * AC: Theta(n)
 * Overall: Theta(n)
 */
TValoare Dictionar::adauga(TCheie c, TValoare v){
	if(primul== nullptr) {
        primul = new Nod(TElem(c, v), nullptr);
        ultimul = primul;
        n++;
        return NULL_TVALOARE;
    }
    //cazul in care exista in disctionar
    Pnod p=primul;
    while(p!= nullptr){
        if(p->elem().first==c){
            TValoare old=p->elem().second;
            TElem nou= TElem (c,v);
            p->e=nou;
            return old;
        }
        p=p->urmator();
    }
    //am ajuns cand daca nu exista , deci adaugam la final
    Pnod actual= new Nod(TElem (c,v), nullptr);
    ultimul->urm=actual;
    ultimul=actual;
    n++;
	return NULL_TVALOARE;
}

/*
 * Complexitate:
 * BC: Theta(1) - prima poz
 * WC: Theta(n) - nu exista cheia
 * AC: Theta(n)
 * Overall: Theta(n)
 */

//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare Dictionar::cauta(TCheie c) const{
    Pnod p=primul;
    while(p!= nullptr && p->elem().first!=c){
        p=p->urmator();
    }
    if(p== nullptr)
        return NULL_TVALOARE;
    else
        return p->elem().second;
}

/*
 * Complexitate:
 * BC: Theta(1) - prima pozitie contine cheia
 * WC: Theta(n) - nu exista cheia
 * AC: Theta(n)
 * Overall: Theta(n)
 */
TValoare Dictionar::sterge(TCheie c){
    Pnod p=primul;
    if(dim()==0){
        return NULL_TVALOARE;
    }
    if(p->elem().first==c && primul==ultimul){
        TValoare old=p->elem().second;

        delete primul;
        primul= nullptr;
        ultimul=nullptr;

        n=0;
        return old;
    }
    if(p->elem().first==c && dim()>1){
        TValoare old=p->elem().second;

        Pnod next=primul->urmator();
        delete primul;
        primul=next;
        n--;

        return old;
    }

    while(p!= nullptr && p->elem().first!=c){
        if(p->urm!= nullptr)
            if(p->urm->elem().first==c)
            {//daca urmatorul are cheia buna, avem 2 cazuri, este sau nu ultimul
                if(p->urm==ultimul)
                {
                    TValoare old=p->urm->elem().second;

                    delete ultimul;
                    ultimul=p;
                    n--;

                    return old;
                }
                else
                {
                    TValoare old=p->urm->elem().second;

                    Pnod next=p->urmator()->urmator();
                    delete p->urmator();
                    p->urm=next;
                    n--;

                    return old;
                }
            }
        p=p->urmator();
    }
    //n-am gasit
    return NULL_TVALOARE;


}
/*
 * Complexitate:
 * Overall: Theta(1)
 */
int Dictionar::dim() const {
	return n;
}
/*
 * Complexitate:
 * Overall: Theta(1)
 */
bool Dictionar::vid() const{
	if(n==0)
	    return true;
    return false;
}
/*
 * Complexitate:
 * Overall: Theta(1)
 */
IteratorDictionar Dictionar::iterator() const {
	return  IteratorDictionar(*this);
}




