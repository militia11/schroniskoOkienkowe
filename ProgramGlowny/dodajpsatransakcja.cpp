#include "dodajpsatransakcja.h"
#include "modelpsy.h"
#include <QDebug>
#include <QMessageBox>

extern ModelPsy modelPsy;

DodajPsaTransakcja::DodajPsaTransakcja(int id, QString imie, int wiek, RodzajPsa rodzaj, QString rasa)
    : id(id),
      imie(imie),
      wiek(wiek),
      rodzaj(rodzaj),
      rasa(rasa)
{
}

void DodajPsaTransakcja::wykonaj()
{
    if( modelPsy.sprawdzDostepnosc(id) ) {
        Pies* pies = new Pies(id, imie, wiek, rodzaj, rasa);
        int rzad = modelPsy.rowCount();
        modelPsy.insertRows( rzad, 1, pies );
    }
    else {
        QMessageBox::warning( 0, "ERROR", "Nie można dodać psa"
                            "<br>Pies o podanym ID istnieje już w bazie", QMessageBox::Ok);

    }
}
