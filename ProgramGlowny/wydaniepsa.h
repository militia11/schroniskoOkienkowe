#ifndef WYDANIEPSA_H
#define WYDANIEPSA_H

class QDate;
class Pies;
class Klient;

class WydaniePsa
{
public:
    WydaniePsa();

private:
    QDate* dataWydania;
    Pies* pies;
    Klient* klient;

};

#endif // WYDANIEPSA_H
