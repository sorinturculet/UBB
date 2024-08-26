//
// Created by sorn on 01-Apr-24.
//
#include <algorithm>
#include <cassert>
#include "Service.h"

void DisciplinaService::addDisciplina(string denumire,int ore,string tip,string cadruDidactic){
    Disciplina d1(denumire,ore,tip,cadruDidactic);
    val.valideaza(d1);
    repo.Store(d1);
}
void DisciplinaService::modifyDisciplina(const string denumire,const int ore,const string tip,const string cadruDidactic){
    repo.Modify(denumire,ore,tip,cadruDidactic) ;
}
const Disciplina& DisciplinaService::findDisciplina(string denumire,string cadruDidactic){
    return repo.find(denumire,cadruDidactic);
}
void DisciplinaService::deleteDisciplina(string denumire,string cadruDidactic){
    Disciplina d1= findDisciplina(denumire,cadruDidactic);
    repo.Delete(d1);
}
MyVector<Disciplina> DisciplinaService::filter(const string cadru,const int val){
    MyVector<Disciplina> v;
    if(val!=0)
        for (const auto &disci: repo.getAllDiscipline()) {
            if(disci.getOre()==val)
                v.push_back(disci);
        }
    else
        for (const auto &disci: repo.getAllDiscipline()) {
            if(disci.getCadruDidactic()==cadru)
                v.push_back(disci);
        }
    return v;
}
MyVector<Disciplina> DisciplinaService::sort(const string crt){
    MyVector<Disciplina> v=repo.getAllDiscipline();
    if(crt=="denumire")
        std::sort(v.begin(), v.end(), [](const Disciplina &a, const Disciplina &b){ return (a.getDenumire() < b.getDenumire());});
    else if(crt=="ore")
        std::sort(v.begin(), v.end(), [](const Disciplina &a, const Disciplina &b){ return (a.getOre() < b.getOre());});
    else if(crt=="tip")
        std::sort(v.begin(), v.end(), [](const Disciplina &a, const Disciplina &b){ return (a.getTip() < b.getTip());});
    else
        std::sort(v.begin(), v.end(), [](const Disciplina &a, const Disciplina &b){ return (a.getCadruDidactic() < b.getCadruDidactic());});
    return v;
}
void testAddDisciplina(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("Analiza",4 ,"Obligatorie","Berinde");
    assert(testService.getAllSongs().size()==1);
}
void testModifyDisciplina(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("Analiza",4 ,"Obligatorie","Berinde");
    testService.modifyDisciplina("Analiza",7,"OK","Berinde");
    assert(testService.getAllSongs()[0].getOre()==7);
    assert(testService.getAllSongs()[0].getTip()=="OK");
}
void testDeleteDisciplina(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("Analiza",4 ,"Obligatorie","Berinde");
    assert(testService.getAllSongs().size()==1);
    testService.deleteDisciplina("Analiza","Berinde");
    assert(testService.getAllSongs().empty());
}
void testFilter(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("ZAnaliza",10,"Mate","Berinde");
    testService.addDisciplina("Malgebra",5,"Mate","Modoi");
    testService.addDisciplina("ZASC",8,"Infor","King");
    testService.addDisciplina("FP",8,"AInfo","Istvanc");
    MyVector<Disciplina> v=testService.filter("Berinde",0);
    assert(v.size()==1);
    MyVector<Disciplina> v2=testService.filter("",8);
    assert(v2.size()==2);
}
void testSort(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("ZAnaliza",10,"Mate","Berinde");
    testService.addDisciplina("Malgebra",5,"Mate","Modoi");
    testService.addDisciplina("ZASC",2,"Infor","King");
    testService.addDisciplina("FP",8,"AInfo","Istvanc");
    MyVector<Disciplina> v=testService.sort("denumire");
    assert(v[0].getDenumire()=="FP");
    MyVector<Disciplina> v2=testService.sort("ore");
    assert(v2[0].getOre()==2);
    MyVector<Disciplina> v3=testService.sort("tip");
    assert(v3[0].getTip()=="AInfo");
    MyVector<Disciplina> v4=testService.sort("cadrudidactic");
    assert(v4[0].getCadruDidactic()=="Berinde");

}

void testeService(){
    testAddDisciplina();
    testDeleteDisciplina();
    testModifyDisciplina();
    testFilter();
    testSort();
}