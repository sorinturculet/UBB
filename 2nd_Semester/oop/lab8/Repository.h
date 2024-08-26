//
// Created by sorn on 01-Apr-24.
//

#ifndef LAB6_REPOSITORY_H
#define LAB6_REPOSITORY_H
#include"Domain.h"
#include<vector>
using std::vector;
class RepoException {
private:
    string errorMsg;
public:
    RepoException(string errorMsg) :errorMsg{ errorMsg } {};
    string getErrorMessage() {
        return this->errorMsg;
    }
};

class AbstractRepository {
public:
    AbstractRepository() = default;

    // Accessor method to retrieve all activities stored in the repository
    // Precondition: None
    // Postcondition: Returns a vector containing all activities stored in the repository
    virtual const vector<Disciplina>& getAllDiscipline() const = 0;

    // Modifies an activity at the specified index with the provided modified activity
    // Precondition: The index must be a valid non-negative integer less than the size of activities vector
    //               The modified_activity must be a valid Activity object
    // Postcondition: The activity at the specified index is replaced with the modified_activity
    // Exception: Throws std::exception if the index is out of range
    virtual void Modify(const string& denumire, int ore, const string& tip, const string& cadruDidactic) = 0;

    // Adds a new activity to the repository
    // Precondition: The activity must be a valid Activity object
    // Postcondition: The activity is added to the activities vector
    virtual void Store(const Disciplina& disci) = 0;

    // Removes the activity at the specified title from the repository
    // Precondition: The index must be a valid non-negative integer less than the size of activities vector
    // Postcondition: The activity at the specified index is removed from the activities vector
    // Exception: Throws std::exception if no activity has title
    virtual void Delete(const Disciplina& disci) = 0;

    // Searches for the activity at the specified title from the repository
    // Precondition: An existing activity has to have the specific title
    // Postcondition: The activity with the specified title is returned
    // Exception: Throws std::exception if no activity has title
    virtual Disciplina& find(const string& Denumire, const string& Profesor)= 0;
};
class DisciplinaRepository:public AbstractRepository{
    private:
    vector<Disciplina> allDisciplina;
    public:
    DisciplinaRepository()=default;

    DisciplinaRepository(const DisciplinaRepository& repo)=delete; //we don't want to copy the repo

    virtual ~DisciplinaRepository()=default;
    //verifica daca exista o disciplina
    //param disci: Disciplina
    bool Exists(const Disciplina& disci) ;
    //adauga o disciplina
    //param disci: Disciplina
    virtual void Store(const Disciplina& disci) override;
    //modifica o disciplina
    //param denumire: string
    //param ore:int
    //param tip:string
    //param cadruDidactic: string
    virtual void Modify(const string& denumire, int ore, const string& tip, const string& cadruDidactic) override;
    //cauta o disciplina si o returneaza
    //param Denumire:string
    //param Profesor:string
    Disciplina& find(const string& Denumire, const string& Profesor) override;
    //sterge o disciplina
    //param disci:Disciplina
    virtual void Delete(const Disciplina& disci) override;
    //returneaza un vector cu toate Disciplinele
    const vector<Disciplina>& getAllDiscipline() const override;
};

class DisciplinaRepoFile:public DisciplinaRepository{
private:
    std::string filename;
    void loadFromFile();
    void writeToFile();
public:
    DisciplinaRepoFile(std::string filename):DisciplinaRepository(),filename{filename}{
        loadFromFile();
    };
    void Store(const Disciplina& disci) override{
        DisciplinaRepository::Store(disci);
        writeToFile();
    }
    void Modify(const string& denumire, int ore, const string& tip, const string& cadruDidactic) override{
        DisciplinaRepository::Modify(denumire,ore,tip,cadruDidactic);
        writeToFile();
    }
    void Delete(const Disciplina& disci) override{
        DisciplinaRepository::Delete(disci);
        writeToFile();
    }
};

void testeRepo();
#endif //LAB6_REPOSITORY_H
