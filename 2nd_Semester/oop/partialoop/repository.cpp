#include"repository.h"
#include"elev.h"
#include<fstream>
void Repository::loadFromFile() {
    ifstream fin(filename);
    if(!fin.is_open()){
        throw ("Fisierul nu a putut fi deschis");
    }
    string nume;
    string scoala;
    string nrMatricol;
    string s;
    while(getline(fin,s)){
        int i=0;
        while(s[i]!=','){
            nrMatricol+=s[i];
            i++;
        }
        i++;
        while(s[i]!=','){
            nume+=s[i];
            i++;
        }
        i++;
        while(i<s.size()){
            scoala+=s[i];
            i++;
        }
        Elev e(stoi(nrMatricol),nume,scoala);
        elevi.push_back(e);
        nume.clear();
        scoala.clear();
        nrMatricol.clear();

    }
    ifstream fin2(filename2);
    if(!fin.is_open()){
        throw ("Fisierul nu a putut fi deschis");
    }
    while(getline(fin2,s)){
        vector<int> v;
        int i=0;

        while(s[i]!=','){
            nume+=s[i];
            i++;
        }

        i++;
        while(i<s.size()){

            string nr;
            while(s[i]!=',' && i<s.size()){
                nr+=s[i];
                i++;
            }
            v.push_back(stoi(nr));
            i++;
        }
        Atelier a(nume,v);
        Ateliere.push_back(a);

        nume.clear();
    }
}
void Repository::sortare() {
    sort(elevi.begin(),elevi.end(),[](Elev e1,Elev e2){
        return e1.getNume()<e2.getNume();
    });
}
vector<Elev> Repository::getAllElevi(){
    return elevi;
}
vector<Atelier> Repository::getAllAteliere(){
    return Ateliere;
}