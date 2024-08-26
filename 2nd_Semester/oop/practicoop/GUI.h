//
// Created by sorn on 27-Jun-24.
//

#ifndef PRACTICOOP_GUI_H
#define PRACTICOOP_GUI_H


#include <QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPushButton>
#include<QLineEdit>
#include<QListWidget>
#include<QTableView>
#include "Service.h"
#include<QFormLayout>
#include "MyTableModel.h"
class GUI:public QWidget,public Observer {
private:
    Service& srv;
    QHBoxLayout* lyMain=new QHBoxLayout;
    QVBoxLayout* lyLeft=new QVBoxLayout;
    QVBoxLayout* lyRight=new QVBoxLayout;
    QTableView* tbl=new QTableView;
    MyTableModel* model = new MyTableModel();
    QLineEdit* txtId=new QLineEdit{};
    QLineEdit* txtAdresa=new QLineEdit{};
    QLineEdit* txtLinii=new QLineEdit{};
    QLineEdit* txtColoane=new QLineEdit{};
    QLineEdit* txtStare=new QLineEdit{};
    QPushButton* btnAdauga=new QPushButton{"Adauga"};
    QPushButton* btnModify=new QPushButton{"Modifica"};
    QPushButton* btnGestiune=new QPushButton{"Gestioneaza Locuri"};
    QPushButton* btnRandom=new QPushButton{"Random stare"};


    QFormLayout* lyForm=new QFormLayout;

public:
    //Constructor GUI
    GUI(Service& srv):srv{srv}{
        srv.addObserver(this);
        model->setData(srv.getAllSorted());
        initGUI();
        connectActions();
    };
    /*
     * initializer GUI
     */
    void initGUI();
    /*
     * conecteaza actiunile
     */
    void connectActions();
    /*
     * functia de updateaza la observer
     */
    void update()override{
        model->setData(srv.getAllSorted());
    }
};


#endif //PRACTICOOP_GUI_H
