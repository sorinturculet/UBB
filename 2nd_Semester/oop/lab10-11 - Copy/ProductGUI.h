//
// Created by sorn on 12-May-24.
//

#ifndef TESTQT_PRODUCTGUI_H
#define TESTQT_PRODUCTGUI_H
#include<QtWidgets/qwidget.h>
#include <QApplication>
#include <QPushButton>
#include<QMessageBox>
#include <QLabel>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QListWidget>
#include <QFormLayout>
#include <QTableWidget>
#include "Service.h"
#include "ContractGUI.h"
using namespace std;

class ProductGUI:public QWidget{
public:
    ProductGUI(DisciplinaService& srv):srv{srv} {
        initGUI();
        loadData();
        initConnect();
    }
private:
    DisciplinaService& srv;

    QHBoxLayout* layoutmain = new QHBoxLayout{};
    QVBoxLayout* typesButtonsLabels = new QVBoxLayout;

    QListWidget* lst=new QListWidget;

    QWidget* lstMap=new QWidget;

    QTableWidget* lst2=new QTableWidget(4,4,this);


    QPushButton* addbtn=new QPushButton{"&adauga"};
    QPushButton* modifybtn=new QPushButton{"&modify"};
    QPushButton* deletebtn=new QPushButton{"&delete"};
    QPushButton* exitbtn=new QPushButton{"&Exit"};
    QPushButton* sortbtn=new QPushButton{"&Sort"};
    QPushButton* filterbtn=new QPushButton{"&Filter"};
    QPushButton* contractbtn=new QPushButton{"&Contract"};
    QPushButton* undobtn=new QPushButton{"&UNDO"};

    map<string,int> allProductMap;

    QLineEdit* nametxt=new QLineEdit;
    QLineEdit* typetxt=new QLineEdit;
    QLineEdit* oretxt=new QLineEdit;
    QLineEdit* cadrutxt=new QLineEdit;
    QLineEdit* filtertxt1=new QLineEdit;
    QLineEdit* filtertxt2=new QLineEdit;
    QLineEdit* sorttxt=new QLineEdit;
    void initConnect(){
        connect(lst, &QListWidget::itemSelectionChanged, [&]() {

            if (lst->selectedItems().empty()) {
                return;
            }
            string activityText = lst->selectedItems()[0]->text().toStdString();
            string title;
            string ore;
            string type;
            string cadrudidactic;
            int i = 0;

            while (activityText[i] != ':')
                i++;
            i += 2;
            while (activityText[i] != ':')
                i++;
            i += 2;
            while (activityText[i] != '|') {
                title += activityText[i];
                i++;
            }
            title.pop_back();
            // Obtinem tipul
            while (activityText[i] != ':')
                i++;
            i += 2;
            while (activityText[i] != '|') {
                ore += activityText[i];
                i++;
            }
            ore.pop_back();
            while (activityText[i] != ':')
                i++;
            i += 2;
            while (activityText[i] != '|') {
                type += activityText[i];
                i++;
            }
            type.pop_back();
            // Obtinem durata
            while (activityText[i] != ':')
                i++;
            i += 2;
            while (activityText[i] != NULL) {
                cadrudidactic += activityText[i];
                i++;
            }
            nametxt->setText(QString::fromStdString(title));
            oretxt->setText(QString::fromStdString(ore));
            typetxt->setText(QString::fromStdString(type));
            cadrutxt->setText(QString::fromStdString(cadrudidactic));

        });
        QObject::connect(exitbtn,&QPushButton::clicked,[&](){
            qDebug()<<"Exit button pressed";
            //QMessageBox::information(nullptr,"Info","asasas");
            close();
        });
        QObject::connect(addbtn,&QPushButton::clicked,[&](){
            auto nume=nametxt->text();
            auto tip=typetxt->text();
            auto ore=oretxt->text();
            auto cadrudidactic=cadrutxt->text();
            //call service srv.add(QString::fromStdString(nume),tip,pret)
            //de adaugat conversie
            try {
                srv.addDisciplina(nume.toStdString(),ore.toInt(),tip.toStdString(),cadrudidactic.toStdString());
            }
            catch(ValidatorException& ve){
                QMessageBox::information(nullptr,"Info",QString::fromStdString("Date invalide."));
            }
            catch(RepoException& re){
                string msg=re.getErrorMessage();
                QMessageBox::information(nullptr,"Info",QString::fromStdString(msg));
            }
            //load data.dupaa dauga
            loadData();
        });
        QObject::connect(modifybtn,&QPushButton::clicked,[&](){
            auto nume=nametxt->text();
            auto tip=typetxt->text();
            auto ore=oretxt->text();
            auto cadrudidactic=cadrutxt->text();
            //call service srv.add(QString::fromStdString(nume),tip,pret)
            //de adaugat conversie
            try{
                srv.modifyDisciplina(nume.toStdString(),ore.toInt(),tip.toStdString(),cadrudidactic.toStdString());
            }
            catch(RepoException& re){
                QMessageBox::information(nullptr,"Info",QString::fromStdString("Date invalide."));
            }

            //load data.dupaa dauga
            loadData();
        });
        QObject::connect(deletebtn,&QPushButton::clicked,[&](){
            auto nume=nametxt->text();
            auto tip=typetxt->text();
            auto ore=oretxt->text();
            auto cadrudidactic=cadrutxt->text();
            //call service srv.add(QString::fromStdString(nume),tip,pret)
            //de adaugat conversie
            try{
                srv.deleteDisciplina(nume.toStdString(),cadrudidactic.toStdString());
            }
            catch(RepoException& re){

                QMessageBox::information(nullptr,"Info",QString::fromStdString("Date invalide."));
            }
            //load data.dupaa dauga
            loadData();
        });
        QObject::connect(filterbtn,&QPushButton::clicked,[&](){
            auto cadru=filtertxt1->text();
            auto ore=filtertxt2->text();
            //call service srv.add(QString::fromStdString(nume),tip,pret)
            //de adaugat conversie
            vector<Disciplina> Disci=srv.filter(cadru.toStdString(),ore.toInt());
            //load data.dupaa dauga
            lst->clear();
            for(const auto& elem:Disci){
                string disci= "Disciplina : Denumire: " + elem.getDenumire() + " | Ore: " + to_string(elem.getOre()) + " | Tip: " + elem.getTip()+ " | Cadru Didactic: " + elem.getCadruDidactic();
                lst->addItem(QString::fromStdString(disci));
            }
        });
        QObject::connect(sortbtn,&QPushButton::clicked,[&](){
            auto crt=sorttxt->text();
            //call service srv.add(QString::fromStdString(nume),tip,pret)
            //de adaugat conversie
            vector<Disciplina> Disci=srv.sort(crt.toStdString());
            //load data.dupaa dauga
            lst->clear();
            for(const auto& elem:Disci){
                string disci= "Disciplina : Denumire: " + elem.getDenumire() + " | Ore: " + to_string(elem.getOre()) + " | Tip: " + elem.getTip()+ " | Cadru Didactic: " + elem.getCadruDidactic();
                lst->addItem(QString::fromStdString(disci));
            }
        });
        QObject::connect(contractbtn,&QPushButton::clicked,[&](){
            ContractGUI* newWindow = new ContractGUI(srv);
            newWindow->show();
        });
        QObject::connect(undobtn,&QPushButton::clicked,[&](){
            try {
                srv.undo();
            }
            catch (RepoException& re){
                QMessageBox::information(nullptr,"Info",QString::fromStdString(re.getErrorMessage()));
            }
            loadData();
        });
        auto it = allProductMap.begin();
        while (it != allProductMap.end()) {
            QHBoxLayout* typeLy = new QHBoxLayout;
            QPushButton* typeBtn = new QPushButton(QString::fromStdString(it->first));
            QLabel* typeLbl = new QLabel("");

            typeLy->addWidget(typeBtn);
            typeLy->addWidget(typeLbl);

            connect(typeBtn, &QPushButton::clicked, [=]() {
                string key = typeBtn->text().toStdString();
                map<string, int> typesCpy = allProductMap;

                QMessageBox::information(this, "Information about type", QString::fromStdString(key) + " has " + QString::number(typesCpy[key]) + " appearences.");
            });

            typesButtonsLabels->addLayout(typeLy);
            it++;
        }
    }
    void loadData(){
        lst->clear();
        vector<Disciplina> allProduct=srv.getAllDiscipline();
        for(const auto& elem:allProduct){
            string disci= "Disciplina : Denumire: " + elem.getDenumire() + " | Ore: " + to_string(elem.getOre()) + " | Tip: " + elem.getTip()+ " | Cadru Didactic: " + elem.getCadruDidactic();
            lst->addItem(QString::fromStdString(disci));
        }

        //map
        allProductMap=srv.get_map();


        lst2->clear();
        QStringList headers;
        headers << "Denumire" << "Ore" << "Tip" << "Cadru Didactic";
        lst2->setHorizontalHeaderLabels(headers);

        lst2->setRowCount(allProduct.size());
        lst2->setColumnCount(4);
        int row=0;
        for(const auto& elem:allProduct){
            lst2->setItem(row,0,new QTableWidgetItem(QString::fromStdString(elem.getDenumire())));
            lst2->setItem(row,1,new QTableWidgetItem(QString::fromStdString(to_string(elem.getOre()))));
            lst2->setItem(row,2,new QTableWidgetItem(QString::fromStdString(elem.getTip())));
            lst2->setItem(row,3,new QTableWidgetItem(QString::fromStdString(elem.getCadruDidactic())));
            row++;
        }
    }
    void initGUI(){//ASEZ ELEMENTELE IN FEREASTRA.
        setLayout(layoutmain);
        auto stgLy= new QVBoxLayout{};

        auto formLy=new QFormLayout{};
        formLy->addRow("Name", nametxt);
        formLy->addRow("Ore", oretxt);
        formLy->addRow("Tip", typetxt);
        formLy->addRow("Cadru Didactic", cadrutxt);
        stgLy->addLayout(formLy);


        auto lyBtn=new QHBoxLayout{};
        lyBtn->addWidget(addbtn);
        lyBtn->addWidget(deletebtn);
        lyBtn->addWidget(modifybtn);
        lyBtn->addWidget(exitbtn);

        auto lyBtn2=new QHBoxLayout{};
        lyBtn2->addWidget(filterbtn);

        auto formLy2=new QFormLayout{};
        formLy2->addRow("Filter by cadru didactic", filtertxt1);
        formLy2->addRow("Filter by number of hours", filtertxt2);

        auto lyBtn3=new QHBoxLayout{};
        lyBtn3->addWidget(sortbtn);

        auto formLy3=new QFormLayout{};
        formLy3->addRow("Sort(denumire/tip/ore/cadrudidactic)", sorttxt);

        stgLy->addLayout(lyBtn);
        stgLy->addLayout(formLy2);
        stgLy->addLayout(lyBtn2);
        stgLy->addLayout(formLy3);
        stgLy->addLayout(lyBtn3);
        stgLy->addWidget(contractbtn);
        stgLy->addWidget(undobtn);
        layoutmain->addLayout(stgLy );

        layoutmain->addWidget(lst);
        layoutmain->addLayout(typesButtonsLabels);
        layoutmain->addWidget(lst2);
    }
};
#endif //TESTQT_PRODUCTGUI_H
