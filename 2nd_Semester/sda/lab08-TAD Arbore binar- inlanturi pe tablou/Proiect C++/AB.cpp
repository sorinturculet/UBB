#include "AB.h"
#include "IteratorAB.h"
#include <exception>
#include <string>
#include <iostream>
/*
 * Complexitate
 * Theta(n)// se parcurge tot arborele
 */
TElem AB::elementMinim() {
    if (this->vid())
        throw exception();
    TElem minim = this->element();
    IteratorAB* iab = this->iterator("inordine");
    iab->prim();
    while (iab->valid()) {
        TElem e = iab->element();
        if(e<minim)
            minim=e;
        iab->urmator();
    }
    return minim;
}
void AB::print() {
    for(int i=0;i<cap;i++)
        cout<<i<<" ";
    cout<<endl;
    for(int i=0;i<cap;i++)
        cout<<v[i]<<" ";
    cout<<endl;
    for(int i=0;i<cap;i++)
        cout<<stanga[i]<<" ";
    cout<<endl;
    for(int i=0;i<cap;i++)
        cout<<dreapta[i]<<" ";
    cout<<endl;
    cout<<"Radacina: "<<radacina<<endl;
    cout<<"PrimLiber: "<<primLiber<<endl;
}
/*
 * Complexitate
 * Theta(3=cap)
 */
AB::AB() {
	this->cap=3;
    this->primLiber=0;
    this->v=new TElem[cap];
    for(int i=0;i<cap;i++)
        this->v[i]=-1;
    this->stanga=new int[cap];
    this->dreapta=new int[cap];
    this->radacina=-1;

}
/*
 * Complexitate
 * Theta(n)
 */
AB::AB(const AB& ab) {
	this->cap=ab.cap;
    this->primLiber=ab.primLiber;
    this->v=new TElem[cap];
    for(int i=0;i<cap;i++)
        this->v[i]=-1;
    this->stanga=new int[cap];
    this->dreapta=new int[cap];
    this->radacina=ab.radacina;
    for(int i=0;i<cap;i++){
        this->v[i]=ab.v[i];
        this->stanga[i]=ab.stanga[i];
        this->dreapta[i]=ab.dreapta[i];
    }


}
/*
 * Complexitate
 * Theta(3==cap)
 */
AB::AB(TElem e){
    this->cap=3;
    this->primLiber=1;
    this->v=new TElem[cap];
    for(int i=0;i<cap;i++)
        this->v[i]=-1;
    this->stanga=new int[cap];
    this->dreapta=new int[cap];
    this->radacina=0;
    this->v[radacina]=e;
    this->stanga[radacina]=-1;
    this->dreapta[radacina]=-1;
}
/*
 * Complexitate
 * Theta(n)
 */
AB::AB(const AB& st, TElem e, const AB& dr){
    this->cap=3;
    this->primLiber=1;
    this->v=new TElem[cap];
    for(int i=0;i<cap;i++)
        this->v[i]=-1;
    this->stanga=new int[cap];
    this->dreapta=new int[cap];
    this->radacina=0;
    this->v[radacina]=e;
    this->stanga[radacina]=-1;
    this->dreapta[radacina]=-1;
    adaugaSubSt(st);
    adaugaSubDr(dr);

}
//redimensionare vector dinamic
void AB::aloca(){
    if(primLiber==cap){
        cap*=2;
        auto* v2=new TElem[cap];
        int* stanga2=new int[cap];
        int* dreapta2=new int[cap];
        for(int i=0;i<cap/2;i++){
            v2[i]=v[i];
            stanga2[i]=stanga[i];
            dreapta2[i]=dreapta[i];
        }
        for(int i=cap/2;i<cap;i++){
            v2[i]=-1;
            stanga2[i]=-1;
            dreapta2[i]=-1;
        }
        delete []v;
        delete []stanga;
        delete []dreapta;
        v=v2;
        stanga=stanga2;
        dreapta=dreapta2;
    }
    primLiber=cap/2;
}
void AB::updatePrimLiber(){
    while(primLiber<cap && v[primLiber]!=-1)
        primLiber++;
    if(primLiber==cap)
        aloca();
}
void AB::distruge(int nod){
    if(nod!=-1){
        distruge(stanga[nod]);
        distruge(dreapta[nod]);
        if(primLiber>nod)
            primLiber=nod;
        this->v[nod]=-1;
    }
}
/*
 * Complexitate
 * Theta(n)-n dim arborelui
 */
//Copiaza tabela subarborelui, in arborele actual
void AB::copiazaSubArbore(const AB& st, int nod) {
    if(nod != -1) {
        int newNod = primLiber;
        this->v[newNod] = st.v[nod];

        if(st.stanga[nod] != -1) {
            updatePrimLiber();
            this->stanga[newNod] = primLiber;
            copiazaSubArbore(st, st.stanga[nod]);
        } else {
            this->stanga[newNod] = -1;
        }

        if(st.dreapta[nod] != -1) {
            updatePrimLiber();
            this->dreapta[newNod] = primLiber;
            copiazaSubArbore(st, st.dreapta[nod]);
        } else {
            this->dreapta[newNod] = -1;
        }
    }
    updatePrimLiber();
}
void AB::copiazaArbore(const AB& st,int nod){
    if(nod==-1)
        radacina=-1;
    else
        radacina=0;
    copiazaSubArbore(st,nod);
}
/*
 * Complexitate
 * Theta(n)-n dim arborelui
 */
void AB::adaugaSubSt(const AB& st){
    if(st.radacina==-1)//este vid
        return;

    distruge(this->stanga[radacina]);//distrugem arborele existent din stanga
    //updatam tabela astfel: copiem toata tabela(vezi copiaza SubArbore), si dupa o conectam
    // la radacina prin asocierea ei in vectorul STANGA.
    int fostprimliber=primLiber;
    copiazaSubArbore(st,st.radacina);
    this->stanga[radacina]=fostprimliber;

}
/*
 * Complexitate
 * Theta(n)-n dim arborelui
 */
void AB::adaugaSubDr(const AB& dr){
    if(dr.radacina==-1)//este vid
        return;

    distruge(this->dreapta[radacina]);//distrugem arborele existent din stanga
    //updatam tabela astfel: copiem toata tabela(vezi copiaza SubArbore), si dupa o conectam
    // la radacina prin asocierea ei in vectorul STANGA.
    int fostprimliber=primLiber;
    copiazaSubArbore(dr,dr.radacina);
    this->dreapta[radacina]=fostprimliber;
}
/*
 * Complexitate
 * Theta(1)
 */
TElem AB::element() const{
 	if(this->radacina==-1)
        throw exception();
     return this->v[radacina];
}
/*
 * Complexitate
 * Theta(n)-n dim arborelui
 */
AB AB::stang() const{
    AB arbore;
    if(this->vid())
        throw exception();
    if(this->stanga[radacina]!=-1)
        arbore.radacina=0;
    arbore.copiazaArbore(*this,this->stanga[radacina]);
    return arbore;
}
/*
 * Complexitate
 * Theta(n)-n dim arborelui
 */
AB AB::drept() const{
    AB arbore;
    if(this->vid())
        throw exception();
    if(this->dreapta[radacina]!=-1)
        arbore.radacina=0;
    arbore.copiazaArbore(*this,this->dreapta[radacina]);
    return arbore;
}
/*
 * Complexitate
 * Theta(1)
 */
AB::~AB() {
	delete []v;
    delete []stanga;
    delete []dreapta;
}
/*
 * Complexitate
 * Theta(1)
 */
bool AB::vid() const{
	if(radacina==-1)
        return true;
    return false;
}


IteratorAB* AB::iterator(string s) const {
	if (s=="preordine")
		return new IteratorPreordine(*this);
	if (s=="inordine")
		return new IteratorInordine(*this);
	if (s=="postordine")
		return new IteratorPostordine(*this);
	if (s=="latime")
		return new IteratorLatime(*this);
	return nullptr;
};
