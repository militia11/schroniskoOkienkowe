#include "przydzielpsatransakcja.h"
#include "listapsow.h"
//#include "rejestracjawydanychpsow.h"

extern ListaPsow gListaPsow;
//extern RejestracjaWydanychPsow gRejestracjaWydanychPsow;

PrzydzielPsaTransakcja::PrzydzielPsaTransakcja(Pies* pies, Klient* klient, QDate *dataPrzydzielenia)
    : wskPies(pies),
      wskKlient(klient),
      dataPrzydzielenia(dataPrzydzielenia)
{
}

void PrzydzielPsaTransakcja::wykonaj()
{
    gListaPsow.usunPsa(wskPies);
//    wskPies->setDatePrzydzielenia(dataPrzydzielenia); // transakcja ustawia psu datę kiedy został przydzielony
//    gRejestracjaWydanychPsow.dodaj(wskPies, wskKlient);
}

PrzydzielPsaTransakcja::PrzydzielPsaTransakcja(const PrzydzielPsaTransakcja &) {}

PrzydzielPsaTransakcja &PrzydzielPsaTransakcja::operator=(const PrzydzielPsaTransakcja &)
{
    return *this;
}

