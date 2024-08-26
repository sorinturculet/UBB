//
// Created by sorn on 01-Apr-24.
//

#include "UI.h"
#include<iostream>
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
}
void ConsoleUI::addui(){
    string denumire,tip,cadruDidactic;
    int ore;
    cout<<"Introduceti denumirea materiei";
    getline(cin>>ws,denumire);
    cout<<"Introduceti numarul de ore materiei";
    cin>>ore;
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
    catch (ValidatorException& val){
        cout<<val.getErrorMessages();
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
    catch (ValidatorException& val){
        cout<<val.getErrorMessages();
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
    catch (ValidatorException& val){
        cout<<val.getErrorMessages();
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
        MyVector<Disciplina> v = srv.filter(cadru,ore);
        for (const auto &disci: v) {
            cout<<disci<<endl;
        }
}
void ConsoleUI::sortui(){
    string s;
    cout<<"Introduceti criteriul dupa care vreti sa sortati";
    cin>>s;
    if(s=="denumire"|| s=="ore"|| s=="tip" || s=="cadrudidactic") {
        MyVector<Disciplina> v = srv.sort(s);
        for (const auto &disci: v) {
            cout<<disci<<endl;
        }
        return ;
    }
    cout<<"Argumentele trebuie sa fie denumire/ore/tip/cadrudidactic";
}
void ConsoleUI::printall(){
    const MyVector<Disciplina>& allDiscipline=srv.getAllSongs();
    if(allDiscipline.empty())
        cout<<" Nu exista discipline"<<endl;
    else
        for(const auto& song:allDiscipline)
            cout<<song;
}
void ConsoleUI::load(){
    srv.addDisciplina("Analiza",8,"Mate","Berinde");
    srv.addDisciplina("Algebra",8,"Mate","Modoi");
    srv.addDisciplina("ASC",8,"Mate","King");
    srv.addDisciplina("FP",8,"Mate","Istvanc");
}
void ConsoleUI::run() {
    int running=1;
    int cmd;
    load();
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
            default:
                cout<<"Comanda invalida\n";
                break;
        }
    }

}
