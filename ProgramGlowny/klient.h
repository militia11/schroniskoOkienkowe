#ifndef KLIENT_H
#define KLIENT_H

#include <QString>

class Klient
{
public:
    Klient(int id, QString imie, QString nazwisko, QString numerTelefonu, QString ulica, int numerDomu, QString miasto, QString kodPocztowy);
    int getId() const;
    QString getImie() const;
    QString getNazwisko() const;
    QString getNumerTelefonu() const;
    QString getUlica() const;
    int getNumerDomu() const;
    QString getMiasto() const;
    QString getKodPocztowy() const;
    void setId(int noweId);
    void setImie(QString noweImie);
    void setNazwisko(QString noweNazwisko);
    void setNumerTelefonu(QString nowyNumerTel);
    void setUlica(QString nowaUlica);
    void setNumerDomu(int nowyNumerDomu);
    void setMiasto(QString noweMiasto);
    void setKodPocztowy(QString nowyKodPocztowy);

    QString toString() const;

private:
    int id;
    QString imie;
    QString nazwisko;
    QString numerTelefonu;
    QString ulica;
    int numerDomu;
    QString miasto;
    QString kodPocztowy;
};

#endif // KLIENT_H
