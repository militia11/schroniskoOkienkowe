#include <QMessageBox>
#include "modelklienci.h"

static const int LICZBA_KOLUMN(8);

ModelKlienci modelKlienci;

ModelKlienci::ModelKlienci(QObject *parent) : QAbstractTableModel(parent)
{

}

ModelKlienci::~ModelKlienci()
{
    qDeleteAll(klienci);
    klienci.clear();
}

int ModelKlienci::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent)
    return klienci.size();
}

int ModelKlienci::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return LICZBA_KOLUMN;
}

void ModelKlienci::insertRows(int row, int count, Klient* klient, const QModelIndex &parent)
{
    beginInsertRows(parent,row, row + count - 1);
    for ( int i=0; i < count; ++i) {
        klienci.insert(row + i, klient);
    }
    endInsertRows();
}

bool ModelKlienci::removeRows(int row, int count, const QModelIndex &parent)
{
    beginRemoveRows(parent, row, row + count - 1);
    klienci.removeAt(row);
    endRemoveRows();
    return true;
}

QVariant ModelKlienci::data(const QModelIndex &index, int role) const
{
    if(role != Qt::DisplayRole) {
        return QVariant();
    }
    int rzad = index.row();
    switch( index.column() ) {
        case 0:
              return klienci[rzad]->getId();
        case 1:
              return klienci[rzad]->getImie();
        case 2:
              return klienci[rzad]->getNazwisko();
        case 3:
              return klienci[rzad]->getNumerTelefonu();
        case 4:
              return klienci[rzad]->getUlica();
        case 5:
              return klienci[rzad]->getNumerDomu();
        case 6:
              return klienci[rzad]->getMiasto();
        case 7:
              return klienci[rzad]->getKodPocztowy();
        default:
              return QVariant();
    }
}

Qt::ItemFlags ModelKlienci::flags(const QModelIndex &index) const
{
    if (index.isValid()) return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
    else return 0;
}

QModelIndex ModelKlienci::createIndex(int row, int column, quintptr id) const
{
    Q_UNUSED(id);
    return QAbstractItemModel::createIndex(row,column);
}

QVariant ModelKlienci::headerData(int section, Qt::Orientation orientation, int role) const
{
    if ( orientation != Qt::Horizontal || role != Qt::DisplayRole )
        return QAbstractItemModel::headerData( section, orientation, role );
    switch ( section ) {
        case 0: return "ID klienta";
        case 1: return "Imie";
        case 2: return "Nazwisko";
        case 3: return "Numer Telefonu";
        case 4: return "Ulica";
        case 5: return "Nr domu";
        case 6: return "Miasto";
        case 7: return "Kod pocztowy";
    }
    return QVariant();
}

bool ModelKlienci::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if(role != Qt::EditRole) return false;
    int rzad = index.row(), col = index.column(); // pozniej przerobic na switch:
    if( col == 0 ) {
        if( !value.toString().isEmpty() )
            klienci[rzad]->setId( value.toInt() );
        else {
            QMessageBox::warning( 0, "UWAGA","<center>Nie można ustawić <b>pustego</b> numeru ID.<br> Proszę wprowadź poprawny numer ID ", QMessageBox::Ok);
        }
    }
    if( col == 1 ) {
        if( !value.toString().isEmpty() )
        klienci[rzad]->setImie( value.toString() );
        else {
            QMessageBox::warning( 0, "UWAGA","Nie można ustawić<b> pustego</b> imienia.<br> Proszę wprowadź poprawne imie klienta. ", QMessageBox::Ok);
        }
    }
    if( col == 2 ) {
        if( !value.toString().isEmpty() )
        klienci[rzad]->setNazwisko( value.toString() );
        else {
            QMessageBox::warning( 0, "UWAGA","Nie można ustawić<b> pustego</b> nazwiska.<br> Proszę wprowadź poprawne imie klienta. ", QMessageBox::Ok);
        }
    }
    if( col == 3 ) {
        klienci[rzad]->setNumerTelefonu( value.toString() );
    }
    if( col == 4 ) {
        klienci[rzad]->setUlica( value.toString() );
    }
    if( col == 5 ) {
        klienci[rzad]->setNumerDomu( value.toInt() );
    }
    if( col == 6 ) {
        klienci[rzad]->setMiasto( value.toString() );
    }
    if( col == 7 ) {
        klienci[rzad]->setKodPocztowy( value.toString() );
    }
    QModelIndex indexAfterChanged = createIndex(rzad,col);
    emit dataChanged(indexAfterChanged,indexAfterChanged);
    return true;
}

bool ModelKlienci::sprawdzDostepnosc(int id)
{
    for(QList<Klient*>::iterator it = klienci.begin();
        it != klienci.end(); ++it ) {
           if( (*it)->getId() == id )
               return false;
    }
    return true;
}

Klient *ModelKlienci::getKlient(int rzad) const
{
    if( klienci.count() == 0 ) {
        return 0;
    }
    return klienci[rzad];
}

QStringList ModelKlienci::getListaKlientow() const
{
    QStringList wynikowaListaKlientow;
        for(QList<Klient*>::const_iterator it = klienci.begin();
            it != klienci.end(); ++it ) {
            wynikowaListaKlientow.append( (*it)->toString() );
        }
        return wynikowaListaKlientow;
}
