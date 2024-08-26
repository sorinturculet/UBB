//
// Created by sorn on 20-May-24.
//

#ifndef PRACTICOOP_ELEV_H
#define PRACTICOOP_ELEV_H
#include<string>
using namespace std;
class Elev{
private:
    int nrMatricol;
    string nume;
    string scoala;
public:
    //Constructor
    Elev(int nrMatricol,string nume,string scoala){
        this->nrMatricol=nrMatricol;
        this->nume=nume;
        this->scoala=scoala;
    }
    //getter de nrMatricol
    int getNrMatricol(){
        return nrMatricol;
    }
    //getter de nume
    string getNume(){
        return nume;
    }
    //getter de scoala
    string getScoala(){
        return scoala;
    }


};
#endif //PRACTICOOP_ELEV_H
