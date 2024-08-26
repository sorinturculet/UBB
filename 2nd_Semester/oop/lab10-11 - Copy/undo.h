//
// Created by sorn on 22-Apr-24.
//
#pragma once
#include "Service.h"
#include <iostream>
#include <memory>
class UndoAction {
public:
    virtual void doUndo() = 0;
    virtual ~UndoAction() = default;
};

class UndoAdd : public UndoAction {
private:
    Disciplina disci;
    DisciplinaRepository& repo;
public:
    UndoAdd(DisciplinaRepository& repository, const Disciplina& disci)
            : repo(repository), disci(disci) {}

    void doUndo() override {
        repo.Delete(disci);
    }
};

class UndoRemove : public UndoAction {
private:
    Disciplina disci;
    DisciplinaRepository& repo;
public:
    UndoRemove(DisciplinaRepository& repository, const Disciplina& disci)
            : repo(repository), disci(disci) {}

    void doUndo() override {
        repo.Store(disci);
    }
};

class UndoUpdate : public UndoAction {
private:
    string denumire;
    int ore;
    string tip;
    string cadruDidactic;
    DisciplinaRepository& repo;
public:
    UndoUpdate(DisciplinaRepository& repository, const string& denumire, int ore, const string& tip, const string& cadruDidactic)
            : repo(repository), denumire(denumire), ore(ore), tip(tip), cadruDidactic(cadruDidactic) {}

    void doUndo() override {
        repo.Modify(denumire, ore, tip, cadruDidactic);
    }
};