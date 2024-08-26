//
// Created by sorn on 01-Apr-24.
//

#include "Domain.h"
#include<cassert>
string Disciplina::getDenumire() const{
    return this->denumire;
}
int Disciplina::getOre() const {
    return this->ore;
}
string Disciplina::getTip() const {
    return this->tip;
}
string Disciplina::getCadruDidactic() const {
    return this->cadruDidactic;
}
void Disciplina::setDenumire(const string newDenumire) {
    this->denumire=newDenumire;
}
void Disciplina::setOre(int newOre) {
    this->ore=newOre;
}
void Disciplina::setTip(const string newTip) {
    this->tip=newTip;
}
void Disciplina::setCadruDidactic(const string newCadruDidactic) {
    this->cadruDidactic=newCadruDidactic;
}
std::ostream& operator<<(std::ostream& stream, const Disciplina& m) {
    stream << "Disciplina , Denumire: " << m.getDenumire() << ", Ore: " << m.getOre() << ", Tip: " << m.getTip()<< ", Cadru Didactic: " << m.getCadruDidactic() <<endl;
    return stream;
}
void testGetSet(){
    Disciplina disci1{ "Analiza",4 ,"Obligatorie","Berinde"};
    assert(disci1.getDenumire()=="Analiza");
    assert(disci1.getOre()==4);
    assert(disci1.getTip()=="Obligatorie");
    assert(disci1.getCadruDidactic()=="Berinde");

    Disciplina disci2{ "Logica",8 ,"Obligatorie","Pop"};
    assert(disci2.getDenumire()=="Logica");
    assert(disci2.getOre()==8);
    assert(disci2.getTip()=="Obligatorie");
    assert(disci2.getCadruDidactic()=="Pop");

    disci2.setDenumire("LC");
    disci2.setOre(10);
    disci2.setTip("Obliga");
    disci2.setCadruDidactic("Pop Andreea");

    assert(disci2.getDenumire()=="LC");
    assert(disci2.getOre()==10);
    assert(disci2.getTip()=="Obliga");
    assert(disci2.getCadruDidactic()=="Pop Andreea");

}
void testeDomain(){
    testGetSet();
}