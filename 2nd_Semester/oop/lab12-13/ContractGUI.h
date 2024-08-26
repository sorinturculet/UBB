//
// Created by sorn on 13-May-24.
//

#ifndef LAB10_11_CONTRACTGUI_H
#define LAB10_11_CONTRACTGUI_H
#include<QtWidgets/qwidget.h>
#include <QApplication>
#include <QPushButton>
#include<QMessageBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QFormLayout>
#include "Service.h"
#include "Observer.h"
using namespace std;

class ContractGUI:public QWidget,public Observer{
public:
    ContractGUI(DisciplinaService& srv):srv{srv} {
        initGUI();
        loadData();
        loadDataContract();
        initConnect();
    }
private:
    DisciplinaService& srv;
    QListWidget* lst=new QListWidget;
    QListWidget* lstcontract=new QListWidget;

    QPushButton* addbtn=new QPushButton{"&adauga"};
    QPushButton* deletebtn=new QPushButton{"&delete contract"};
    QPushButton* exitbtn=new QPushButton{"&Exit"};
    QPushButton* generatebtn=new QPushButton{"&generate"};
    QPushButton* exportbtn=new QPushButton{"&export"};

    QLineEdit* denumiretxt=new QLineEdit;
    QLineEdit* cadrutxt=new QLineEdit;
    QLineEdit* nrmateriitxt=new QLineEdit;
    QLineEdit* numefisiertxt=new QLineEdit;
    void initConnect(){

        QObject::connect(exitbtn,&QPushButton::clicked,[&](){
            qDebug()<<"Exit button pressed";
            //QMessageBox::information(nullptr,"Info","asasas");
            close();
        });
        QObject::connect(addbtn,&QPushButton::clicked,[&](){
            auto nume=denumiretxt->text();
            auto cadru=cadrutxt->text();
            //call service srv.add(QString::fromStdString(nume),tip,pret)
            //de adaugat conversie
            try {
                srv.addContract(nume.toStdString(), cadru.toStdString());
            }
            catch(RepoException& ve){
                QMessageBox::information(nullptr,"Info",QString::fromStdString("Date invalide."));
            }
            //load data.dupaa dauga
            loadData();
            loadDataContract();
        });
        QObject::connect(deletebtn,&QPushButton::clicked,[&](){
            srv.emptyContract();
            loadData();
            loadDataContract();
        });
        QObject::connect(generatebtn,&QPushButton::clicked,[&](){
            auto nr=nrmateriitxt->text();
            srv.generateContract(nr.toInt());
            loadData();
            loadDataContract();
        });
        QObject::connect(exportbtn,&QPushButton::clicked,[&](){
            auto nume=numefisiertxt->text();
            srv.exportContract(nume.toStdString());
        });
    }
    void update() override{
        loadData();
        loadDataContract();
    }
    void loadData(){
        lst->clear();
        vector<Disciplina> allProduct=srv.getAllDiscipline();
        for(const auto& elem:allProduct){
            string disci= "Disciplina : Denumire: " + elem.getDenumire() + ", Ore: " + to_string(elem.getOre()) + ", Tip: " + elem.getTip()+ ", Cadru Didactic: " + elem.getCadruDidactic();
            lst->addItem(QString::fromStdString(disci));
        }
    }
    void loadDataContract(){
        lstcontract->clear();
        vector<Disciplina> allProduct=srv.getAllFromContract();
        for(const auto& elem:allProduct){
            string disci= "Disciplina : Denumire: " + elem.getDenumire() + ", Ore: " + to_string(elem.getOre()) + ", Tip: " + elem.getTip()+ ", Cadru Didactic: " + elem.getCadruDidactic();
            lstcontract->addItem(QString::fromStdString(disci));
        }
    }
    void initGUI(){//ASEZ ELEMENTELE IN FEREASTRA.
        srv.addObserver(this);
        auto* layoutmain = new QHBoxLayout{};
        setLayout(layoutmain);
        auto stgLy= new QVBoxLayout{};

        auto formLy=new QFormLayout{};
        formLy->addRow("Denumire materie", denumiretxt);
        formLy->addRow("Cadru didactic materie", cadrutxt);
        stgLy->addLayout(formLy);

        auto lyBtn=new QHBoxLayout{};
        lyBtn->addWidget(addbtn);
        lyBtn->addWidget(deletebtn);

        auto lyBtn2=new QHBoxLayout{};
        lyBtn2->addWidget(generatebtn);

        auto formLy2=new QFormLayout{};
        formLy2->addRow("Numar de materii dorite", nrmateriitxt);

        auto lyBtn3=new QHBoxLayout{};
        lyBtn3->addWidget(exportbtn);

        auto formLy3=new QFormLayout{};
        formLy3->addRow("Numelere fisierului .csv)", numefisiertxt);

        stgLy->addLayout(lyBtn);
        stgLy->addLayout(formLy2);
        stgLy->addLayout(lyBtn2);
        stgLy->addLayout(formLy3);
        stgLy->addLayout(lyBtn3);
        stgLy->addWidget(exitbtn);
        layoutmain->addLayout(stgLy );

        layoutmain->addWidget(lst);
        layoutmain->addWidget(lstcontract);
    }
};
#endif //LAB10_11_CONTRACTGUI_H
