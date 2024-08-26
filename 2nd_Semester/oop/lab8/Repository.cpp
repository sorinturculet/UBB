//
// Created by sorn on 01-Apr-24.
//

#include "Repository.h"
#include<algorithm>
#include <fstream>
#include <cassert>
using namespace std;

void DisciplinaRepoFile::loadFromFile() {
    std::ifstream f(filename);
    if(!f.is_open()){
        throw RepoException("Unable to open file");
    }
    string line;
    while (getline(f, line)) {
        int i = 0;

        string denumire, ore, tip, cadru;

        while (line[i] != ',' && line[i] != NULL) {
            denumire += line[i];
            i++;
        }
        i++;
        while (line[i] != ',' && line[i] != NULL) {
            ore += line[i];
            i++;
        }
        i++;
        while (line[i] != ',' && line[i] != NULL) {
            tip += line[i];
            i++;
        }
        i++;
        while (line[i] != NULL) {
            cadru += line[i];
            i++;
        }

        int durata = stoi(ore);

        Disciplina d{denumire,durata,tip,cadru};
        DisciplinaRepository::Store(d);
    }

    f.close();
}
void DisciplinaRepoFile::writeToFile()
{
    std::ofstream fout(this->filename);
    for (auto& disci : DisciplinaRepository::getAllDiscipline()) {
        fout << disci.getDenumire() << "," << disci.getOre() << "," << disci.getTip() << "," << disci.getCadruDidactic() << endl;
    }
    fout.close();
}

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
        throw RepoException("Disciplina exista deja.\n");
    this->allDisciplina.push_back(disci);
}
void DisciplinaRepository::Modify(const string& denumire, int ore, const string& tip, const string& cadruDidactic) {
    try {

        Disciplina& d = find(denumire, cadruDidactic);

        d.setTip(tip);
        d.setOre(ore);
    }
    catch (RepoException&) {
        throw RepoException("Disciplina nu exista in lista.\n");
    }
}

Disciplina& DisciplinaRepository::find(const string& Denumire, const string& Profesor) {
    auto it = std::find_if(allDisciplina.begin(), allDisciplina.end(), [&](const Disciplina& d) {
        return d.getDenumire() == Denumire && d.getCadruDidactic() == Profesor;
    });

    if (it != allDisciplina.end()) {
        return *it;
    }

    throw RepoException("Disciplina nu exista\n");
}

void DisciplinaRepository::Delete(const Disciplina& disci) {
    auto pred = [&](const Disciplina& d) {
        return d == disci;
    };

    allDisciplina.erase(std::remove_if(allDisciplina.begin(), allDisciplina.end(), pred), allDisciplina.end());
}


const vector<Disciplina>& DisciplinaRepository::getAllDiscipline() const{
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
    try{
        testRepo.Modify("Analiza",6,"fRATE","Modoi");
    }
    catch (RepoException& re){
        cout<<re.getErrorMessage();
        assert(re.getErrorMessage()=="Disciplina nu exista in lista.\n");
    }
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
void testRepoFile(){
DisciplinaRepoFile repo("C:/eu/ubb/2nd_Semester/oop/lab8/testrepo.txt");

    Disciplina disci1{ "Disci 2",4 ,"Type 3","Teacher 4"};

    repo.Store(disci1);

    vector<Disciplina> allActivities = repo.getAllDiscipline();
    assert(allActivities.size() == 2);
    repo.Modify("Disci 2",9 ,"Type 3","Teacher 4");
    assert(repo.getAllDiscipline()[1].getOre() == 9);
    repo.Delete(disci1);
    assert(repo.getAllDiscipline().size()==1);
}
void testeRepo(){
    testAdd();
    testDelete();
    testModify();
    testFind();
    testRepoFile();
}