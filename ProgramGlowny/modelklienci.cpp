#include "modelklienci.h"

ModelKlienci::ModelKlienci(QObject *parent) : QAbstractTableModel(parent)
{

}



ModelKlienci::~ModelKlienci()
{
    qDeleteAll(klienci);
    klienci.clear();
}
