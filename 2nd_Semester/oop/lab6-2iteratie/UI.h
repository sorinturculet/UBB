//
// Created by sorn on 01-Apr-24.
//

#ifndef LAB6_UI_H
#define LAB6_UI_H
#include "Service.h"
class ConsoleUI{
    private:
        DisciplinaService& srv;
    public:
        ConsoleUI(DisciplinaService& srv):srv{srv}{};
        ConsoleUI(const ConsoleUI& ot) = delete;
        void addui();
        void modifyui();
        void deleteui();
        void findui();
        void filterui();
        void sortui();
        void printall();
        void run();
        void load();
        void printMenu();
};
#endif //LAB6_UI_H
