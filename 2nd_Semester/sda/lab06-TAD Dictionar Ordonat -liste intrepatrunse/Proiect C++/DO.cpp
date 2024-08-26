#include "Iterator.h"
#include "DO.h"
#include <iostream>

#include <exception>
using namespace std;

int hashCode(TCheie e){
//ptr moment numarul e intreg
    return abs(e);
}

int DO::d(TCheie c) const{
    //HASHCODE
    return hashCode(c) % m;
}
DO::DO(Relatie r) {
    m = MAX;
    v = new TElem[m];
    urm = new int[m];
    primLiber = 0;
    rel = r;
    for(int i = 0; i < m; i++) {
        v[i] = std::make_pair(-1, -1);
        urm[i] = -1;
    }
}
/*
 * Complexitate
 * O(n)
 * WC- Nu exista si toate cheile sunt in dispersie pe aceeasi pozitie ca cea cautata
 * AG 0(1)- Dispersia este uniforma
 */
//adauga o pereche (cheie, valoare) in dictionar
//daca exista deja cheia in dictionar, inlocuieste valoarea asociata cheii si returneaza vechea valoare
//daca nu exista cheia, adauga perechea si returneaza null
TValoare DO::adauga(TCheie c, TValoare val) {
	TElem e=std::make_pair(c,val);
    int i=d(c);
    if(v[i].first == -1){// pozitia este libera
        v[i] = e;
        if(i == primLiber)
            actPrimLiber();
        return NULL_TVALOARE;
    }

    int j = -1;	// j va retine pozitia precedenta lui i, pentru a putea reface inlantuirea
    // daca pozitia nu este libera
    while (i != -1 and v[i].first!=c)	// iteram pana gasim capatul inlantuirii
    {
        j = i;
        i = urm[i];
    }
    // adaugam elementul
    if(i!=-1){//cheia exista
        TValoare valoare = v[i].second;
        v[i].second = val;
        return valoare;
    }
    //cheia nu exista,trebuie adaugata.
    if (primLiber >= m)
        throw std::exception(); //nu tratam depasirea tabelei
    //adaugam elementul, in primul spatiu liber.
    v[primLiber] = e;
    urm[j] = primLiber;
    actPrimLiber();
	return NULL_TVALOARE;
}
/*
 * Complexitate
 * O(n)
 * WC- Nu exista si toate cheile sunt in dispersie pe aceeasi pozitie ca cea cautata
 * AG 0(1)- Dispersia este uniforma
 */
//cauta o cheie si returneaza valoarea asociata (daca dictionarul contine cheia) sau null
TValoare DO::cauta(TCheie c) const {
	int i=d(c);
    while(i != -1){//cautam in locatia de dispersie
        if(v[i].first == c)
            return v[i].second;
        i = urm[i];
    }
    //nu exista(i=-1), deci returnam NULL_TVALOARE
	return NULL_TVALOARE;	
}
/*
 * Complexitate
 * O(n)
 * WC- Nu exista si toate cheile sunt in dispersie pe aceeasi pozitie ca cea cautata.
 * AG 0(1)- Dispersia este uniforma
 */
//sterge o cheie si returneaza valoarea asociata (daca exista) sau null
TValoare DO::sterge(TCheie c) {
    int i = d(c);
    int j = -1;
    int k=0;
    while(k<m and urm[k]!=i)
        k++;
    if(k<m)
        j=k;
    while(i != -1 and v[i].first != c){//cautam elementul
        j = i;
        i = urm[i];
    }
    if(i == -1)
        return NULL_TVALOARE;
    else
    {
        bool gata = false;
        TValoare valoare = v[i].second;
        do{
            int p=urm[i];
            int pp=i;
            while(p!=-1 and d(v[p].first)!=i){
                pp=p;
                p=urm[p];
            }
            if(p==-1)
                gata=true;
            else{
                v[i]=v[p];
                i=p;
                j=pp;
            }
        }while(!gata);
        if(j!=-1)
            urm[j]=urm[i];
        std::pair<int,int> pereche = std::make_pair(-1,-1);
        v[i] = pereche;
        urm[i] = -1;

        if(i < primLiber)
            primLiber = i;
        return valoare;
    }
}
/*
 * Complexitate
 * O(m)
 * BC- 0(1)-dictionarul este plin
 * WC- 0(m)-dictionarul este gol
 */
//returneaza numarul de perechi (cheie, valoare) din dictionar
int DO::dim() const {
	int size=primLiber;
    int i=primLiber;
    while(i<m){
        if(v[i].first != -1)
            size++;
        i++;
    }
	return size;
}

//verifica daca dictionarul e vid
bool DO::vid() const {
	if(this->dim() == 0)
	    return true;
    return false;
}

Iterator DO::iterator() const {
	return  Iterator(*this);
}
/* Complexitate
* O(n)
* WC- Nu exista si toate cheile sunt in dispersie pe aceeasi pozitie ca cea cautata
* AG 0(1)- Dispersia este uniforma
*/
// înlocuiește valoarea mapate în prezent cheii k cu valoarea valoareNoua, dar numai în cazul în care valoarea curentă este egală cu valoareVeche.
void DO::inlocuieste (TCheie k, TValoare valoareVeche, TValoare valoareNoua){
    int i=d(k);
    //cautam elementul
    while(i != -1 and v[i].first != k)
        i = urm[i];
    if(i == -1 || v[i].second != valoareVeche)
        return;
    v[i].second = valoareNoua;
}
void DO::print() const {
    cout<<"Dictionarul este:";
    for(int i = 0; i < m; i++) {
        if(v[i].first != -1)
            std::cout << v[i].first << " " << v[i].second << std::endl;
    }

}
DO::~DO() {
	delete[] v;
    delete[] urm;
}
