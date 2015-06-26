#include "listaklientow.h"

ListaKlientow::ListaKlientow()
{

}

ListaKlientow::~ListaKlientow()
{

}

void ListaKlientow::dodajKlienta(Klient* klient)
{
    listaKlientow.append(klient);
}

void ListaKlientow::usunKlienta(Klient* klient)
{
    listaKlientow.removeOne(klient);
}

Klient *ListaKlientow::getKlient(int id)
{
    for(QList<Klient*>::iterator it = listaKlientow.begin();
        it != listaKlientow.end(); ++it ) {
           if( (*it)->getId() == id )
               return *it;
    }
    return 0;
}

ListaKlientow::ListaKlientow(const ListaKlientow &){}

ListaKlientow &ListaKlientow::operator=(const ListaKlientow &)
{
    return *this;
}

