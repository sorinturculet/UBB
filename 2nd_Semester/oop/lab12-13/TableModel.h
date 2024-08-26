//
// Created by sorn on 27-May-24.
//

#ifndef LAB10_11_TABLEMODEL_H
#define LAB10_11_TABLEMODEL_H

#include <QAbstractTableModel>
#include "Domain.h"

class myTableModel: public QAbstractTableModel{
    std::vector<Disciplina> discipline;
public:
    myTableModel(std::vector<Disciplina> discipline):discipline{discipline}{

    }
    int rowCount(const QModelIndex &parent = QModelIndex()) const override{
        return discipline.size();
    }
    int columnCount(const QModelIndex &parent = QModelIndex()) const override{
        return 4;
    }
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override{\
        qDebug()<<"row :"<<index.row()<<" column :"<<index.column();
        if(role==Qt::DisplayRole){
            Disciplina d=discipline[index.row()];
            if(index.column()==0)
                return QString::fromStdString(d.getDenumire());
            if(index.column()==1)
                return QString::number(d.getOre());
            if(index.column()==2)
                return QString::fromStdString(d.getTip());
            if(index.column()==3)
                return QString::fromStdString(d.getCadruDidactic());

        }
        return QVariant();
    }
    void setDiscipline(std::vector<Disciplina> discipline){
        this->discipline=discipline;
        auto topLeft = createIndex(0, 0);
        auto bottomRight = createIndex(rowCount(), columnCount());
        emit dataChanged(topLeft, bottomRight);
    }

};


#endif //LAB10_11_TABLEMODEL_H
