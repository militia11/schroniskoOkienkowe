#ifndef PRZYDZIELPSATRANSAKCJA_H
#define PRZYDZIELPSATRANSAKCJA_H

#include "QDate"
#include "transakcja.h"
#include <QTableView>

//class ModelKlienci;
//class ModelPsy;
class ModelRejestr;

//class Pies;
class Klient;
class PrzydzielPsaTransakcja : public Transakcja
{

public:
    PrzydzielPsaTransakcja(Klient* klient, QTableView *widok);//Pies* pies, Klient* klient, QDate* dataPrzydzielenia
    virtual void wykonaj();

private:
    // moze usunac
    PrzydzielPsaTransakcja(const PrzydzielPsaTransakcja&);
    PrzydzielPsaTransakcja& operator=(const PrzydzielPsaTransakcja&);

    QTableView* widok;
//    Pies* wskPies;
    Klient* klient;
//    QDate* dataPrzydzielenia;
};

#endif // PRZYDZIELPSATRANSAKCJA_H
