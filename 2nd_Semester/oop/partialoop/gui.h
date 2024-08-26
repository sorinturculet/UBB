//
// Created by sorn on 20-May-24.
//

#ifndef PRACTICOOP_GUI_H
#define PRACTICOOP_GUI_H
#include<algorithm>
#include<QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include"service.h"
#include<QListWidget>
#include <iostream>
#include<QLineEdit>
#include<QMessageBox>
#include<QPushButton>
class guiElev:public QWidget{
public:
    //Constructorul
    guiElev(Service srv):srv(srv){
        initGUI();
        loadData();
        initConnect();
    }
private:
    Service srv;
    QHBoxLayout* lyMain=new QHBoxLayout{};
    QListWidget* listElevi=new QListWidget{};
    QListWidget* listAteliere=new QListWidget{};
    QPushButton* sortare=new QPushButton{"Sortare"};
    QLineEdit* detaliiAteliere=new QLineEdit{};
    QHBoxLayout* lyButtons=new QHBoxLayout{};
    void initGUI(){
        setLayout(lyMain);
        QVBoxLayout* lyLeft=new QVBoxLayout{};
        lyMain->addLayout(lyLeft);
        QVBoxLayout* lyRight=new QVBoxLayout{};
        lyMain->addLayout(lyRight);
        lyRight->addWidget(listElevi);
        lyRight->addWidget(listAteliere);
        lyLeft->addWidget(detaliiAteliere);
        lyLeft->addWidget(sortare);
        lyRight->addLayout(lyButtons);

    }
    void loadData(){
        listElevi->clear();
        for(auto& elev: srv.getAllElevi()){
            string dateElev=elev.getNume()+" | "+elev.getScoala();
            listElevi->addItem(QString::fromStdString(dateElev));
        }
        listAteliere->clear();
        for(auto& atelier:srv.getAllAteliere()){
            cout<<atelier.getNume()<<endl;
            string dateAtelier=atelier.getNume();
            listAteliere->addItem(QString::fromStdString(dateAtelier));
        }

    }
    //Conecteaza butoanele
    void initConnect(){
        QObject::connect(sortare,&QPushButton::clicked,[&](){
            try{
                srv.sortare();
            }
            catch(exception& ex){
                QMessageBox::critical(this,"Error",ex.what());
            }
            loadData();
        });
        connect(listElevi, &QListWidget::itemSelectionChanged, [&]() {
            string nume=listElevi->currentItem()->text().toStdString();
            string numeof;
            int i=0;
            while(nume[i]!=' '){
                numeof+=nume[i];
                i++;
            }
            int nrelev=0;
            for(auto elev:srv.getAllElevi()){

                if(elev.getNume()==numeof){
                    nrelev=elev.getNrMatricol();
                }
            }
            string detalii;
            for(auto& atelier:srv.getAllAteliere()){
                for(auto& numar:atelier.getElevi()){
                    cout<<numar<<" "<<nrelev<<endl;
                    if(numar==nrelev){
                        cout<<numar;
                        detalii+=atelier.getNume();
                        detalii+=" ";
                        break;
                    }
                }
            }
            detaliiAteliere->setText(QString::fromStdString(detalii));
            nume.clear();
        });
        connect(listAteliere, &QListWidget::itemSelectionChanged, [&]() {

            for(int i = 0; i < listAteliere->count(); ++i) {
                QPushButton* btn = new QPushButton(listAteliere->item(i)->text(), this);

                connect(btn, &QPushButton::clicked, [this, btn]() {

                    string atelierName = btn->text().toStdString();
                    for(auto& atelier : srv.getAllAteliere()) {
                        if(atelier.getNume() == atelierName) {
                            for(auto& numar : atelier.getElevi()) {
                                for(auto& elev : srv.getAllElevi()) {
                                    if(elev.getNrMatricol() == numar) {
                                        QMessageBox::information(this, "Student Name", QString::fromStdString(elev.getNume()));                                    }
                                }
                            }
                        }
                    }
                });


                lyButtons->addWidget(btn);
            }
        });
    }

};
#endif //PRACTICOOP_GUI_H
