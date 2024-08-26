//
// Created by sorn on 20-May-24.
//

#ifndef PRACTICOOP_SERVICE_H
#define PRACTICOOP_SERVICE_H
#include"repository.h"
class Service{
private:
    Repository& repo;
public:
    Service(Repository& repo):repo(repo){};
    //returneaza vector cu toti elevii
    vector<Elev> getAllElevi(){
        return repo.getAllElevi();
    }
    //returneaza vector cu toate atelierii
    vector<Atelier> getAllAteliere(){
        return repo.getAllAteliere();
    }
    //Sorteaza elevii dupa nume.
    void sortare(){
        repo.sortare();
    }

};
#endif //PRACTICOOP_SERVICE_H
