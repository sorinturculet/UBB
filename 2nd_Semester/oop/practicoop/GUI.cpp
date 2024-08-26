//
// Created by sorn on 27-Jun-24.
//

#include <QMessageBox>
#include "GUI.h"
#include "GUIParcare.h"

void GUI::initGUI() {
    setLayout(lyMain);
    tbl->setModel(model); tbl->setColumnWidth(1, 200);
    lyMain->addWidget(tbl);
    lyMain->addLayout(lyLeft);
    lyForm->addRow("Id: ", txtId);
    lyForm->addRow("Adresa: ", txtAdresa);
    lyForm->addRow("NrLinii: ", txtLinii);
    lyForm->addRow("NrColoane: ", txtColoane);
    lyForm->addRow("Stare: ", txtStare);
    lyForm->addWidget(btnAdauga);
    lyForm->addWidget(btnModify);

    lyForm->addWidget(btnRandom);
    lyForm->addWidget(btnGestiune);
    lyMain->addLayout(lyRight);
    lyMain->addLayout(lyForm);
}
void GUI::connectActions() {
    connect(btnAdauga, &QPushButton::clicked, [&](){
        try{
            int id=txtId->text().toInt();
            string adresa=txtAdresa->text().toStdString();
            int linii=txtLinii->text().toInt();
            int coloane=txtColoane->text().toInt();
            string stare=txtStare->text().toStdString();
            srv.addParcare(id,adresa,linii,coloane,stare);
        }
        catch(runtime_error){
            QMessageBox::information(this,"Eroare","Date invalide");
        }
    });
    connect(btnModify, &QPushButton::clicked, [&](){
        try{
            int id=txtId->text().toInt();
            string adresa=txtAdresa->text().toStdString();
            int linii=txtLinii->text().toInt();
            int coloane=txtColoane->text().toInt();
            string stare=txtStare->text().toStdString();
            srv.modificaStare(id,adresa,linii,coloane,stare);
        }
        catch(runtime_error){
            QMessageBox::information(this,"Eroare","Date invalide");
        }
    });
    connect(btnGestiune, &QPushButton::clicked, [&](){
        int id=txtId->text().toInt();
        GUIParcare* guiParcare=new GUIParcare(srv,id);
        GUIParcare* guiParcare2=new GUIParcare(srv,id);
        guiParcare->show();
        guiParcare2->show();

    });
    connect(btnRandom, &QPushButton::clicked, [&](){
        int id=txtId->text().toInt();
        string random=srv.random(id);
        txtStare->setText(QString::fromStdString(random));
    });
}