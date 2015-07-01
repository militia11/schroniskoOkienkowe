#include "pies.h"
#include "QDate"
#include <QMessageBox>

Pies::Pies(int id, QString imie, int wiek, RodzajPsa rodzaj, QString rasa)
    : id(id),
      imie(imie),
      wiek(wiek),
      rodzaj(rodzaj),
      rasa(rasa)
{
}

int Pies::getId() const
{
    return id;
}

QString Pies::getImie() const
{
    return imie;
}

int Pies::getWiek() const
{
    return wiek;
}

RodzajPsa Pies::getRodzaj() const
{
    return rodzaj;
}

QString Pies::getRasa() const
{
    return rasa;
}

void Pies::setId(int noweId)
{
    id = noweId;
}

void Pies::setImie(QString noweImie)
{
    imie = noweImie;
}

void Pies::setWiek(int nowyWiek)
{
    wiek = nowyWiek;
}

void Pies::setRodzaj(QString nowyRodzaj)
{

//    if( nowyRodzaj == QString("Łagodny") )
//        rodzaj = Lagodny;
//    else if( nowyRodzaj == QString("Agresywny") )
//        rodzaj = Grozny;
//    else if( nowyRodzaj == QString("Do domu") )
//        rodzaj = Grozny;
//    else if( nowyRodzaj == QString("Na podwórko") )
//        rodzaj = Nieokreslony;
//    else if( nowyRodzaj == QString("Nieokreślony") )
//        rodzaj = Nieokreslony;
//    else
//        QMessageBox::warning( 0, "UWAGA","Niepoprawny rodzaj psa. <br>Proszę ustawić poprawny <br><b>Łagodny, Agresywny, Do domu, Na podwórko, Nieokreślony</b>lub <b>Nieokreślony</b><br> ",QMessageBox::Ok);
}

void Pies::setRasa(QString nowaRasa)
{
    rasa = nowaRasa;
}

QString Pies::toString() const
{
    return QString("ID: %1 - %2 Wiek: %3 Rasa: %5").arg(id).arg(imie).arg(wiek).arg(rasa);
}

Pies::Pies(const Pies &) {}

Pies &Pies::operator=(const Pies &)
{
    return *this;
}

