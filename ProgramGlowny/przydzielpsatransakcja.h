#ifndef PRZYDZIELPSATRANSAKCJA_H
#define PRZYDZIELPSATRANSAKCJA_H

#include "transakcja.h"
#include "QDate"

class Pies;
class Klient;
class PrzydzielPsaTransakcja : public Transakcja
{

public:
    PrzydzielPsaTransakcja(Pies* pies, Klient* klient, QDate* dataPrzydzielenia);
    virtual void wykonaj();

private:
    PrzydzielPsaTransakcja(const PrzydzielPsaTransakcja&);
    PrzydzielPsaTransakcja& operator=(const PrzydzielPsaTransakcja&);

    Pies* wskPies;
    Klient* wskKlient;
    QDate* dataPrzydzielenia;
};

#endif // PRZYDZIELPSATRANSAKCJA_H
