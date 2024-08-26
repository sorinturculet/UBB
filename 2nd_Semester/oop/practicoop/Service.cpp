//
// Created by sorn on 27-Jun-24.
//
#include<algorithm>
#include <stdexcept>
#include <iostream>
#include "Service.h"
vector<Parcare> Service::getAllSorted() {
    vector<Parcare> v=r.getAll();
    sort(v.begin(),v.end(),[](const Parcare& p1,const Parcare& p2){
        return p1.getColoane()*p1.getLinii()<p2.getColoane()*p2.getLinii();
    });
    return v;
}
void Service::addParcare(int id, std::string adresa, int linii, int coloane, std::string stare) {
    Parcare p(id,adresa,linii,coloane,stare);
    vector<Parcare> v=r.getAll();
    for(const auto& parcare:v){
        if(p.getId()==parcare.getId())
            throw std::runtime_error("Id-ul exista deja");
    }
    string errors=p.valideaza();
    if(errors!="")
        throw std::runtime_error(errors);
    r.add(p);
    notify();
}
void Service::modificaStare(int id, std::string adresa, int linii, int coloane, std::string stare) {
    Parcare p(id,adresa,linii,coloane,stare);
    string errors=p.valideaza();
    if(errors!="")
        throw std::runtime_error(errors);
    r.update(p);
    notify();
}
void Service::modificaStareLoc(int id,int index,char c){
    for(auto& loc:r.getAll())
        if(loc.getId()==id)
        {
            string stare=loc.getStare();
            stare[index]=c;
            Parcare p(loc.getId(),loc.getAdresa(),loc.getLinii(),loc.getColoane(),stare);
            r.update(p);
            notify();
            break;
        }
};
string Service::random(int id) {
    string randoml;
    for(auto& loc:r.getAll())
        if(loc.getId()==id)
        {
            for(int i=0;i<loc.getColoane()*loc.getLinii();i++)
                if(rand()%2==0)
                    randoml+="X";
                else randoml+="-";
            //this->modificaStare(loc.getId(),loc.getAdresa(),loc.getLinii(),loc.getColoane(),randoml);
            return randoml;
        }
}