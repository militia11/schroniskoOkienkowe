#include "przydzielpsatransakcja.h"
#include "wydaniepsa.h"
#include "rejestr.h"

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
}

PrzydzielPsaTransakcja::PrzydzielPsaTransakcja(const PrzydzielPsaTransakcja &) {}

PrzydzielPsaTransakcja &PrzydzielPsaTransakcja::operator=(const PrzydzielPsaTransakcja &)
{
    return *this;
}

