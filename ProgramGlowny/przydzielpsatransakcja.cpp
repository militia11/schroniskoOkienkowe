#include "przydzielpsatransakcja.h"
#include "listapsow.h"
#include "wydaniepsa.h"
#include "rejestr.h"

extern ListaPsow gListaPsow;
extern Rejestr gRejestr;

PrzydzielPsaTransakcja::PrzydzielPsaTransakcja(Pies* pies, Klient* klient, QDate *dataPrzydzielenia)
    : wskPies(pies),
      wskKlient(klient),
      dataPrzydzielenia(dataPrzydzielenia)
{
}

void PrzydzielPsaTransakcja::wykonaj()
{
    gListaPsow.usunPsa(wskPies);
    WydaniePsa* wydaniePsa = new WydaniePsa(wskPies, wskKlient, dataPrzydzielenia);
    gRejestr.dodaj(wydaniePsa);
//    wskPies->setDatePrzydzielenia(dataPrzydzielenia); // transakcja ustawia psu datę kiedy został przydzielony
//    gRejestracjaWydanychPsow.dodaj(wskPies, wskKlient);
}

PrzydzielPsaTransakcja::PrzydzielPsaTransakcja(const PrzydzielPsaTransakcja &) {}

PrzydzielPsaTransakcja &PrzydzielPsaTransakcja::operator=(const PrzydzielPsaTransakcja &)
{
    return *this;
}

