//
// Created by sorn on 01-Apr-24.
//

#ifndef LAB6_REPOSITORY_H
#define LAB6_REPOSITORY_H
#include"Domain.h"
#include"vector.h"
class RepoException {
private:
    string errorMsg;
public:
    RepoException(string errorMsg) :errorMsg{ errorMsg } {};
    string getErrorMessage() {
        return this->errorMsg;
    }
};
class DisciplinaRepository{
    private:
    MyVector<Disciplina> allDisciplina;
    public:
    DisciplinaRepository()=default;
    DisciplinaRepository(const DisciplinaRepository& repo)=delete;

    bool Exists(const Disciplina& disci);
    void Store(const Disciplina& disci);
    void Modify(string denumire,int ore,string tip,string cadruDidactic);
    const Disciplina& find(const string Denumire,const string Profesor);
    void Delete(Disciplina& disci);

    const MyVector<Disciplina>& getAllDiscipline();

};
void testeRepo();
#endif //LAB6_REPOSITORY_H
