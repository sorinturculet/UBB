#include "UI.h"
#include <iostream>
using std::cout;
using std::endl;
/*
 5 Contract de studii
Creați o aplicație care permite:
· gestiunea unei liste de discipline. Disciplina: denumire, ore pe săptămâna, tip, cadru
didactic
· adăugare, ștergere, modificare și afișare discipline
· căutare disciplina
· filtrare discipline după: nr ore, cadru didactic
· sortare discipline după: denumire, nr ore, cadru didactic + tip
 */
void testAll(){
    testeDomain();
    testeRepo();
    testeService();
    cout<<"Finished tests";
}
void startApp(){
    DisciplinaRepository repo;
    DisciplinaValidator val;
    DisciplinaService srv{repo,val};
    ConsoleUI ui{srv};
    ui.run();
}
int main() {
    testAll();
    startApp();
    return 0;
}
