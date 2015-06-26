#include "listapsow.h"

ListaPsow gListaPsow;

ListaPsow::~ListaPsow()
{
    qDeleteAll(listaPsow); // usunięcie wskaźników
    listaPsow.clear();     // wyczyszczenie listy
}

void ListaPsow::dodajPsa(Pies *pies)
{
    listaPsow.append(pies);
}

void ListaPsow::usunPsa(Pies* pies)
{
    listaPsow.removeOne(pies);
}

QStringList ListaPsow::getListaPsow(RodzajPsa rodzaj)
{
    QStringList wynikowaListaPsow;
    for(QList<Pies*>::iterator it = listaPsow.begin();
        it != listaPsow.end(); ++it ) {
        if( (*it)->getRodzaj() == rodzaj) {
            wynikowaListaPsow.append( (*it)->toString() );
        }
    }
    return wynikowaListaPsow;
}

QStringList ListaPsow::getListaPsow()
{
    QStringList wynikowaListaPsow;
    for(QList<Pies*>::iterator it = listaPsow.begin();
        it != listaPsow.end(); ++it ) {
            wynikowaListaPsow.append( (*it)->toString() );
    }
    return wynikowaListaPsow;
}

Pies* ListaPsow::getPies(int id)
{
    for(QList<Pies*>::iterator it = listaPsow.begin();
        it != listaPsow.end(); ++it ) {
           if( (*it)->getId() == id )
               return *it;
    }
    return 0;
}

ListaPsow::ListaPsow(const ListaPsow &) {}

ListaPsow &ListaPsow::operator=(const ListaPsow)
{
    return *this;
}



