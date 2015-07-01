#ifndef MODELPSY_H
#define MODELPSY_H

#include <QObject>
#include <QAbstractTableModel>
#include <QList>
#include "pies.h"

class ModelPsy : public QAbstractTableModel
{
    Q_OBJECT

public:
     explicit ModelPsy(QObject* parent = 0);
     ~ModelPsy();

    int rowCount(const QModelIndex &parent= QModelIndex()) const ;
    int columnCount(const QModelIndex &parent= QModelIndex()) const ;

    void insertRows(int row, int count, Pies *pies, const QModelIndex &parent = QModelIndex() );
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QModelIndex createIndex(int row, int column, quintptr id = 0) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    bool sprawdzDostepnosc( int id);
    Pies* getPies(int rzad) const;

private:
    QList<Pies*> psy;
};

#endif // MODELPSY_H
