#include "wydaniepsa.h"

WydaniePsa::WydaniePsa(Pies* pies, Klient* klient, QDate* dataWydania)
    : pies(pies),
      klient(klient),
      dataWydania(dataWydania)
{
}

Pies *WydaniePsa::getPies()
{
    return pies;
}

Klient *WydaniePsa::getKlient()
{
    return klient;
}

