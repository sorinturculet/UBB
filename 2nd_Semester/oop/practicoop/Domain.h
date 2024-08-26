//
// Created by sorn on 27-Jun-24.
//

#ifndef PRACTICOOP_DOMAIN_H
#define PRACTICOOP_DOMAIN_H

#include<string>
#include <utility>
using namespace std;
class Parcare {
private:
    int id;
    string adresa;
    int linii;
    int coloane;
    string stare;
public:
    Parcare(int id,string adresa,int linii,int coloane,string stare):id{id},adresa{std::move(adresa)},linii{linii},coloane{coloane},stare{std::move(stare)}{}
    /*
     * returneaza id-ul;
     */
    int getId() const{
        return id;
    }
    /*
     * returneaza adresa;
     */
    string getAdresa() const {
        return adresa;
    }
    /*
     * returneaza nr de linii;
     */
    int getLinii() const{
        return linii;
    }
    /*
     * returneaza nr de coloane
     */
    int getColoane() const{
        return coloane;
    }
    /*
     * returneaza starea;
     */
    string getStare() const{
        return stare;
    }
    /*
     * seteaza starea parcarii
     * param stare: string
     */
    void setStare(string stare){
        this->stare=stare;
    }
    string valideaza(){
        string errors="";
        if(getLinii()<1 || getLinii()>5)
            errors+="Numar invalid de linii\n";
        if(getColoane()<1 || getColoane()>5)
            errors+="Numar invalid de coloane\n";
        if(getStare().size()!=getLinii()*getColoane())
            errors+="Stare invalida\n";
        for(auto &i:getStare())
            if(i!='X' && i!='-')
                errors+="Stare invalida\n";
        return errors;
    }
};


#endif //PRACTICOOP_DOMAIN_H
