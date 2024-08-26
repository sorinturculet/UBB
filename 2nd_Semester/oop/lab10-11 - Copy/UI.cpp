//
// Created by sorn on 01-Apr-24.
//

#include "UI.h"
#include<iostream>
#include <fstream>

using namespace std;
void ConsoleUI::printMenu() {
    cout << "Comenzi disponibile:" << endl;
    cout << "1. Adauga disciplica" << endl;
    cout << "2. Modifica disciplina" << endl;
    cout << "3. Sterge disciplina" << endl;
    cout << "4. Cauta disciplina" << endl;
    cout << "5. Filtreaza discipline" << endl;
    cout << "6. Sorteaza discipline" << endl;
    cout << "7. Afiseaza toate disciplinile" << endl;
    cout << "8. Exit" << endl;
    cout << "9.Contract de studiu" << endl;
    cout << "10.Undo" << endl;
}
void ConsoleUI::addui(){
    string denumire,tip,cadruDidactic;
    int ore;
    cout<<"Introduceti denumirea materiei";
    getline(cin>>ws,denumire);
    cout<<"Introduceti numarul de ore materiei";
    try{
        cin>>ore;
    }
    catch (ValidatorException){
        cout<<"NUmarul de ore trebuie sa fie un numar natural.\n";
    }
    cout<<"Introduceti tipul materiei";
    getline(cin>>ws,tip);
    cout<<"Introduceti cadrul Didactic al materiei";
    getline(cin>>ws,cadruDidactic);

    try{
        srv.addDisciplina(denumire,ore,tip,cadruDidactic);
    }
    catch (RepoException& re){
        cout<<re.getErrorMessage();
    }
}
void ConsoleUI::modifyui(){
    return;
}
void ConsoleUI::deleteui(){
    string denumire,tip,cadruDidactic;
    int ore;
    cout<<"Introduceti denumirea materiei";
    getline(cin>>ws,denumire);
    cout<<"Introduceti cadrul Didactic al materiei";
    getline(cin>>ws,cadruDidactic);

    try{
        srv.deleteDisciplina(denumire,cadruDidactic);
    }
    catch (RepoException& re){
        cout<<re.getErrorMessage();
    }
}
void ConsoleUI::findui(){
    string denumire,tip,cadruDidactic;
    int ore;
    cout<<"Introduceti denumirea materiei";
    getline(cin>>ws,denumire);
    cout<<"Introduceti cadrul Didactic al materiei";
    getline(cin>>ws,cadruDidactic);

    try{
        Disciplina d1=srv.findDisciplina(denumire,cadruDidactic);
        cout<<d1;
    }
    catch (RepoException& re){
        cout<<re.getErrorMessage();
    }
}
void ConsoleUI::filterui(){
    string cadru;
    int ore=0;
    cout<<"Introduceti criteriul dupa care vreti sa sortati";
    cout<<"Introduceti numele profesorului dupa care vreti sa filtrati(daca nu vrei introduceti 'NU')";
    cin>>cadru;
    if(cadru=="NU") {
        cout<<"Introduceti numarul de ore dupa care vreti sa filtrati.";
        cin >> ore;
    }
        vector<Disciplina> v = srv.filter(cadru,ore);
        for (const auto &disci: v) {
            cout<<disci<<endl;
        }
}
void ConsoleUI::sortui(){
    string s;
    cout<<"Introduceti criteriul dupa care vreti sa sortati";
    cin>>s;
    if(s=="denumire"|| s=="ore"|| s=="tip" || s=="cadrudidactic") {
        vector<Disciplina> v = srv.sort(s);
        for (const auto &disci: v) {
            cout<<disci<<endl;
        }
        return ;
    }
    cout<<"Argumentele trebuie sa fie denumire/ore/tip/cadrudidactic";
}
void ConsoleUI::printall(){
    const vector<Disciplina>& allDiscipline=srv.getAllDiscipline();
    if(allDiscipline.empty())
        cout<<" Nu exista discipline"<<endl;
    else
        for(const auto& disci:allDiscipline)
            cout<<disci<<endl;
}
void ConsoleUI::contract(){
    cout<<"Alegeti una dintre urmatoarele functii ale contractului de studiu:" << endl;
    cout << "1. Adauga in contract" << endl;
    cout << "2. Goleste contract" << endl;
    cout << "3. Genereaza contract" << endl;
    cout << "4. Export contract" << endl;
    int opt;
    cin>>opt;
    if(opt==1){
        string denumire,cadrudidactic;
        cout<<"Introduceti denumirea materiei";
        getline(cin>>ws,denumire);
        cout<<"Introduceti cadrul Didactic al materiei";
        getline(cin>>ws,cadrudidactic);
    srv.addContract(denumire,cadrudidactic);
    }
    if(opt==2){
        srv.emptyContract();
    }
    if(opt==3){
        cout<<"Introduceti numarul de materii";
        int n;
        cin>>n;
        try{srv.generateContract(n);}
        catch (RepoException& re){
            cout<<re.getErrorMessage()<<endl;
        }
    }
    if(opt==4){
        cout<<"Introduceti numele fisierului(.csv) pentru a exporta ";
        string fisier;
        getline(cin>>ws,fisier);
        std::ofstream fout(fisier);
        if (!fout.is_open()) {
            std::cout << "Error opening file: " << endl;
            return;
        }
        const vector<Disciplina>& allDiscipline=srv.getAllFromContract();
        for (auto it = allDiscipline.begin(); it != allDiscipline.end(); ++it) {
            fout << *it;
            if (next(it) != allDiscipline.end()) {
                int ok=0;
            }
        }
        fout.close();
        cout<<"Export cu succes\n";

    }
    const vector<Disciplina>& allDiscipline=srv.getAllFromContract();
    cout<<"Contractul dumneavoastra este:"<<endl;
    if(allDiscipline.empty())
        cout<<"Nu exista discipline"<<endl;
    else
        for(const auto& disci:allDiscipline)
            cout<<disci<<endl;
}
void ConsoleUI::load(){
    srv.addDisciplina("Analiza",8,"Mate","Berinde");
    srv.addDisciplina("Algebra",8,"Mate","Modoi");
    srv.addDisciplina("ASC",8,"Mate","King");
    srv.addDisciplina("FP",8,"Mate","Istvanc");
}
void ConsoleUI::undo(){
    srv.undo();
}
void ConsoleUI::run() {
    int running=1;
    int cmd;
    while(running){
        printMenu();
        cout<<"Comanda dvs este : ";
        cin>>cmd;
        switch (cmd) {
            case 1:
                addui();
                break;
            case 2:
                modifyui();
                break;
            case 3:
                deleteui();
                break;
            case 4:
                findui();
                break;
            case 5:
                filterui();
                break;
            case 6:
                sortui();
                break;
            case 7:
                printall();
                break;
            case 8:
                running=0;
                break;
            case 9:
                contract();
                break;
            case 10:
                undo();
                break;
            default:
                cout<<"Comanda invalida\n";
                break;
        }
    }

}
