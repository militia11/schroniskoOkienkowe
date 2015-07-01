#include "modelrejestr.h"
#include "klient.h"
#include "pies.h"
#include <QMessageBox>

static const int LICZBA_KOLUMN(6);

ModelRejestr modelRejestr;

ModelRejestr::ModelRejestr(QObject *parent) : QAbstractTableModel(parent)
{
}

ModelRejestr::~ModelRejestr()
{
    qDeleteAll(wydania);
    wydania.clear();
}

int ModelRejestr::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return wydania.size();
}

int ModelRejestr::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return LICZBA_KOLUMN;
}

void ModelRejestr::insertRows(int row, int count, WydaniePsa *wydanie, const QModelIndex &parent)
{
    beginInsertRows(parent,row, row + count - 1);
    for ( int i=0; i < count; ++i) {
        wydania.insert(row + i, wydanie);
    }
    endInsertRows();
}

bool ModelRejestr::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    wydania.removeAt(row);
    endRemoveRows();
    return true;
}

QVariant ModelRejestr::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole) {
        return QVariant();
    }
    int rzad = index.row();
    switch( index.column() ) {
        case 0:
              return wydania[rzad]->getData();
        case 1:
              return wydania[rzad]->getPies()->getImie();
        case 2:
              return wydania[rzad]->getPies()->getId();
        case 3:
              return wydania[rzad]->getKlient()->getImie();
        case 4:
              return wydania[rzad]->getKlient()->getNazwisko();
        case 5:
              return wydania[rzad]->getKlient()->getId();
        default:
              return QVariant();
    }
}

Qt::ItemFlags ModelRejestr::flags(const QModelIndex &index) const
{
    if (index.isValid()) return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    else return 0;
}

QModelIndex ModelRejestr::createIndex(int row, int column, quintptr id) const
{
    Q_UNUSED(id);
    return QAbstractItemModel::createIndex(row,column);
}

QVariant ModelRejestr::headerData(int section, Qt::Orientation orientation, int role) const
{
    if ( orientation != Qt::Horizontal || role != Qt::DisplayRole )
        return QAbstractItemModel::headerData( section, orientation, role );
    switch ( section ) {
        case 0: return "Data wydania";
        case 1: return "Pies";
        case 2: return "ID psa";
        case 3: return "Klient Imie";
        case 4: return "Klient Nazwisko";
        case 5: return "ID klienta";
    }
    return QVariant();
}

bool ModelRejestr::setData(const QModelIndex &index, const QVariant &value, int role)
{
//    case 0: return "Data wydania";
//    case 1: return "Pies";
//    case 2: return "ID psa";
//    case 3: return "Klient Imie";
//    case 4: return "Klient Nazwisko";
//    case 5: return "ID klienta";
    if(role != Qt::EditRole) return false;
    int rzad = index.row(), col = index.column(); // pozniej przerobic na switch:
    if( col == 0 ) {
       ; // doroooooooooooobic
    }
    if( col == 1 ) {
        if( !value.toString().isEmpty() )
            wydania[rzad]->getPies()->setId( value.toInt() );
        else {
            QMessageBox::warning( 0, "UWAGA","<center>Nie można ustawić <b>pustego</b> imienia psa.<br> Proszę wprowadź poprawne imie psa ", QMessageBox::Ok);
        }
    }
    if( col == 2 ) {
        if( !value.toString().isEmpty() )
            wydania[rzad]->getPies()->setId( value.toInt() );
        else {
            QMessageBox::warning( 0, "UWAGA","<center>Nie można ustawić <b>pustego</b> numeru ID psa.<br> Proszę wprowadź poprawny numer ID psa ", QMessageBox::Ok);
        }
    }
//    if( col == 3 ) {
//        wydania[row]->setNumerTelefonu( value.toString() );
//    }
//    if( col == 4 ) {
//        wydania[row]->setUlica( value.toString() );
//    }
//    if( col == 5 ) {
//        wydania[row]->setNumerDomu( value.toInt() );
//    }
    QModelIndex indexAfterChanged = createIndex(rzad,col);
    emit dataChanged(indexAfterChanged,indexAfterChanged);
    return true;
}
