#ifndef WYDANIEPSA_H
#define WYDANIEPSA_H

class QDate;
class Pies;
class Klient;

class WydaniePsa
{
public:
    WydaniePsa(Pies* pies, Klient* klient, QDate* dataWydania);

    Pies* getPies();
    Klient* getKlient();
private:
    Pies* pies;
    Klient* klient;
    QDate* dataWydania;
};

#endif // WYDANIEPSA_H
