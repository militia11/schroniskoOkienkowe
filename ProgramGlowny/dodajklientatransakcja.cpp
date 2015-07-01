#include "dodajklientatransakcja.h"
#include "klient.h"
#include "modelklienci.h"
#include <QMessageBox>

extern ModelKlienci modelKlienci;

DodajKlientaTransakcja::DodajKlientaTransakcja(int id, QString imie, QString nazwisko, QString numerTelefonu, QString ulica, int numerDomu, QString miasto, QString kodPocztowy)
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

void DodajKlientaTransakcja::wykonaj()
{
    if( modelKlienci.sprawdzDostepnosc(id) ) {
        Klient* klient = new Klient(id, imie, nazwisko, numerTelefonu, ulica, numerDomu, miasto, kodPocztowy);
        int rzad = modelKlienci.rowCount();
        modelKlienci.insertRows( rzad, 1, klient );
    }
    else {
        QMessageBox::warning( 0, "ERROR", "Nie można dodać klienta"
                            "<br>Klient o podanym ID istnieje już w bazie", QMessageBox::Ok);
    }


}

