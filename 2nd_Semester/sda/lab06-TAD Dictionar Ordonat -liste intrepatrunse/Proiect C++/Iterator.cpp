#include <exception>
#include <iostream>
#include "Iterator.h"
#include "DO.h"

using namespace std;

//void Iterator::deplasare() {
//    while (curent < dict.m && dict.v[curent].first == NULL_TVALOARE) {
//        curent++;
//    }
//}
Iterator::Iterator(const DO& d) : dict(d){
    elements = new TCheie[dict.m];
    int indice=0;
    for(int i=0;i<dict.m;i++){
        if(dict.v[i].first!=NULL_TVALOARE){
            elements[indice]=dict.v[i].first;
            indice++;
        }
    }
    //sortam vectorul cheilor
    for(int i=0;i<indice-1;i++){
        for(int j=i+1;j<indice;j++){
            //folosim ordinea dictionarului
            if(!dict.rel(elements[i],elements[j])){
                TCheie aux=elements[i];
                elements[i]=elements[j];
                elements[j]=aux;
            }
        }
    }
    size=indice;
    curent=0;
}

void Iterator::prim(){
	curent=0;
}

void Iterator::urmator(){

    curent++;
    //else throw std::exception();
}

bool Iterator::valid() const{
	return curent<size;
}

TElem Iterator::element() const{
	if(valid()){
        TCheie key=elements[curent];
        TValoare value=dict.cauta(key);
        return TElem(key,value);
    }
	return pair <TCheie, TValoare>  (-1, -1);
}
Iterator::~Iterator(){
    delete[] elements;
}


