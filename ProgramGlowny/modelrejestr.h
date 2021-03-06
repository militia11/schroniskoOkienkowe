﻿#ifndef MODELREJESTR_H
#define MODELREJESTR_H

#include <QAbstractTableModel>
#include "wydaniepsa.h"

class ModelRejestr : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ModelRejestr(QObject* parent = 0);
    ~ModelRejestr();

    int rowCount(const QModelIndex &parent= QModelIndex()) const ;
    int columnCount(const QModelIndex &parent= QModelIndex()) const ;

    void insertRows(int row, int count, WydaniePsa *wydanie, const QModelIndex &parent = QModelIndex() );
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QModelIndex createIndex(int row, int column, quintptr id = 0) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

private:
    QList<WydaniePsa*> wydania;
};

#endif // MODELREJESTR_H
