#ifndef MODELKLIENCI_H
#define MODELKLIENCI_H

#include <QObject>
#include <QAbstractTableModel>
#include <QList>
#include "klient.h"

class ModelKlienci : public QAbstractTableModel
{
    Q_OBJECT

public:
    explicit ModelKlienci(QObject* parent = 0);
    ~ModelKlienci();

    int rowCount(const QModelIndex &parent= QModelIndex()) const ;
    int columnCount(const QModelIndex &parent= QModelIndex()) const ;

    void insertRows(int row, int count, Klient *klient, const QModelIndex &parent = QModelIndex() );
    bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QModelIndex createIndex(int row, int column, quintptr id = 0) const;

    QVariant headerData(int section, Qt::Orientation orientation, int role) const;
    bool setData(const QModelIndex &index, const QVariant &value, int role);

    bool sprawdzDostepnosc( int id);
    Klient* getKlient(int rzad) const;
    QStringList getListaKlientow() const;

private:
     QList<Klient*> klienci;
};

#endif // MODELKLIENCI_H
