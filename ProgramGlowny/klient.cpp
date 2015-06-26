#include "klient.h"

Klient::Klient(int id, QString imie, QString nazwisko, QString ulica, int numerTelefonu)
    : id(id),
      imie(imie),
      nazwisko(nazwisko),
      ulica(ulica),
      numerTelefonu(numerTelefonu)
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

int Klient::getNumerTelefonu() const
{
    return numerTelefonu;
}

QString Klient::toString() const
{
    return QString("ID: %1  %2 %3 Ulica: %4 Nr tel.: %5").arg(id).arg(imie).arg(nazwisko).arg(ulica).arg(numerTelefonu);
}

