#include "przydzielpsatransakcja.h"
#include "wydaniepsa.h"
#include "rejestr.h"
#include "modelklienci.h"
#include "modelpsy.h"
#include "modelrejestr.h"

extern Rejestr gRejestr;

PrzydzielPsaTransakcja::PrzydzielPsaTransakcja(Pies* pies, Klient* klient, QDate *dataPrzydzieleniaz, ModelPsy* psy, ModelKlienci* klienci,  ModelRejestr * wydania)
    : wskPies(pies),
      wskKlient(klient),
      dataPrzydzielenia(dataPrzydzielenia)
{
}

void PrzydzielPsaTransakcja::wykonaj()
{
//    gListaPsow.usunPsa(wskPies);
//    WydaniePsa* wydaniePsa = new WydaniePsa(wskPies, wskKlient, dataPrzydzielenia);
//    gRejestr.dodaj(wydaniePsa);
}

PrzydzielPsaTransakcja::PrzydzielPsaTransakcja(const PrzydzielPsaTransakcja &) {}

PrzydzielPsaTransakcja &PrzydzielPsaTransakcja::operator=(const PrzydzielPsaTransakcja &)
{
    return *this;
}

