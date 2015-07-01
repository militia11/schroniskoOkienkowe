#include "przydzielpsatransakcja.h"
//#include "wydaniepsa.h"
#include "modelpsy.h"
#include "modelrejestr.h"
#include "klient.h"
#include "usunpsatransakcja.h"
#include <QModelIndex>

extern ModelPsy modelPsy;
extern ModelRejestr modelRejestr;

PrzydzielPsaTransakcja::PrzydzielPsaTransakcja(Klient *klient, QTableView* widok)
    : klient(klient),
      widok(widok)
{
}

void PrzydzielPsaTransakcja::wykonaj()
{
    QModelIndex index = widok->selectionModel()->currentIndex();
    int rzadp = index.row();
    Pies* pies = modelPsy.getPies(rzadp);

    QDate dataPrzydzielenia = QDate::currentDate();
    //QDate dataPrzydzielenia(2014,11,02);  //= dataPrzydzielenia.currentDate();
    WydaniePsa* wydaniePsa = new WydaniePsa(pies, klient, dataPrzydzielenia);

    //dodaj
    int rzadw = modelRejestr.rowCount();
    modelRejestr.insertRows( rzadw, 1, wydaniePsa );

    // usunięcia psa z listy psów
    UsunPsaTransakcja transakcja(widok);
    transakcja.wykonaj();

//    int rzad = modelPsy.rowCount();
//    modelPsy.insertRows( rzad, 1, pies );

//    gListaPsow.usunPsa(wskPies);
//    gRejestr.dodaj(wydaniePsa);
}

PrzydzielPsaTransakcja::PrzydzielPsaTransakcja(const PrzydzielPsaTransakcja &) {}

PrzydzielPsaTransakcja &PrzydzielPsaTransakcja::operator=(const PrzydzielPsaTransakcja &)
{
    return *this;
}

