#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "pies.h"
#include "klient.h"
#include "wydaniepsa.h"
#include "dodajpsatransakcja.h"
#include "usunpsatransakcja.h"
#include "modelrejestr.h"
#include "modelklienci.h"
#include "modelpsy.h"
#include "przydzielpsatransakcja.h"
#include "wydajpsadialog.h"

#include <QDate>
#include <QMessageBox>

extern ModelPsy modelPsy;
extern ModelKlienci modelKlienci;
extern ModelRejestr modelRejestr;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionWydajpsa->setEnabled(false);
    ui->actionListaPsy->setChecked(true);

    QObject::connect( ui->actionDodajPsa, SIGNAL( triggered() ), this, SLOT( dodajPsa() ) );
    QObject::connect( ui->actionUsunPsa, SIGNAL( triggered() ), this, SLOT( usunPsa() ) );

    QObject::connect( ui->actionRejestrWydan, SIGNAL( triggered() ), this, SLOT( pokazRejestr() ) );
    QObject::connect( ui->actionListaPsy, SIGNAL( triggered() ), this, SLOT( pokazPsy() ) );
    QObject::connect( ui->actionListaKlientow, SIGNAL( triggered() ), this, SLOT( pokazKlientow() ) );
    QObject::connect( ui->actionWydajpsa, SIGNAL( triggered() ), this, SLOT( wydajPsa() ) );

    widok = new QTableView(this);
    widok->setModel(&modelPsy);
    delegat = new DelegatDanych(this);
    widok->setItemDelegate(delegat);
    QHeaderView* hv = widok->horizontalHeader();
    hv->setSectionResizeMode(QHeaderView::ResizeToContents);

    QObject::connect(qApp, SIGNAL( focusChanged( QWidget*, QWidget* ) ), this, SLOT( aktualizujWidok() ) );
    setCentralWidget(widok);
}
void MainWindow::closeEvent(QCloseEvent *event) {
//        if( ( QMessageBox::warning( this, "UWAGA", "<center> Wszystkie niezapisane dane zostaną utracone.<BR> Zamknąć aplikację?",
//                                   QMessageBox::Yes | QMessageBox::No ) ) == QMessageBox::No) {
//            event->ignore();
//            return;
//        }
//        event->accept();
}

void MainWindow::wydajPsaDodajacKlientaIPsa()
{

}

void MainWindow::wydajPsaDodajacKlienta()
{
    WydajPsaDialog dialog(widok, this);
    Klient* klient;
    if( dialog.exec() == QDialog::Accepted ) {
        int rzadKlienci = dialog.getRzad(),
            rzadPsy = widok->selectionModel()->currentIndex().row(),
                rzadk = 0;
        klient = modelKlienci.getKlient(rzadKlienci);
        PrzydzielPsaTransakcja transakcja(klient, widok);
        transakcja.wykonaj();
    }
}

void MainWindow::pokazRejestr()
{
    widok->setModel(&modelRejestr);
    ui->actionUsunPsa->setEnabled(false);
    ui->actionDodajPsa->setEnabled(false);
    ui->actionWydajpsa->setEnabled(true);
    ui->actionListaPsy->setChecked(false);
    ui->actionListaKlientow->setChecked(false);
}

void MainWindow::pokazPsy()
{
    widok->setModel(&modelPsy);
    ui->actionUsunPsa->setEnabled(true);
    if(modelPsy.rowCount() != 0){
        ui->actionWydajpsa->setEnabled(true);
    }
    ui->actionDodajPsa->setEnabled(true);
    ui->actionListaKlientow->setChecked(false);
    ui->actionRejestrWydan->setChecked(false);
}

void MainWindow::pokazKlientow()
{
    widok->setModel(&modelKlienci);
    ui->actionUsunPsa->setEnabled(false);
    ui->actionDodajPsa->setEnabled(false);
    ui->actionWydajpsa->setEnabled(false);
    ui->actionListaPsy->setChecked(false);
    ui->actionRejestrWydan->setChecked(false);
}

void MainWindow::aktualizujWidok()
{
    if( ui->actionListaPsy->isChecked() == true ){
        if(modelPsy.rowCount() != 0){
            ui->actionWydajpsa->setEnabled(true);
        }
    }
}

void MainWindow::wydajPsa()
{
    QAbstractItemModel * model;
    model = widok->model();
    if( model  == &modelRejestr ) {
        wydajPsaDodajacKlientaIPsa();
        QMessageBox::warning( 0, "UWAGAaaaaaaaaa", "Nie można ustawić<b> pustego</b> nazwiska.<br> "
                              "Proszę wprowadź poprawne imie klienta. ", QMessageBox::Ok);
    }
    else {
        wydajPsaDodajacKlienta();
    }
}

void MainWindow::dodajPsa()
{
    DodajPsaDialog dialog(this);
    if( dialog.exec() == QDialog::Accepted ) { // jeśli dane są poprawne
        DodajPsaTransakcja transakcja( dialog.getId(), dialog.getImie(), dialog.getWiek(),
                                      dialog.getRodzaj(), dialog.getRasa() );
        transakcja.wykonaj();                   // jeśli takiego psa niema w bazie wykonaj
    }
}

void MainWindow::usunPsa()
{
    if( QMessageBox::warning(this, "UWAGA", "Czy napewno chcesz <b>usunąć nieodwracalnie</b> psa?",
                             QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        UsunPsaTransakcja transakcja(widok);
        transakcja.wykonaj();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
