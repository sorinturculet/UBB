#include <assert.h>
#include<iostream>
#include"elev.h"
#include "service.h"
#include"domain.h"
void testElev(){
    Elev e(8,"Mihai","Sadoveanu");
    assert(e.getNrMatricol()==8);
    assert(e.getNume()=="Mihai");
    assert(e.getScoala()=="Sadoveanu");
}
void testAtelier(){
    vector<int> v;
    v.push_back(10);
    Atelier a("A",v);
    assert(a.getNume()=="A");
    assert(a.getElevi().size()==1);

}
void testRepo(){
    Repository r("C:/eu/ubb/2nd_Semester/oop/practicoop/test.txt","C:/eu/ubb/2nd_Semester/oop/practicoop/test2.txt");

    vector<Elev> elevi= r.getAllElevi();
    assert(elevi.size()==5);
    assert(elevi[0].getNrMatricol()==8);
    assert(elevi[1].getNume()=="Darius");
    assert(elevi[2].getScoala()=="Chinteni");

    r.sortare();
    elevi= r.getAllElevi();
    assert(elevi[0].getNume()=="Darius");
    assert(elevi[1].getNume()=="Gica");
    assert(elevi[4].getNume()=="Mihaita");
}
void testService(){
    Repository r("C:/eu/ubb/2nd_Semester/oop/practicoop/test.txt","C:/eu/ubb/2nd_Semester/oop/practicoop/test2.txt");
    Service srv{r};
    vector<Elev> elevi= srv.getAllElevi();
    assert(elevi.size()==5);
    srv.sortare();
    elevi= srv.getAllElevi();
    assert(elevi[0].getNume()=="Darius");
    assert(elevi[1].getNume()=="Gica");
    assert(elevi[4].getNume()=="Mihaita");
    vector<Atelier> ateliere=srv.getAllAteliere();
    assert(ateliere.size()==5);
}
void testAll(){
    testElev();
    testAtelier();
    testRepo();
}