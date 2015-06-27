#include "modelpsy.h"

ModelPsy::ModelPsy(QObject *parent) : QAbstractTableModel(parent)
{

}

ModelPsy::~ModelPsy()
{
    qDeleteAll(psy);
    psy.clear();
}
