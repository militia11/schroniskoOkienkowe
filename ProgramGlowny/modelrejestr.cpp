#include "modelrejestr.h"
#include "klient.h"
#include "pies.h"

static const int LICZBA_KOLUMN(5);

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
    int row = index.row();
    switch( index.column() ) {
        case 0:
              return wydania[row]->getKlient()->getImie();
        case 1:
              return wydania[row]->getPies()->getImie();
//        case 2:
//              return wydania[row]->getData(); // dorobic
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
        case 0: return "Klient:";
        case 1: return "Pies";
//        case 2: return "Data:";
//        case 3: return "";
//        case 4: return "x";
    }
    return QVariant();
}

bool ModelRejestr::setData(const QModelIndex &index, const QVariant &value, int role)
{
    /*if(role != Qt::EditRole) return false;
    int row = index.row(), col = index.column(); // pozniej przerobic na switch:
    if( col == 0 ) {
        if( !value.toString().isEmpty() ) m_People[row]->setName(value.toString());
        else {
            QMessageBox::warning( 0, "Warning Incorrect Person Name","<center>You can't set <b>empty</b> word as Person's name.<br> Please enter correct Person's' name. ",QMessageBox::Ok);
        }
    }
    if( col == 1 ) {
        m_People[row]->setPhoneNumber(value.toString());
    }
    if( col == 2 ) {
        m_People[row]->setCity(value.toString());
    }
    if( col == 3 ) {
        m_People[row]->setAge(value.toInt());
    }
    if( col == 4 ) {
        m_People[row]->setPESEL(value.toLongLong());
    }
    QModelIndex indexAfterChanged = createIndex(row,col);
    emit dataChanged(indexAfterChanged,indexAfterChanged)*/;
    return true;
}



// takie  byly
//bool PersonItemModel::setData(const QModelIndex &index, const QVariant &value, int role) {

//}
//QVariant PersonItemModel::headerData(const int section, const Qt::Orientation orientation, const int role) const {

//}


//niewykorzystane jeszcze

//void PersonItemModel::insertRows(int row, int count,QList<Person*> people, const QModelIndex &parent ) {
//    beginInsertRows(parent,row, row + count - 1);
//    for ( int i=0; i < count; ++i) {
//        m_People.insert(row + i, people[i]);
//    }
//    endInsertRows();
//}
//Person* PersonItemModel::getItem(int row) const {
//    return m_People[row];
//}

//QList<Person*> PersonItemModel::getData() const {
//    return m_People;
//}
