//
// Created by sorn on 01-Apr-24.
//
#include<string>
#include"vector.h"
#ifndef LAB6_SERVICE_H
#define LAB6_SERVICE_H
#include "Repository.h"
#include "validator.h"
class DisciplinaService{
    private:
        DisciplinaRepository& repo;
        DisciplinaValidator val;
    public:
        DisciplinaService(DisciplinaRepository& disciRepo,DisciplinaValidator& disciVal): repo{disciRepo},val{disciVal}{};
        DisciplinaService(const DisciplinaService& ot)=delete;

            void addDisciplina(string denumire,int ore,string tip,string cadruDidactic);
            void modifyDisciplina(string denumire,int ore,string tip,string cadruDidactic);
            const Disciplina& findDisciplina(string denumire,string cadruDidactic);
            void deleteDisciplina(string denumire,string cadruDidactic);
            const MyVector<Disciplina>& getAllSongs() {
                return this->repo.getAllDiscipline();
            }
            MyVector<Disciplina> sort(const string crt);
            MyVector<Disciplina> filter(const string cadru,const int ore);

};
void testeService();

#endif //LAB6_SERVICE_H
