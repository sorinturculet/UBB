//
// Created by sorn on 20-May-24.
//

#ifndef PRACTICOOP_DOMAIN_H
#define PRACTICOOP_DOMAIN_H
#include<string>
#include<vector>
using namespace std;
class Atelier{
private:
    string nume;
    vector<int> elevi;
public:
    //Constructor
    Atelier(string nume, vector<int> elevi){
        this->nume=nume;
        this->elevi=elevi;
    }
    //getter de nrMatricol
    string getNume(){
        return nume;
    }
    //getter de elevi.
    vector<int> getElevi(){
        return elevi;
    };
};
#endif //PRACTICOOP_DOMAIN_H
