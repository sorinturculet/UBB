//
// Created by sorn on 27-Jun-24.
//

#ifndef PRACTICOOP_SERVICE_H
#define PRACTICOOP_SERVICE_H

#include"Repository.h"
#include "Observer.h"
class Service:public Observable{
private:
    Repository& r;
public:
    /*
     * Constructor Service
     */
    Service(Repository& r):r{r}{};
    /*
     * Returneaza vector sortat dupa nr de locuri a unei parcari
     * returns: vector de Parcari
     */
    vector<Parcare> getAllSorted();
    /*
     * adauga o Parcare
     * param:id int
     * param:adresa string
     * param:linii int
     * param:coloane int
     * param:stare string
     * post:adauga o parcare
     * throws:exception daca parcare exista deja
     */
    void addParcare(int id,string adresa,int linii,int coloane,string stare);
    /*
     * sterge o parcare
     * param:id int
     * param:adresa string
     * param:linii int
     * param:coloane int
     * param:stare string
     * post:sterge o parcare
     * throws:exception daca parcare nu exista
     */
    void modificaStare(int id,string adresa,int linii,int coloane,string stare);
    /*
     * modifica starea unui loc
     * param:id int
     * param:index int
     * param:c char
     * post:modifica starea unui loc
     */
    void modificaStareLoc(int id,int index,char c);
    /*
     * face o stare random si returneaza
     */
    string random(int id);
};


#endif //PRACTICOOP_SERVICE_H
