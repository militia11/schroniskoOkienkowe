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

private:
    QList<Pies*> psy;
};

#endif // MODELPSY_H
