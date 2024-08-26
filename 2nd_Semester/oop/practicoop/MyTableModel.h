#pragma once
#include <QAbstractTableModel>
#include "Domain.h"
#include <vector>


class MyTableModel : public QAbstractTableModel {
private:
    vector<Parcare> v;

public:
    /*
     * returneaza numarul de randuri
     *returns int
     */
    int rowCount(const QModelIndex& parent = QModelIndex()) const {
        return v.size();
    }
    /*
     * returneaza numarul de coloane
     *returns int
     */
    int columnCount(const QModelIndex& parent = QModelIndex()) const {
        return 5;
    }
    /*
     * returneaza campul din header
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const {
        if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
            if (section == 0) {
                return "Id";
            }
            if (section == 1) {
                return "Adresa";
            }
            if (section == 2) {
                return "Linii";
            }
            if (section == 3) {
                return "Coloane";
            }
            if (section == 4) {
                return "Stare";
            }
        }
        return QVariant{};
    }
    /*
     * returneaza tabelu
     */
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const {
        if (role == Qt::DisplayRole) {
            int row = index.row();
            Parcare t = v[row];

            if (index.column() == 0) {
                return t.getId();
            }
            if (index.column() == 1) {
                return QString::fromStdString(t.getAdresa());
            }
            if (index.column() == 2) {
                return t.getLinii();
            }
            if (index.column() == 3) {
                return t.getColoane();
            }
            if(index.column()==4){
                return QString::fromStdString(t.getStare());
            }
        }
        return QVariant{};
    }

    void setData(vector<Parcare> v1) {
        emit layoutAboutToBeChanged();
        v = v1;
        emit layoutChanged();
    }
};