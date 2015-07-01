#include <QMessageBox>
#include<QRegExpValidator>
#include "dodajklientadialog.h"
#include "ui_dodajklientadialog.h"

QRegExp DodajKlientaDialog::formatNrTelefonu("([1-9]\\d\\d)-(\\d{3})-(\\d{3})");

DodajKlientaDialog::DodajKlientaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajKlientaDialog)
{
    ui->setupUi(this);
    QRegExpValidator* numerTelValid(new QRegExpValidator(formatNrTelefonu));
    ui->lineEditNumerTelefonu->setValidator(numerTelValid);
}

//if( !ui->lineEditPhoneNumber->text().isEmpty() ) { //this field is required
//        if(s_phoneFormat.exactMatch(ui->lineEditPhoneNumber->text())) {
//                     // required nine signs phone number
//                    m_Person->setName(ui->lineEditPersonName->text());
void DodajKlientaDialog::on_buttonBox_accepted()
{
    if( ui->spinBoxId->value() != 0 ) {      // jeśli pole Id jest wypełnione
        if( !ui->lineEditImie->text().isEmpty() ){ // jeśli pole Imie jest również wypełnione
            if( !ui->lineEditNazwisko->text().isEmpty() ){
                if( ui->lineEditNumerTelefonu->text().isEmpty()
                        || formatNrTelefonu.exactMatch( ui->lineEditNumerTelefonu->text() ) ) {
                    id = ui->spinBoxId->value();   // ustawiamy atrybuty
                    numerTelefonu = ui->lineEditNumerTelefonu->text();
                    imie = ui->lineEditImie->text();
                    nazwisko = ui->lineEditNazwisko->text();
                    ulica = ui->lineEditUlica->text();
                    numerDomu = ui->spinBoxNrDomu->value();
                    miasto = ui->lineEditMiasto->text();
                    kodPocztowy = ui->lineEditKodPocztowy->text().toInt();
                    accept();
                }
                else {
                    QMessageBox::warning( this, "ERROR BŁĘDNY NUMER TELEFONU", " Proszę podaj prawidłowy nr telefonu w standardzie "
                                         "<br><b> XXX-XXX-XXX", QMessageBox::Ok);
                    ui->lineEditNazwisko->setFocus();
                }

                }

                else {                             // jeśli pole nazwisko nie jest również wypełnione
                    QMessageBox::warning( this, "ERROR BRAK NAZWISKA", " Nie można zaakceptować bez podania nazwiska klienta. "
                                         "<br>Proszę podaj nazwikso klienta", QMessageBox::Ok);
                    ui->lineEditNazwisko->setFocus();
                }
        }
        else {                       // jeśli pole Imie nie jest również wypełnione
            QMessageBox::warning( this, "ERROR BRAK IMIENIA", " Nie można zaakceptować bez podania imienia klienta. "
                                 "<br>Proszę podaj imie klienta", QMessageBox::Ok);
            ui->lineEditImie->setFocus();
        }
    }
    else {                           // jeśli pole Id nie jest wypełnione
        QMessageBox::warning( this, "ERROR BRAK ID", "Nie można zaakceptować bez numeru ID. "
                            "<br>Proszę podaj numer ID klienta", QMessageBox::Ok);
        ui->spinBoxId->setFocus();
    }
}

DodajKlientaDialog::~DodajKlientaDialog()
{
    delete ui;
}

void DodajKlientaDialog::on_buttonBox_rejected()
{
    reject();
}

int DodajKlientaDialog::getId() const
{
    return id;
}

QString DodajKlientaDialog::getImie() const
{
    return imie;
}

QString DodajKlientaDialog::getNazwisko() const
{
    return nazwisko;
}

QString DodajKlientaDialog::getUlica() const
{
    return ulica;
}

int DodajKlientaDialog::getNumerDomu() const
{
    return numerDomu;
}

QString DodajKlientaDialog::getMiasto() const
{
    return miasto;
}

QString DodajKlientaDialog::getKodPocztowy() const
{
    return kodPocztowy;
}

void DodajKlientaDialog::setId(int noweId)
{
    id = noweId;
}

void DodajKlientaDialog::setImie(QString noweImie)
{
    imie = noweImie;
}

void DodajKlientaDialog::setNazwisko(QString noweNazwisko)
{
    nazwisko = noweNazwisko;
}

void DodajKlientaDialog::setNumerTelefonu(QString nowyNumerTel)
{
    numerTelefonu = nowyNumerTel;
}

void DodajKlientaDialog::setUlica(QString nowaUlica)
{
    ulica = nowaUlica;
}

void DodajKlientaDialog::setNumerDomu(int nowyNumerDomu)
{
    numerDomu = nowyNumerDomu;
}

void DodajKlientaDialog::setMiasto(QString noweMiasto)
{
    miasto = noweMiasto;
}

void DodajKlientaDialog::setKodPocztowy(QString nowyKodPocztowy)
{
    kodPocztowy = nowyKodPocztowy;
}

QString DodajKlientaDialog::getNumerTelefonu() const
{
    return numerTelefonu;
}
