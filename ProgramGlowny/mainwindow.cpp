#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDate>
#include <QMessageBox>

#include "pies.h"
#include "klient.h"
#include "wydaniepsa.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QObject::connect(ui->actionDodajPsa, SIGNAL( triggered() ), this, SLOT( dodajPsa()) );

    Pies* pies = new Pies(1, "Dino", 8, Grozny, "Owczarek" );
    Klient* klient = new Klient(2, "Jan", "Bury", "ul. Osa 12; Bydgoszcz; 85790", 857464757);
    QDate* dataPrzydzielenia = new QDate(2014, 07, 23);
    WydaniePsa* wydaniePsa = new WydaniePsa(pies, klient, dataPrzydzielenia);



    modelRejestr = new ModelRejestr(this);
    widokRejestr = new QTableView(this);
    widokRejestr->setModel(modelRejestr);

    int row = modelRejestr->rowCount();
    modelRejestr->insertRows( row, 1, wydaniePsa );
    setCentralWidget(widokRejestr);
}
void MainWindow::closeEvent(QCloseEvent *event) {
    //if(modelCareer->rowCount() || modelPeople->rowCount() ) {
        if( (QMessageBox::warning( this, "WARNING", "<center>Do you want to close application? You have data in models. Any unsaved data will be lost. Do you want to quit application?", QMessageBox::Yes | QMessageBox::No) ) == QMessageBox::No) {
            event->ignore();
            return;
        }
   // }
        event->accept();
}

void MainWindow::dodajPsa()
{
    QMessageBox::warning( this, "WARNING", "<center>Do you want to close application? You have data in models. Any unsaved data will be lost. Do you want to quit application?", QMessageBox::Yes | QMessageBox::No);
}
MainWindow::~MainWindow()
{
    delete ui;
}
