#include "modelpsy.h"
#include <QMessageBox>

static const int LICZBA_KOLUMN(5);

ModelPsy modelPsy;

ModelPsy::ModelPsy(QObject *parent) : QAbstractTableModel(parent)
{

}

ModelPsy::~ModelPsy()
{
    qDeleteAll(psy);
    psy.clear();
}

int ModelPsy::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return psy.size();
}

int ModelPsy::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return LICZBA_KOLUMN;
}

void ModelPsy::insertRows(int row, int count, Pies* pies, const QModelIndex &parent)
{
    beginInsertRows(parent,row, row + count - 1);
    for ( int i=0; i < count; ++i) {
        psy.insert(row + i, pies);
    }
    endInsertRows();
}

bool ModelPsy::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    psy.removeAt(row);
    endRemoveRows();
    return true;
}

QVariant ModelPsy::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole) {
        return QVariant();
    }
    int rzad = index.row();
    switch( index.column() ) {
        case 0:
              return psy[rzad]->getId();
        case 1:
              return psy[rzad]->getImie();
        case 2:
              return psy[rzad]->getWiek();
        case 3:
              return psy[rzad]->getRasa();
        case 4:
              if( psy[rzad]->getRodzaj() == Lagodny){
                  return QString("Łagodny");
              }
              else if( psy[rzad]->getRodzaj() == Agresywny){
                  return QString("Agresywny");
              }
              else if( psy[rzad]->getRodzaj() == Nieokreslony ){
                  return QString("Nieokreślony");
              }
              else if( psy[rzad]->getRodzaj() == DoDomu){
                  return QString("Do domu");
              }
              else if( psy[rzad]->getRodzaj() == NaPodworko ){
                  return QString("Na podwórko");
              }
        default:
              return QVariant();
    }
}

Qt::ItemFlags ModelPsy::flags(const QModelIndex &index) const
{
    if (index.isValid()) return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    else return 0;
}

QModelIndex ModelPsy::createIndex(int row, int column, quintptr id) const
{
    Q_UNUSED(id);
    return QAbstractItemModel::createIndex(row,column);
}

QVariant ModelPsy::headerData(int section, Qt::Orientation orientation, int role) const
{
    if ( orientation != Qt::Horizontal || role != Qt::DisplayRole )
        return QAbstractItemModel::headerData( section, orientation, role );
    switch ( section ) {
        case 0: return "ID psa";
        case 1: return "Imie";
        case 2: return "Wiek";
        case 3: return "Rasa";
        case 4: return "Kategoria";

    }
    return QVariant();
}

bool ModelPsy::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role != Qt::EditRole) return false;
    int rzad = index.row(), col = index.column(); // pozniej przerobic na switch:
    if( col == 0 ) {
        if( !value.toString().isEmpty() )
            psy[rzad]->setId( value.toInt() );
        else {
            QMessageBox::warning( 0, "UWAGA","<center>Nie można ustawić <b>pustego</b> numeru ID.<br> Proszę wprowadź poprawny numer ID ", QMessageBox::Ok);
        }
    }
    if( col == 1 ) {
        if( !value.toString().isEmpty() )
        psy[rzad]->setImie( value.toString() );
        else {
            QMessageBox::warning( 0, "UWAGA", "Nie można ustawić<b> pustego</b> imienia.<br> Proszę wprowadź poprawne imie psa. ", QMessageBox::Ok);
        }
    }
    if( col == 2 ) {
        psy[rzad]->setWiek( value.toInt() );
    }
    if( col == 3 ) {
        psy[rzad]->setRasa( value.toString() );
    }
    if( col == 4 ) {
        psy[rzad]->setRodzaj( value.toString() );
    }
    QModelIndex indexAfterChanged = createIndex(rzad,col);
    emit dataChanged(indexAfterChanged,indexAfterChanged);
    return true;
}

bool ModelPsy::sprawdzDostepnosc(int id)
{
    for(QList<Pies*>::iterator it = psy.begin();
        it != psy.end(); ++it ) {
           if( (*it)->getId() == id )
               return false;
    }
    return true;
}

Pies *ModelPsy::getPies(int rzad) const
{
    return psy[rzad];
}

