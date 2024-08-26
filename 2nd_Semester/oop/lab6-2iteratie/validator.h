//
// Created by sorn on 04-Apr-24.
//

#ifndef LAB6_VALIDATOR_H
#define LAB6_VALIDATOR_H
#include "Domain.h"
#include<vector>
#include<string>
using std::string;
using std::vector;

class ValidatorException{
    vector<string> errorMsg;
public:
    ValidatorException(vector<string> error):errorMsg{error}{};

    string getErrorMessages(){
        string fullmsg="";
        for(const string e:errorMsg)
            fullmsg+= e+"\n";
        return fullmsg;
    }
};
class DisciplinaValidator{
public:
    void valideaza(const Disciplina& disci){
        vector<string> errors;
        if(disci.getDenumire().length()<2)
            errors.push_back("Denumirea trebuie sa aiba cel putin 2 litere");
        if(disci.getOre()<=0)
            errors.push_back("Orele trebuie sa fie numere pozitive");
        if(disci.getTip().length()<2)
            errors.push_back("Tipul trebuie sa aiba cel putin 2 litere");
        if(disci.getCadruDidactic().length()<2)
            errors.push_back("Profesorul trebuie sa aiba cel putin 2 litere");
        if(errors.size()>0){
            throw ValidatorException(errors);
        }
    }
};
#endif //LAB6_VALIDATOR_H
