#include "Matrice.h"
#include <exception>
//#include<iostream>
using namespace std;


Matrice::Matrice(int m, int n) {
    this->nrLines = m;
    this->nrCols=n;
    this->l=0;
    this->cap=2;

    cols=new int[n+1];
    for(int i=0;i<=n;i++)
        cols[i]=0;

    lines=new int[cap];
    values=new TElem[cap];
}
Matrice::~Matrice(){
    delete[] cols;
    delete[] lines;
    delete[] values;
}

//void Matrice::PRINT(){
//    for(int i=0;i<=nrCols;i++)
//        cout<<cols[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<this->l;i++)
//        cout<<lines[i]<<" ";
//    cout<<endl;
//    for(int i=0;i<this->l;i++)
//        cout<<values[i]<<" ";
//    cout<<endl<<endl;
//}

int Matrice::nrLinii() const{
	return nrLines;

}


int Matrice::nrColoane() const{
	return nrCols;
}


TElem Matrice::element(int i, int j) const{
	if(i<0 || j<0 || i>=nrLines || j>=nrCols)
        throw exception();
    for(int element=cols[j];element<cols[j+1];element++){
        if(this->lines[element]==i){
            return this->values[element];
        }
    }
    return NULL_TELEMENT;
}
//complexitate
void Matrice::Transpusa(){
    Matrice Tr(this->nrCols,this->nrLines);
    for(int i=0;i<this->nrLines;i++)
        for(int j=0;j<this->nrCols;j++)
        {
            if(element(i,j)!=NULL_TELEMENT)
                Tr.modifica(j,i, this->element(i,j));
        }

    this->nrLines = Tr.nrLines;
    this->nrCols = Tr.nrCols;
    this->cap = Tr.cap;
    this->l = Tr.l;
    this->cols = new int[Tr.nrCols+1];
    this->lines = new int[Tr.nrLines];
    this->values = new TElem[Tr.cap];

    for(int i=0; i<=this->nrCols; i++)
        this->cols[i] = Tr.cols[i];
    for(int i=0; i<this->l; i++){
        this->lines[i] = Tr.lines[i];
        this->values[i] = Tr.values[i];
    }

}


TElem Matrice::modifica(int i, int j, TElem e) {
    if(i<0 || j<0 || i>nrLines || j>nrCols)
        throw exception();
    //vector dinamic cu redimensionare.
    if(this->cap==this->l){
        this->cap*=2;
        int* newLines=new int[this->cap];
        int* newValues=new TElem[this->cap];
        for(int indice=0;indice<this->l;indice++){
            newLines[indice]=this->lines[indice];
            newValues[indice]=this->values[indice];
        }
        delete[] this->lines;
        delete[] this->values;
        this->lines=newLines;
        this->values=newValues;
    }
    //verificam daca elementul exista deja.
    bool found=false;
    for(int element=cols[j];element<cols[j+1];element++){
        if(this->lines[element]==i){
            found=true;
            this->values[element]=e;
        }
    }
    //elementul nu exista deci trebuie adaugat
    if(!found){
        int element=cols[j];
        while(element<cols[j+1] && this->lines[element]<i){//gasim unde trebuie inserat elementul
            element++;
        }
        for(int k=this->l;k>=element;k--) {//mutam tot la dreapta pentru a face loc elementului.
            this->lines[k + 1] = this->lines[k];
            this->values[k+1]=this->values[k];
        }
        this->lines[element]=i;
        this->values[element]=e;
        this->l++;

        for(int k=nrCols+1;k>j;k--)//incrementam coloanele la final.
            cols[k]++;

    }
	return e;
}


