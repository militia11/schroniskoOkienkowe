#ifndef DODAJPSATRANSAKCJA_H
#define DODAJPSATRANSAKCJA_H
#include <QString>
#include "transakcja.h"
#include "pies.h"

class DodajPsaTransakcja : public Transakcja
{
public:
    DodajPsaTransakcja(int id, QString imie, int wiek, RodzajPsa rodzaj, QString rasa);
    virtual void wykonaj();

private:
    int id;
    QString imie;
    int wiek;
    RodzajPsa rodzaj;
    QString rasa;
};

#endif // DODAJPSATRANSAKCJA_H
