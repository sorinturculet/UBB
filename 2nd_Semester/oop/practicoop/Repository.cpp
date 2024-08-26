//
// Created by sorn on 27-Jun-24.
//

#include "Repository.h"
#include <fstream>
#include <iostream>

void Repository::loadFromFile() {
    ifstream fin(filename);
    if(!fin.is_open()){
        throw std::runtime_error("Fisier nevalid");
    }
    v.clear();
    string buffer;
    while(getline(fin,buffer)){
        string id;
        string adresa;
        string linii;
        string coloane;
        string stare;
        int i=0;
        while(buffer[i]!=' '){
            id+=buffer[i];
            i++;
        }
        i++;
        while(buffer[i]!=' '){
            adresa+=buffer[i];
            i++;
        }
        i++;
        while(buffer[i]!=' '){
            linii+=buffer[i];
            i++;
        }
        i++;
        while(buffer[i]!=' '){
            coloane+=buffer[i];
            i++;
        }
        i++;
        while(i<buffer.size()){
            stare+=buffer[i];
            i++;
        }
        Parcare p(stoi(id),adresa,stoi(linii),stoi(coloane),stare);
        //cout<<p.getId()<<" "<<p.getAdresa()<<" "<<p.getLinii()<<" "<<p.getColoane()<<" "<<p.getStare()<<"\n";
        v.push_back(p);
    }

    fin.close();
}
void Repository::saveToFile() {
    ofstream fout(filename);
    for(const auto& p:v){
        fout<<p.getId()<<" "<<p.getAdresa()<<" "<<p.getLinii()<<" "<<p.getColoane()<<" "<<p.getStare()<<"\n";
    }
    fout.close();
}
vector<Parcare> Repository::getAll() {
    return v;
}
void Repository::add(Parcare p) {
    v.push_back(p);
    saveToFile();
}
void Repository::update(Parcare p) {
    for(auto &i:v){
        if(i.getId()==p.getId()){
            i=p;
            saveToFile();
            return;
        }
    }
    throw std::runtime_error("Parcare inexistenta");
}
