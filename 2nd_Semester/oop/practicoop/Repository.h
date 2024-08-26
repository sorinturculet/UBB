//
// Created by sorn on 27-Jun-24.
//

#ifndef PRACTICOOP_REPOSITORY_H
#define PRACTICOOP_REPOSITORY_H

#include "Domain.h"
#include <utility>
#include<vector>
class Repository {
private:
    string filename;
    vector<Parcare> v;
public:
    //Constructor Repository
    explicit Repository(string filename):filename{std::move(filename)}{loadFromFile();};
    /*
     * Extrage datele din fisier si le adauga in vectorul
     */
    void loadFromFile();
    /*
     * Salveaza datele in fisier
     */
    void saveToFile();
    /*
     * Returneaza toate parcarile
     * returns:vector de Parcare
     */
    vector<Parcare> getAll();
    /*
     * adauga o parcare
     * param: p Parcare
     */
    void add(Parcare p);
    /*
     * updateaza o parcare dupa id
     * param:p Parcare
     */
    void update(Parcare p);

};


#endif //PRACTICOOP_REPOSITORY_H
