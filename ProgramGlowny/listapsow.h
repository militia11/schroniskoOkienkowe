#ifndef LISTAPSOW_H
#define LISTAPSOW_H

#include <QList>
#include <QStringList>
#include "pies.h"

class ListaPsow
{
public:
    ListaPsow() {}
    ~ListaPsow();

    void dodajPsa(Pies* pies);
    void usunPsa(Pies *pies);
    QStringList getListaPsow();
    QStringList getListaPsow(RodzajPsa rodzaj);
    Pies *getPies(int id);

private:
    ListaPsow(const ListaPsow&);
    ListaPsow& operator=(const ListaPsow);
    QList<Pies*> listaPsow;
};

#endif // LISTAPSOW_H
