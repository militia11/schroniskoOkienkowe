#ifndef LISTAKLIENTOW_H
#define LISTAKLIENTOW_H

#include "klient.h"
#include <QList>

class ListaKlientow
{
public:
    ListaKlientow();
    ~ListaKlientow();

    void dodajKlienta(Klient *klient);
    void usunKlienta(Klient *klient);
    Klient* getKlient(int id);

private:
    ListaKlientow(const ListaKlientow&);
    ListaKlientow& operator=(const ListaKlientow&);

    QList<Klient*> listaKlientow;
};

#endif // LISTAKLIENTOW_H
