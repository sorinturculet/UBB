//
// Created by sorn on 01-Apr-24.
//

#ifndef LAB6_DOMAIN_H
#define LAB6_DOMAIN_H
#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::endl;
using std::ostream;
class Disciplina{
    private:
        string denumire{""};
        int ore{0};
        string tip{""};
        string cadruDidactic{""};
public:
    Disciplina()=default;
    Disciplina(string denumire,int ore, string tip,string cadruDidactic ):denumire{denumire},ore{ore},tip{tip},cadruDidactic{cadruDidactic}{};
    //constructor copiere
    Disciplina(const Disciplina& disci): denumire{disci.denumire},ore{disci.ore},tip{disci.tip},cadruDidactic{disci.cadruDidactic}{
        cout<<" [Disciplina] Copy constructor called.\n";
    };
    string getDenumire() const;
    int getOre() const;
    string getTip() const;
    string getCadruDidactic() const;

    void setDenumire(const string newDenumire);
    void setOre(int newOre);
    void setTip(const string newTip);
    void setCadruDidactic(const string newCadruDidactic);

    bool operator==(const Disciplina& other) const{
        return(other.denumire==this->denumire && other.cadruDidactic==this->cadruDidactic);
    }
    friend std::ostream& operator<<(std::ostream& stream, const Disciplina& m);

};
void testeDomain();
#endif //LAB6_DOMAIN_H
