//
// Created by sorn on 27-Jun-24.
//

#ifndef PRACTICOOP_GUIPARCARE_H
#define PRACTICOOP_GUIPARCARE_H

#include<QWidget>
#include<QHBoxLayout>
#include<QVBoxLayout>
#include<QPushButton>
#include<QLineEdit>
#include<QListWidget>
#include<QTableView>
#include <QLabel>
#include <iostream>
#include "Service.h"
class GUIParcare:public QWidget,public Observer {
private:
    int id;
    Service& srv;
    QHBoxLayout* lyMain=new QHBoxLayout;
    QVBoxLayout* lyLeft=new QVBoxLayout;
    QVBoxLayout* lyRight=new QVBoxLayout;
    QGridLayout* lyForm=new QGridLayout;
    int matrix[5][5];
public:
    /*
     * Constructor GUIParcare
     */
    GUIParcare(Service& srv,int id):srv{srv},id{id}{
        srv.addObserver(this);
        initGUI();
    };
    /*
     * initializeaza
     */
    void initGUI(){
        setLayout(lyMain);
        loadData();
        lyMain->addLayout(lyForm);
        lyMain->addLayout(lyLeft);
        lyMain->addLayout(lyRight);
    }
    /*
     * incarca butoanele in tabel.
     */
    void loadData(){

        for(auto loc:srv.getAllSorted())
            if(loc.getId()==id)
            {

                string stare=loc.getStare();
                for(int i=0;i<loc.getLinii();i++)
                    for(int j=0;j<loc.getColoane();j++)
                    {
                        int index = i * loc.getColoane() + j;
                        cout<<index<<" "<<endl;
                        matrix[i][j]=i * loc.getColoane() + j;
                        if(stare[index]=='X') {
                            QPushButton *btn = new QPushButton{"X"};
                            lyForm->addWidget(btn, i, j);
                            connect(btn, &QPushButton::clicked, [&,i,j](){
                                cout<<matrix[i][j]<<"  PRESSED\n";
                                srv.modificaStareLoc(id,matrix[i][j],'-');
                            });
                        }
                        else
                        {
                            QPushButton *btn = new QPushButton{"-"};
                            lyForm->addWidget(btn, i, j);
                            connect(btn, &QPushButton::clicked, [&,i,j](){
                                cout<<matrix[i][j]<<"  PRESSED\n";
                                srv.modificaStareLoc(id,matrix[i][j],'X');
                            });
                        }

                    }
            }

    }
    /*
     * updateaza in caz ca se schimba ceva
     */
    void update()override{
        loadData();
    }
};

#endif //PRACTICOOP_GUIPARCARE_H
