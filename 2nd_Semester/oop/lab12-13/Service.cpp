//
// Created by sorn on 01-Apr-24.
//
#include <algorithm>
#include<fstream>
#include <cassert>
#include<random>
#include<chrono>
#include <utility>
#include "Service.h"

void DisciplinaService::addDisciplina(string denumire,int ore,string tip,string cadruDidactic){
    Disciplina d1(std::move(denumire),ore,std::move(tip),std::move(cadruDidactic));
    val.valideaza(d1);
    auto* u = new UndoAdd(this->repo, d1);

    repo.Store(d1);
    this->undoActions.push_back(u);
}
void DisciplinaService::modifyDisciplina(const string& denumire,const int ore,const string& tip,const string& cadruDidactic){

    Disciplina d1= findDisciplina(denumire,cadruDidactic);
    auto* u = new UndoUpdate(this->repo, d1.getDenumire(),d1.getOre(),d1.getTip(),d1.getCadruDidactic());
    repo.Modify(denumire,ore,tip,cadruDidactic) ;
    this->undoActions.push_back(u);
}
const Disciplina& DisciplinaService::findDisciplina(const string& denumire,const string& cadruDidactic){
    return repo.find(denumire,cadruDidactic);
}
void DisciplinaService::deleteDisciplina(const string& denumire,const string& cadruDidactic){
    Disciplina d1= findDisciplina(denumire,cadruDidactic);
    repo.Delete(d1);
    auto* u = new UndoRemove(this->repo, d1);

    undoActions.push_back(u);
}
vector<Disciplina> DisciplinaService::filter(const string cadru, const int valo) {
    vector<Disciplina> v;
    auto& discipline = repo.getAllDiscipline();
    if (valo != 0) {
        std::copy_if(discipline.begin(), discipline.end(), std::back_inserter(v),
                     [&](const Disciplina& disci) {
                         return disci.getOre() == valo;
                     });
    } else {
        std::copy_if(discipline.begin(), discipline.end(), std::back_inserter(v),
                     [&](const Disciplina& disci) {
                         return disci.getCadruDidactic() == cadru;
                     });
    }
    return v;
}
vector<Disciplina> DisciplinaService::sort(const string& crt){
    vector<Disciplina> v=repo.getAllDiscipline();
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
void DisciplinaService::addContract(const string& denumire,const string& cadruDidactic){
    Disciplina d= findDisciplina(denumire,cadruDidactic);
    contract.push_back(d);
    notify();
}
void DisciplinaService::emptyContract(){
    contract.clear();
    notify();
}
void DisciplinaService::generateContract(const int n){
    emptyContract();
    if(n>repo.getAllDiscipline().size())
        throw RepoException("Nu avem destule discipline");
    auto seed=std::chrono::system_clock::now().time_since_epoch().count();
    vector<Disciplina> v=repo.getAllDiscipline();
    std::shuffle(v.begin(),v.end(),std::default_random_engine(seed));
    std::copy(v.begin(), v.begin() + n, std::back_inserter(contract));
    notify();
}
void DisciplinaService::exportContract(const string& filename) {
    std::ofstream fout(filename);
    if (!fout.is_open()) {
        std::cout << "Error opening file: " << endl;
        return;
    }
    const vector<Disciplina>& allDiscipline=getAllFromContract();
    for (auto it = allDiscipline.begin(); it != allDiscipline.end(); ++it) {
        fout << *it;
        if (next(it) != allDiscipline.end()) {
            int ok=0;
        }
    }
    fout.close();

}
std::map<string,int> DisciplinaService::get_map(){
    vector<Disciplina> v=repo.getAllDiscipline();
    std::map<string,int> map;
    for(const auto& disci:v){
        auto it=map.find(disci.getTip());
        if(it==map.end()) {
            map.insert({disci.getTip(), 1});
        }
        else {
            (*it).second++;
        }
    }
    return map;
}

void DisciplinaService::undo(){
    if (undoActions.empty())
        throw RepoException("Nu se poate face undo");
    UndoAction* undo_elem=undoActions.back();
    undo_elem->doUndo();
    undoActions.pop_back();
    delete undo_elem;
}
void testAddDisciplina(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("Analiza",4 ,"Obligatorie","Berinde");
    assert(testService.getAllDiscipline().size()==1);
    try{
        testService.addDisciplina("a",-1,"b","c");
    }
    catch (ValidatorException&){
        assert(true);
    }

}
void testModifyDisciplina(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("Analiza",4 ,"Obligatorie","Berinde");
    testService.modifyDisciplina("Analiza",7,"OK","Berinde");
    assert(testService.getAllDiscipline()[0].getOre()==7);
    assert(testService.getAllDiscipline()[0].getTip()=="OK");
}
void testDeleteDisciplina(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("Analiza",4 ,"Obligatorie","Berinde");
    assert(testService.getAllDiscipline().size()==1);
    testService.deleteDisciplina("Analiza","Berinde");
    assert(testService.getAllDiscipline().empty());
}
void testFilter(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("ZAnaliza",10,"Mate","Berinde");
    testService.addDisciplina("Malgebra",5,"Mate","Modoi");
    testService.addDisciplina("ZASC",8,"Infor","King");
    testService.addDisciplina("FP",8,"AInfo","Istvanc");
    vector<Disciplina> v=testService.filter("Berinde",0);
    assert(v.size()==1);
    vector<Disciplina> v2=testService.filter("",8);
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
    vector<Disciplina> v=testService.sort("denumire");
    assert(v[0].getDenumire()=="FP");
    vector<Disciplina> v2=testService.sort("ore");
    assert(v2[0].getOre()==2);
    vector<Disciplina> v3=testService.sort("tip");
    assert(v3[0].getTip()=="AInfo");
    vector<Disciplina> v4=testService.sort("cadrudidactic");
    assert(v4[0].getCadruDidactic()=="Berinde");

}
void testContract(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("ZAnaliza",10,"Mate","Berinde");
    testService.addDisciplina("Malgebra",5,"Mate","Modoi");
    testService.addDisciplina("ZASC",2,"Infor","King");
    testService.addDisciplina("FP",8,"AInfo","Istvanc");
    testService.addContract("ZAnaliza","Berinde");
    assert(testService.getAllFromContract().size()==1);
    testService.emptyContract();
    assert(testService.getAllFromContract().empty());
    try{
        testService.generateContract(9);
    }
    catch (RepoException&){
        assert(true);
    }
    testService.generateContract(4);
    assert(testService.getAllFromContract().size()==4);
}
void testMap(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    testService.addDisciplina("ZAnaliza",10,"Mate","Berinde");
    testService.addDisciplina("Malgebra",5,"Mate","Modoi");
    testService.addDisciplina("ZASC",2,"Infor","King");
    testService.addDisciplina("FP",8,"AInfo","Istvanc");
    testService.addContract("ZAnaliza","Berinde");
    std::map<string,int> m=testService.get_map();
    assert(m.size()==3);
    auto it=m.find("Mate");
    assert((*it).second==2);
}
void testUndo(){
    DisciplinaRepository testRepo;
    DisciplinaValidator testVal;
    DisciplinaService testService{testRepo,testVal};
    try{
        testService.undo();
    }
    catch (RepoException&){
        assert(true);
    }
    testService.addDisciplina("ZAnaliza",10,"Mate","Berinde");
    testService.addDisciplina("Malgebra",5,"Mate","Modoi");
    testService.addDisciplina("ZASC",2,"Infor","King");
    testService.addDisciplina("FP",8,"AInfo","Istvanc");
    assert(testService.getAllDiscipline().size()==4);
    testService.undo();
    assert(testService.getAllDiscipline().size()==3);
    testService.deleteDisciplina("ZAnaliza","Berinde");
    assert(testService.getAllDiscipline().size()==2);
    testService.undo();
    assert(testService.getAllDiscipline().size()==3);
    testService.modifyDisciplina("ZAnaliza",600,"Mate","Berinde");
    assert(testService.getAllDiscipline()[2].getOre()==600);
    testService.undo();
    assert(testService.getAllDiscipline()[2].getOre()==10);

}
void testeService(){
    testAddDisciplina();
    testDeleteDisciplina();
    testModifyDisciplina();
    testFilter();
    testSort();
    testContract();
    testMap();
    testUndo();
}