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

private:
     QList<Klient*> klienci;
};

#endif // MODELKLIENCI_H
