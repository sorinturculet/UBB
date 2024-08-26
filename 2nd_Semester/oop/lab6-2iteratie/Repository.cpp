//
// Created by sorn on 01-Apr-24.
//

#include "Repository.h"
#include <assert.h>
bool DisciplinaRepository::Exists(const Disciplina& disci){
    try{
        (find(disci.getDenumire(),disci.getCadruDidactic()));
        return true;
    }
    catch (RepoException&){
        return false;
    }

}
void DisciplinaRepository::Store(const Disciplina& disci){
    if(Exists(disci))
        throw RepoException("Disciplina exista deja.");
    this->allDisciplina.push_back(disci);
}
void DisciplinaRepository::Modify(string denumire,int ore,string tip,string cadruDidactic){
    try {
        Disciplina d = find(denumire, cadruDidactic);
        for (auto it = allDisciplina.begin(); it != allDisciplina.end(); ++it)
        {
            if(*it==d)
                it->setTip(tip),it->setOre(ore);
        }
    }
    catch (RepoException&) {
        throw RepoException("Disciplina nu exista in lista.\n");
    }
}
const Disciplina& DisciplinaRepository::find(const string Denumire,const string Profesor){
    for (const Disciplina& disci : this->allDisciplina){
        if(disci.getDenumire()==Denumire && disci.getCadruDidactic()==Profesor)
            return disci;
    }
    throw RepoException("Disciplina nu exista");
}
void DisciplinaRepository::Delete(Disciplina& disci){
    for (auto it = allDisciplina.begin(); it != allDisciplina.end(); ++it) {
        if(*it == disci) {
            allDisciplina.erase(it);
            break;
        }
    }
}

const MyVector<Disciplina>& DisciplinaRepository::getAllDiscipline(){
    return this->allDisciplina;
}
void testAdd(){
    DisciplinaRepository testRepo;
    Disciplina disci1{ "Analiza",4 ,"Obligatorie","Berinde"};
    testRepo.Store(disci1);
    assert(testRepo.getAllDiscipline().size()==1);
    try{
        testRepo.Store(disci1);
    }
    catch (RepoException&){
        assert(testRepo.getAllDiscipline().size() == 1);
    }
}
void testDelete(){
    DisciplinaRepository testRepo;
    Disciplina disci1{ "Analiza",4 ,"Obligatorie","Berinde"};
    testRepo.Store(disci1);
    assert(testRepo.getAllDiscipline().size()==1);
    testRepo.Delete(disci1);
    assert(testRepo.getAllDiscipline().empty());
}
void testModify(){
    DisciplinaRepository testRepo;
    Disciplina disci1{ "Analiza",4 ,"Obligatorie","Berinde"};
    testRepo.Store(disci1);
    testRepo.Modify("Analiza",6,"fRATE","Berinde");
    assert(testRepo.getAllDiscipline()[0].getOre()==6);
    assert(testRepo.getAllDiscipline()[0].getTip()=="fRATE");
    assert(testRepo.getAllDiscipline()[0].getTip()=="fRATE");
}
void testFind(){
    DisciplinaRepository testRepo;
    Disciplina disci1{ "Analiza",4 ,"Obligatorie","Berinde"};
    testRepo.Store(disci1);
    Disciplina disci2=testRepo.find("Analiza","Berinde");
    assert(disci1==disci2);
}
void testeRepo(){
    testAdd();
    testDelete();
    testModify();
    testFind();
}