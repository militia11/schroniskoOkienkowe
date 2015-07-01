#ifndef WYDANIEPSA_H
#define WYDANIEPSA_H

#include <QDate>

class Pies;
class Klient;

class WydaniePsa
{
public:
    WydaniePsa(Pies* pies, Klient* klient, const QDate &dataWydania);
    Pies* getPies() const;
    Klient* getKlient() const;
    QDate getData() const;

private:
    Pies* pies;
    Klient* klient;
    QDate dataWydania;
};

#endif // WYDANIEPSA_H
