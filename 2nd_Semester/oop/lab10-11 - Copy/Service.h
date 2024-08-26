//
// Created by sorn on 01-Apr-24.
//
#include<string>
#include<vector>
#ifndef LAB6_SERVICE_H
#define LAB6_SERVICE_H
#include "Repository.h"
#include "validator.h"
#include "Undo.h"
#include <unordered_map>
#include<map>
class DisciplinaService{
    private:
        DisciplinaRepository& repo;
        DisciplinaValidator& val;
        vector<Disciplina> contract;

        vector<UndoAction*> undoActions;
    public:
    DisciplinaService(DisciplinaRepository& disciRepo,DisciplinaValidator& disciVal): repo{disciRepo},val{disciVal}{};        DisciplinaService(const DisciplinaService& ot)=delete;
        ~DisciplinaService(){
            for(auto act:undoActions)
                delete act;
        };
            //adauga o disciplina
            //param denumire:string
            //param ore:int
            //param tip:string
            //param cadruDidactic:string
            void addDisciplina(string denumire,int ore,string tip,string cadruDidactic);
            //modifica o disciplina
            //param denumire:string
            //param ore:int
            //param tip:string
            //param cadruDidactic:string
            void modifyDisciplina(const string& denumire,int ore,const string& tip,const string& cadruDidactic);
            //findDisciplina o disciplina
            //param denumire:string
            //param cadruDidactic:string
            const Disciplina& findDisciplina(const string& denumire,const string& cadruDidactic);
            //sterge o disciplina
            //param denumire:string
            //param cadruDidactic:string
            void deleteDisciplina(const string& denumire,const string& cadruDidactic);
            //returneaza un vector cu toate disciplinele
            const vector<Disciplina>& getAllDiscipline(){
                return this->repo.getAllDiscipline();
            }
            //sorteaza disciplinele dupa criteriu
            vector<Disciplina> sort(const string& crt);
            //filtreaza disciplinele dupa cadru didactic sau numarul de ore
            vector<Disciplina> filter(string cadru,int ore);

            //adauga o materie la contract
            void addContract(const string& denumire,const string& cadruDidactic);
            //sterge tot din contract
            void emptyContract();
            //genereaza un nou contract
            void generateContract(int n);
            //returneaza toate disciplinele din contract
            const vector<Disciplina>& getAllFromContract() {
                return this->contract;
            }
            void exportContract(const string& filename);
            //returneaza disctionarul
            std::map<string,int> get_map();

            void undo();
};
void testeService();

#endif //LAB6_SERVICE_H
