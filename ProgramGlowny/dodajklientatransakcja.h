#ifndef DODAJKLIENTATRANSAKCJA_H
#define DODAJKLIENTATRANSAKCJA_H

#include <QString>
#include "transakcja.h"

class DodajKlientaTransakcja : public Transakcja
{
public:
    DodajKlientaTransakcja(int id, QString imie, QString nazwisko, QString numerTelefonu, QString ulica, int numerDomu, QString miasto, QString kodPocztowy);
    virtual void wykonaj();

private:
    int id;
    QString imie;
    QString nazwisko;
    QString numerTelefonu;
    QString ulica;
    int numerDomu;
    QString miasto;
    QString kodPocztowy;
};

#endif // DODAJKLIENTATRANSAKCJA_H
