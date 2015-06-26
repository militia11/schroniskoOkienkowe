#ifndef KLIENT_H
#define KLIENT_H

#include <QString>

class Klient
{
public:
    Klient(int id, QString imie, QString nazwisko, QString ulica, int numerTelefonu);
    int getId() const;
    QString getImie() const;
    QString getNazwisko() const;
    QString getUlica() const;
    int getNumerTelefonu() const;
    QString toString() const;

private:
    int id;
    QString imie;
    QString nazwisko;
    QString ulica;
    int numerTelefonu;
};

#endif // KLIENT_H
