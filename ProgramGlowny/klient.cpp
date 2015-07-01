#include "klient.h"

Klient::Klient(int id, QString imie, QString nazwisko, QString numerTelefonu, QString ulica, int numerDomu, QString miasto, QString kodPocztowy)
    : id(id),
      imie(imie),
      nazwisko(nazwisko),
      numerTelefonu(numerTelefonu),
      ulica(ulica),
      numerDomu(numerDomu),
      miasto(miasto),
      kodPocztowy(kodPocztowy)
{
}

int Klient::getId() const
{
    return id;
}

QString Klient::getImie() const
{
    return imie;
}

QString Klient::getNazwisko() const
{
    return nazwisko;
}

QString Klient::getUlica() const
{
    return ulica;
}

int Klient::getNumerDomu() const
{
    return numerDomu;
}

QString Klient::getMiasto() const
{
    return miasto;
}

QString Klient::getKodPocztowy() const
{
    return kodPocztowy;
}

void Klient::setId(int noweId)
{
    id = noweId;
}

void Klient::setImie(QString noweImie)
{
    imie = noweImie;
}

void Klient::setNazwisko(QString noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void Klient::setNumerTelefonu(QString nowyNumerTel)
{
    numerTelefonu = nowyNumerTel;
}

void Klient::setUlica(QString nowaUlica)
{
    ulica = nowaUlica;
}

void Klient::setNumerDomu(int nowyNumerDomu)
{
    numerDomu = nowyNumerDomu;
}

void Klient::setMiasto(QString noweMiasto)
{
    miasto = noweMiasto;
}

void Klient::setKodPocztowy(QString nowyKodPocztowy)
{
    kodPocztowy = nowyKodPocztowy;
}

QString Klient::getNumerTelefonu() const
{
    return numerTelefonu;
}

QString Klient::toString() const
{
    return QString("ID: %1  %2 %3   Ulica: %4 %5  Nr tel.: %6").arg(id).arg(imie).arg(nazwisko).arg(ulica).arg(numerDomu).arg(numerTelefonu);
}

