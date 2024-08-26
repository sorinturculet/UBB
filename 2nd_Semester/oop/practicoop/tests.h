//
// Created by sorn on 27-Jun-24.
//

#ifndef PRACTICOOP_TESTS_H
#define PRACTICOOP_TESTS_H
#include "Domain.h"
#include<assert.h>
#include "Repository.h"
#include "Service.h"
#include <iostream>
void test_service(){
    Repository r("C:\\Users\\sorn\\Desktop\\practicoop\\datatest.txt");
    Service s(r);
    assert(s.getAllSorted().size()>5);
    try{
        s.addParcare(67,"Eroilor",20,30,"XXX---");
    }
    catch(std::runtime_error& e){
        assert(true);
    }
    try{
        s.addParcare(200,"OK",1,2,"XX");
    }
    catch(std::runtime_error& e){
        assert(true);
    }
    s.modificaStare(5,"privatia",1,1,"-");
    assert(s.getAllSorted()[0].getStare()=="-");
    s.modificaStare(5,"privatia",1,1,"X");
    assert(s.getAllSorted()[0].getStare()=="X");
    //1 Eroilor 2 3 ---XXX

    s.modificaStareLoc(1,4,'-');

    assert(r.getAll()[0].getStare()=="---X-X");
    s.modificaStareLoc(1,4,'X');
    assert(r.getAll()[0].getStare()=="---XXX");
}
void test_repo(){
    Repository r("C:\\Users\\sorn\\Desktop\\practicoop\\datatest.txt");
    r.loadFromFile();
    assert(r.getAll().size()>5);
    assert(r.getAll()[0].getId()==1);
    assert(r.getAll()[0].getAdresa()=="Eroilor");
    Parcare p=Parcare(67,"Eroilor",2,3,"XXX---");
    r.add(p);
    assert(r.getAll().size()>6);
    r.update(Parcare(67,"Eroilor",2,3,"---XXX"));
    assert(r.getAll()[5].getStare()=="---XXX");
}
void test_domain(){
    Parcare p=Parcare(1,"Eroilor",2,3,"XXX---");
    assert(p.getStare()=="XXX---");
    assert(p.getId()==1);
    assert(p.getLinii()==2);
    assert(p.getColoane()==3);
    p.setStare("---XXX");
    assert(p.getStare()=="---XXX");
    assert(p.valideaza().size()==0);
    Parcare p2=Parcare(2,"Eroilorr",2,2,"XXXXX");
    assert(p2.valideaza().size()>2);
}

void test_all(){
    test_domain();
    test_repo();
    test_service();
    cout<<"Finished tests\n";
}
#endif //PRACTICOOP_TESTS_H
