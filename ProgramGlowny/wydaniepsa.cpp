#include "wydaniepsa.h"

WydaniePsa::WydaniePsa(Pies* pies, Klient* klient, const QDate& dataWydania)
    : pies(pies),
      klient(klient),
      dataWydania(dataWydania)
{
}

Pies *WydaniePsa::getPies() const
{
    return pies;
}

Klient *WydaniePsa::getKlient() const
{
    return klient;
}

QDate WydaniePsa::getData() const
{
    return dataWydania;
}

