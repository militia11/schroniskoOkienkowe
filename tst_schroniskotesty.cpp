#include <QString>
#include <QtTest>
#include <assert.h>
#include <QDebug>

#include "ProgramGlowny/pies.h"
#include "ProgramGlowny/listapsow.h"
#include "ProgramGlowny/transakcja.h"
#include "ProgramGlowny/klient.h"
#include "ProgramGlowny/rejestr.h"
#include "ProgramGlowny/przydzielpsatransakcja.h"

extern  ListaPsow gListaPsow;
extern  Rejestr gRejest;

class SchroniskoTesty : public QObject
{
    Q_OBJECT

public:
    SchroniskoTesty();

private Q_SLOTS:

    void testDodaniePsa();
    void testUsunieciePsa();
    void testAtrybutyPsa();
    void testPobranieListyPsow();
    void testPobranieListyPsowDanegoRodzaju();
    void testPrzydzieleniePsa();
    void testDatyPrzydzielenia();
    void testAtrybutyKlienta();
    void testFunkcjiToStringKlienta();
    void testWyswietlenieListyPrzydzielen();
};

SchroniskoTesty::SchroniskoTesty()
{
}

void SchroniskoTesty::testDodaniePsa()
{
    Pies* wskPies = new Pies(184, "Burek", 4, Grozny, "Bernardyn" );

    ListaPsow psyWSchronisku;
    psyWSchronisku.dodajPsa(wskPies);
    assert(psyWSchronisku.getPies(184));
}

void SchroniskoTesty::testUsunieciePsa()
{
    Pies* wskPies = new Pies(12, "Gordon", 6, Grozny, "Husky" );

    ListaPsow psyWSchronisku;
    psyWSchronisku.dodajPsa(wskPies);
    assert( psyWSchronisku.getPies(12) );

    psyWSchronisku.usunPsa(wskPies);
    Pies* wskPiesZListyPsow = psyWSchronisku.getPies(12);
    assert( wskPiesZListyPsow == 0 );
}

void SchroniskoTesty::testAtrybutyPsa()
{
    Pies pies(24345, "Azor", 4, Lagodny, "Pudel" );

    QCOMPARE( 24345, pies.getId() );
    QCOMPARE( QString("Azor"), pies.getImie() );
    QCOMPARE( 4, pies.getWiek() );
    QCOMPARE( Lagodny, pies.getRodzaj() );
    QCOMPARE( QString("Pudel"), pies.getRasa() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodny numer ID", Continue);
    QCOMPARE( 98345, pies.getId() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodne imie", Continue);
    QCOMPARE( QString("Burek"), pies.getImie() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodny wiek", Continue);
    QCOMPARE( 12, pies.getWiek() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodny rodzaj", Continue);
    QCOMPARE( Grozny, pies.getRodzaj() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodna rasa", Continue);
    QCOMPARE( QString("Owczarek Bernaski"), pies.getRasa() );
}

void SchroniskoTesty::testPobranieListyPsow()
{
    Pies* wskPies1 = new Pies(184, "Burek", 4, Grozny, "Bernardyn" );
    Pies* wskPies2 = new Pies(24345, "Azor", 4, Lagodny, "Pudel" );

    ListaPsow psyWSchronisku;
    psyWSchronisku.dodajPsa(wskPies1);
    psyWSchronisku.dodajPsa(wskPies2);


    QStringList listaTestowa1;
    listaTestowa1.append( wskPies1->toString() );
    listaTestowa1.append( wskPies2->toString() );
    QStringList pobranaZListyPsow = psyWSchronisku.getListaPsow();
    QCOMPARE( listaTestowa1, pobranaZListyPsow );

    QStringList listaTestowa2;
    listaTestowa2.append( QString("niezgodne dane") );
    listaTestowa2.append( wskPies2->toString() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : porównanie z niewłaściwym stringiem", Continue);
    QCOMPARE( listaTestowa2, psyWSchronisku.getListaPsow() );
}

void SchroniskoTesty::testPobranieListyPsowDanegoRodzaju()
{
    Pies* wskPies1 = new Pies(1384, "Reksio", 4, Grozny, "Amstaf" );
    Pies* wskPies2 = new Pies(745, "Tofik", 4, Lagodny, "York" );
    Pies* wskPies3 = new Pies(745, "Burek", 4, Lagodny, "Kundel" );

    ListaPsow psyWSchronisku;
    psyWSchronisku.dodajPsa(wskPies1);
    psyWSchronisku.dodajPsa(wskPies2);
    psyWSchronisku.dodajPsa(wskPies3);

    // porównanie dwóch list stringów:

    // właściwa lista z psami łagodnymi
    QStringList listaTestowa1;
    listaTestowa1.append( wskPies2->toString() );
    listaTestowa1.append( wskPies3->toString() );

    QCOMPARE( listaTestowa1, psyWSchronisku.getListaPsow(Lagodny) );

    QStringList listaTestowa2;
    listaTestowa2.append( wskPies2->toString() );
    listaTestowa2.append( wskPies3->toString() );
    listaTestowa2.append( wskPies1->toString() );

    QEXPECT_FAIL("", "porównanie z niewłaściwą listą różnych rodzajów", Continue);
    QCOMPARE( listaTestowa2, psyWSchronisku.getListaPsow(Lagodny) );

    QStringList listaTestowa3;
    listaTestowa3.append( wskPies1->toString() );
    listaTestowa3.append( QString("niezgodne dane"));
    listaTestowa3.append( wskPies3->toString() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : porównanie z niewłaściwym stringiem", Continue);
    QCOMPARE( listaTestowa3, psyWSchronisku.getListaPsow() );
}

void SchroniskoTesty::testPrzydzieleniePsa()
{
    Pies* wskPies = new Pies(1, "Dino", 8, Grozny, "Owczarek" );

    gListaPsow.dodajPsa(wskPies);  // przypadek testowy pokazał, że potrzebujemy globalnej listy psów
    assert(gListaPsow.getPies(1));

    Klient* wskKlient = new Klient(346, "Jan", "Bury", "ul. Osa 12; Bydgoszcz; 85790", 857464757);

    QDate* wskDataPrzydzielenia = new QDate(2014, 07, 23);
    PrzydzielPsaTransakcja przydzielPsa(wskPies, wskKlient , wskDataPrzydzielenia);
    przydzielPsa.wykonaj();

//    Klient* wskKlientPobrany = gRejestracjaWydanychPsow[wskPies];      // pobranie klienta z rejestracji ( mapy psów i klientów )
//    assert(wskKlientPobrany);

//    Pies* wskPiesPobrany = gRejestracjaWydanychPsow.key(wskKlient);
//    assert(wskPiesPobrany);          // test pokazał, że wymagamy klas RejestracjaWydanychPsow oraz Klient

    // sprawdzenie czy pies został jednocześnie usunięty z listy psów dostępnych
    Pies* wskPiesZListyPsow = gListaPsow.getPies(1);
    assert( wskPiesZListyPsow == 0 );

//    QDate* wskPobranaData = wskPies->getDataPrzydzielenia(); // data dodana, wskaźnik pobrany oraz wskaźnik na dodaną datę
//    QCOMPARE(wskDataPrzydzielenia, wskPobranaData);          // pokazują na ten sam adres

//    qDeleteAll(gRejestracjaWydanychPsow);  // wyczyszczenie mapy po teście
//    gRejestracjaWydanychPsow.clear();
}

void SchroniskoTesty::testDatyPrzydzielenia()
{
//    Pies* wskPies = new Pies(3, "Alf", 8, Grozny, "Doberman" );
//    gListaPsow.dodajPsa(wskPies);  // przypadek testowy pokazał, że potrzebujemy globalnej listy psów
//    Klient* wskKlient = new Klient(346, "Józef", "Harny", "ul. Basztowa 43/20; Bydgoszcz; 85790", 647578574);
//    QDate* wskDataPrzydzielenia = new QDate(2014, 07, 23);
//    PrzydzielPsaTransakcja przydzielPsa(wskPies, wskKlient , wskDataPrzydzielenia);
//    przydzielPsa.wykonaj();

//    QDate* wskPobranaData = wskPies->getDataPrzydzielenia(); // data dodana, wskaźnik pobrany oraz wskaźnik na dodaną datę
//    QCOMPARE(wskDataPrzydzielenia, wskPobranaData);          // pokazują na ten sam adres

//    qDeleteAll(gRejestracjaWydanychPsow);  // wyczyszczenie mapy po teście
//    gRejestracjaWydanychPsow.clear();
}

void SchroniskoTesty::testAtrybutyKlienta()
{
    Klient klient(123, "Adam", "Kowalski", "ul. Kościelna 12; Bydgoszcz; 85790", 600821340);

    QCOMPARE( 123, klient.getId() );
    QCOMPARE( QString("Adam"), klient.getImie() );
    QCOMPARE( QString("Kowalski"), klient.getNazwisko() );
    QCOMPARE( QString("ul. Kościelna 12; Bydgoszcz; 85790"), klient.getUlica() );
    QCOMPARE( 600821340, klient.getNumerTelefonu() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodny numer Id", Continue);
    QCOMPARE( 345, klient.getId());

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodne imie", Continue);
    QCOMPARE( QString("Kuba"), klient.getImie());

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodne nazwisko", Continue);
    QCOMPARE( QString("Nowicki"), klient.getNazwisko() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodna ulica", Continue);
    QCOMPARE( QString("ul. Sławków 3; Lublin; 44230"), klient.getUlica() );

    QEXPECT_FAIL("", "test na niewłaściwe dane : niezgodny numer", Continue);
    QCOMPARE( 515987464, klient.getNumerTelefonu() );
}

void SchroniskoTesty::testFunkcjiToStringKlienta()
{
    Klient klient(123, "Józef", "Jung", "ul. Bema 12; Nysa; 42390", 345828740);
    qDebug() << klient.toString();
}

void SchroniskoTesty::testWyswietlenieListyPrzydzielen()
{
//    Pies* wskPies1 = new Pies(124, "Bruno", 4, Grozny, "Owczarek" );
//    Klient* wskKlient1 = new Klient(46, "Łukasz", "Zima", "ul. Osa 1/34; Płock; 32790", 464857757);
//    Pies* wskPies2 = new Pies(356, "Simba", 8, Grozny, "Owczarek" );
//    Klient* wskKlient2 = new Klient(98, "Tomek", "Gawor", "ul. Borów 62; Bytom; 35670", 774855647);

//    gRejestracjaWydanychPsow.dodaj(wskPies1,wskKlient1);  // przypadek testowy pokazał, że potrzebujemy globalnej listy psów
//    gRejestracjaWydanychPsow.dodaj(wskPies2,wskKlient2);
//    qDebug() << gRejestracjaWydanychPsow.listaPrzydzielenPsow();
}

QTEST_APPLESS_MAIN(SchroniskoTesty)

#include "tst_schroniskotesty.moc"
