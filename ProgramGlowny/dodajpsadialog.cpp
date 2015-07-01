#include "dodajpsadialog.h"
#include "ui_dodajpsadialog.h"
#include <QMessageBox>

DodajPsaDialog::DodajPsaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajPsaDialog)
{
    ui->setupUi(this);
    QStringList kategorie;
    kategorie << "Nieokreślony" << "Łagodny" << "Agresywny" << "Do domu" << "Na podwórko";
    ui->comboBoxRodzaj->addItems(kategorie);
}

DodajPsaDialog::~DodajPsaDialog()
{
    delete ui;
}

void DodajPsaDialog::on_buttonBox_accepted()
{
    if( ui->spinBoxId->value() != 0) {      // jeśli pole Id jest wypełnione
        if( !ui->lineEditImie->text().isEmpty() ){ // jeśli pole Imie jest również wypełnione
            ustawParametry();
            accept();
        }
        else {                       // jeśli pole Imie nie jest również wypełnione
            QMessageBox::warning( this, "ERROR BRAK IMIENIA", " Nie można zaakceptować bez imienia psa. "
                                 "<br>Proszę podaj imie psa", QMessageBox::Ok);
            ui->lineEditImie->setFocus();
        }
    }
    else {                           // jeśli pole Id nie jest wypełnione
        QMessageBox::warning( this, "ERROR BRAK ID", "Nie można zaakceptować bez numeru ID. "
                            "<br>Proszę podaj numer ID psa", QMessageBox::Ok);
        ui->spinBoxId->setFocus();
    }
}


void DodajPsaDialog::setRodzaj(QString nowyRodzaj)
{
    if( nowyRodzaj == QString("Łagodny") )
        rodzaj = Lagodny;
    else if( nowyRodzaj == QString("Groźny") )
        rodzaj = Agresywny;
    else
        QMessageBox::warning( 0, "UWAGA","Niepoprawny rodzaj psa. <br>Proszę ustawić poprawny <br><b>Łagodny </b>lub <b>Groźny </b><br> ",QMessageBox::Ok);
}

void DodajPsaDialog::sprawdzIUstawRodzaj()
{
    if( ui->comboBoxRodzaj->currentText() == "Nieokreślony") {
        rodzaj = Nieokreslony;
    }
    else if( ui->comboBoxRodzaj->currentText() == "Łagodny"){
        rodzaj = Lagodny;
    }
    else if( ui->comboBoxRodzaj->currentText() == "Agresywny"){
        rodzaj = Agresywny;
    }
    else if( ui->comboBoxRodzaj->currentText() == "Do domu"){
        rodzaj = DoDomu;
    }
    else if( ui->comboBoxRodzaj->currentText() == "Na podwórko"){
        rodzaj = NaPodworko;
    }
}
void DodajPsaDialog::ustawParametry()
{
    // ustawiamy atrybuty
    sprawdzIUstawRodzaj();
    id = ui->spinBoxId->value();
    imie = ui->lineEditImie->text();
    wiek = ui->spinBoxWiek->value();
    rasa = ui->lineEditRasa->text();
}

void DodajPsaDialog::on_buttonBox_rejected()
{
    reject();
}

int DodajPsaDialog::getId() const
{
    return id;
}

void DodajPsaDialog::setRasa(QString nowaRasa)
{
    rasa = nowaRasa;
}

QString DodajPsaDialog::getImie() const
{
    return imie;
}

int DodajPsaDialog::getWiek() const
{
    return wiek;
}

RodzajPsa DodajPsaDialog::getRodzaj() const
{
    return rodzaj;
}

QString DodajPsaDialog::getRasa() const
{
    return rasa;
}

void DodajPsaDialog::setId(int noweId)
{
    id = noweId;
}

void DodajPsaDialog::setImie(QString noweImie)
{
    imie = noweImie;
}

void DodajPsaDialog::setWiek(int nowyWiek)
{
    wiek = nowyWiek;
}
