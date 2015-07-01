#include <QMessageBox>
#include <QStringList>
#include "wydajpsadialog.h"
#include "ui_wydajpsadialog.h"
#include "modelklienci.h"
#include "dodajklientadialog.h"
#include "dodajklientatransakcja.h"
#include "pies.h"
#include "modelpsy.h"

extern ModelKlienci modelKlienci;
extern ModelPsy modelPsy;

WydajPsaDialog::WydajPsaDialog(QTableView* widok, QWidget *parent)
    : widok(widok),
    QDialog(parent),
    ui(new Ui::WydajPsaDialog)
{
    ui->setupUi(this);
    QModelIndex index = widok->selectionModel()->currentIndex();
    int rzad = index.row();
    Pies* pies = modelPsy.getPies(rzad);
    int id = pies->getId();
    QString imie = pies->getImie();
    ui->labelPies->setText( "<center>Wydanie psa<b> " + imie + "</b> o numerze<b> " + QString::number(id) );
    aktualizujListe();
}

WydajPsaDialog::~WydajPsaDialog()
{
    delete ui;
}

int WydajPsaDialog::getRzad() const
{
    return rzad;
}

void WydajPsaDialog::aktualizujListe()
{
    ui->listKlienci->clear();
    QStringList lista = modelKlienci.getListaKlientow();
    for(QStringList::iterator it = lista.begin();
        it != lista.end(); ++it) {
        ui->listKlienci->addItem(*it);
    }
}

void WydajPsaDialog::on_buttonBox_accepted()
{
    if( ui->listKlienci->currentIndex().isValid() ){  // jeśli pozycja jest zaznaczona
        rzad = ui->listKlienci->currentIndex().row();
        accept();
    }
    else {
        if(ui->listKlienci->count() == 0) {
            QMessageBox::warning(this,"ERROR LISTA KLIENTÓW JEST PUSTA","Nie można zaakceptować bez wybrania klienta. "
                                 "<br> Dodaj klienta i wskaż go jako właściciela.", QMessageBox::Yes);
        }
        else {
            QMessageBox::warning(this,"ERROR NIE WYBRANO KLIENTA ","Nie można zaakceptować bez wybrania klienta. "
                                 "<br> Proszę wskazać klienta.", QMessageBox::Yes);
        }
    }
}

void WydajPsaDialog::on_pushButton_clicked()
{
    DodajKlientaDialog dialog(this); //
    if( dialog.exec() == QDialog::Accepted ) {
        DodajKlientaTransakcja transakcja( dialog.getId(), dialog.getImie(), dialog.getNazwisko(),
                                           dialog.getNumerTelefonu(), dialog.getUlica(), dialog.getNumerDomu(),
                                           dialog.getMiasto(), dialog.getKodPocztowy());
        transakcja.wykonaj();
        aktualizujListe();
    }
}

void WydajPsaDialog::on_buttonBox_rejected()
{
    reject();
}
