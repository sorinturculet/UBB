//
// Created by sorn on 22-Apr-24.
//

#pragma once
#include "Repository.h"
#include<unordered_map>
#include<random>
#include<cassert>
#include <algorithm>

class RepoMap:public DisciplinaRepository{
private:
    std::unordered_map<string,Disciplina> allDisciplina;
    double real;
public:
    RepoMap(double real):DisciplinaRepository(),real{real}{};

    RepoMap(const DisciplinaRepository& repo)=delete; //we don't want to copy the repo

    ~RepoMap()=default;
    void random(){
        double number=((double)rand()/RAND_MAX);
        if (number<real){
            number=number*100;
            cout<<"Probabilitate de "<<number;
            throw ("Exceptie neasteptata");
        }
    }
    //verifica daca exista o disciplina
    //param disci: Disciplina
    bool Exists(const Disciplina& disci){
        try{
            (find(disci.getDenumire(),disci.getCadruDidactic()));
            return true;
        }
        catch (RepoException&){
            return false;
        }
    };
    //adauga o disciplina
    //param disci: Disciplina
    void Store(const Disciplina& disci) override{
        random();
        if(Exists(disci))
            throw RepoException("Disciplina exista deja.\n");
        this->allDisciplina.insert(std::make_pair(disci.getDenumire(),disci));
    };
    //modifica o disciplina
    //param denumire: string
    //param ore:int
    //param tip:string
    //param cadruDidactic: string
    void Modify(const string& denumire, int ore, const string& tip, const string& cadruDidactic) override{
        random();
        try {

            Disciplina& d = find(denumire, cadruDidactic);

            d.setTip(tip);
            d.setOre(ore);
        }
        catch (RepoException&) {
            throw RepoException("Disciplina nu exista in lista.\n");
        }
    };
    //cauta o disciplina si o returneaza
    //param Denumire:string
    //param Profesor:string
    Disciplina& find(const string& Denumire, const string& Profesor) override {
        for (const auto& pair : allDisciplina) {
            const Disciplina& d = pair.second;
            if (d.getDenumire() == Denumire && d.getCadruDidactic() == Profesor) {
                return const_cast<Disciplina&>(pair.second);
            }
        }
        throw RepoException("Disciplina nu exista\n");
    }
    //sterge o disciplina
    //param disci:Disciplina
    void Delete(const Disciplina& disci) override {
        random();
        for (auto it = allDisciplina.begin(); it != allDisciplina.end(); ++it) {
            if (it->second == disci) {
                allDisciplina.erase(it);
                return;
            }
        }
        throw RepoException("Disciplina nu exista\n");
    }
    //returneaza un vector cu toate Disciplinele
    vector<Disciplina>& getAllDiscipline() const override {
        vector<Disciplina> result;
        for (const auto& pair : allDisciplina) {
            result.push_back(pair.second);
        }
        return result;
    }
};
/*
void testRepoMap() {
    // Create a RepoMap object
    RepoMap repo(0.5);

    // Create a Disciplina object
    Disciplina disci("Math", 3, "Mandatory", "John Doe");

    // Add the Disciplina to the RepoMap
    repo.Store(disci);

    // Check if the Disciplina was added correctly
    assert(repo.Exists(disci));

    // Check if the Disciplina can be found
    Disciplina& found = repo.find("Math", "John Doe");
    assert(found.getDenumire() == "Math");
    assert(found.getCadruDidactic() == "John Doe");

    // Delete the Disciplina from the RepoMap
    repo.Delete(disci);

    // Check if the Disciplina was deleted correctly
    assert(!repo.Exists(disci));
}
*/
