#include <QString>
#include <QtTest>
#include <assert.h>
#include <QDebug>

#include "ProgramGlowny/pies.h"
#include "ProgramGlowny/transakcja.h"
#include "ProgramGlowny/klient.h"
#include "ProgramGlowny/przydzielpsatransakcja.h"
#include "ProgramGlowny/modelrejestr.h"
#include "ProgramGlowny/modelpsy.h"
#include "ProgramGlowny/modelklienci.h"


class SchroniskoTesty : public QObject
{
    Q_OBJECT

public:
    SchroniskoTesty();

private Q_SLOTS:
    void testPrzydzieleniePsa();
};

SchroniskoTesty::SchroniskoTesty()
{
}
    // porównanie dwóch list stringów:

void SchroniskoTesty::testPrzydzieleniePsa()
{
//    Pies* pies = new Pies(1, "Dino", 8, Grozny, "Owczarek" );
//    Klient* klient = new Klient(2, "Jan", "Bury", "ul. Osa 12; Bydgoszcz; 85790", 857464757);
//    QDate* dataPrzydzielenia = new QDate(2014, 07, 23);
//    WydaniePsa* wydaniePsa = new WydaniePsa(pies, klient, dataPrzydzielenia);

//    ModelRejestr* modelRejestr = new ModelRejestr(this);

//    int row = modelRejestr->rowCount();
//    modelRejestr->insertRows( row, 1, wydaniePsa );

//    gListaKlientow.dodajKlienta(klient);
//    assert(gListaKlientow.getKlient(2));

//    QDate* dataPrzydzielenia = new QDate(2014, 07, 23);
//    PrzydzielPsaTransakcja przydzielPsa(pies, klient , dataPrzydzielenia);
//    przydzielPsa.wykonaj();

//    Pies* piesPobrany = gRejestr.getPies(1);
//    assert(piesPobrany);

//    Klient* klientPobrany = gRejestr.getKlient(2);
//    assert(klientPobrany);

//    Pies* piesZListyPsow = gListaPsow.getPies(1);
//    assert( piesZListyPsow == 0 );

//    Klient* klientZListyKlientow = gListaKlientow.getKlient(2);
//    assert(klientZListyKlientow);

//    QDate* wskPobranaData = wskPies->getDataPrzydzielenia(); // data dodana, wskaźnik pobrany oraz wskaźnik na dodaną datę
//    QCOMPARE(wskDataPrzydzielenia, wskPobranaData);          // pokazują na ten sam adres

//    gListaKlientow.wyczysc();
//    gListaPsow.wyczysc();
    //gRejestr.wyczysc();
}


QTEST_APPLESS_MAIN(SchroniskoTesty)

#include "tst_schroniskotesty.moc"
