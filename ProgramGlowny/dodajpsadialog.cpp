#include "dodajpsadialog.h"
#include "ui_dodajpsadialog.h"

DodajPsaDialog::DodajPsaDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DodajPsaDialog)
{
    ui->setupUi(this);
}

DodajPsaDialog::~DodajPsaDialog()
{
    delete ui;
}
