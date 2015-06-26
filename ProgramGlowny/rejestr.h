#ifndef REJESTR_H
#define REJESTR_H

#include "wydaniepsa.h"

#include <QList>

class WydaniePsa;
class Pies;
class Klient;
class Rejestr
{
public:
    Rejestr();
    void dodaj(WydaniePsa* wydaniePsa);
    Pies* getPies(int id);
    Klient* getKlient(int id);
    void wyczysc();

private:
    QList<WydaniePsa*> listaWydan;
};

#endif // REJESTR_H
