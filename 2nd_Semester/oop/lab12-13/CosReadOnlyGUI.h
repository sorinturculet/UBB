//
// Created by sorn on 26-May-24.
//

#ifndef LAB10_11_COSREADONLYGUI_H
#define LAB10_11_COSREADONLYGUI_H
#include<qwidget.h>
#include <QPainter>
#include"Service.h"
class CosReadOnlyGUI:public QWidget, public Observer {
    void paintEvent(QPaintEvent* ev)override{
        QPainter p{this};
        for(auto& disci:srv.getAllFromContract()){
            int x=rand()%300;
            int y=rand()%300;
            p.drawRect(x,y,20,80);
        }
    }
public:
    CosReadOnlyGUI(DisciplinaService& srv):srv{srv}{
        srv.addObserver(this);
        initGUI();
        loadData();
    }
    void update() override{
        repaint();
    }
private:
    DisciplinaService& srv;

    void initGUI();
    void loadData();
    ~CosReadOnlyGUI(){
        srv.removeObserver(this);
    }
};


#endif //LAB10_11_COSREADONLYGUI_H
