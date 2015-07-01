#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTableView>
#include "delegatdanych.h"
#include "dodajpsadialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void closeEvent(QCloseEvent* event);
    void wydajPsaDodajacKlientaIPsa();
    void wydajPsaDodajacKlienta();

private slots:
    void aktualizujWidok();
    void wydajPsa();
    void dodajPsa();
    void usunPsa();

    void pokazRejestr();
    void pokazPsy();
    void pokazKlientow();

private:
    Ui::MainWindow *ui;
    QTableView *widokRejestr;
    QTableView *widok;
    DelegatDanych* delegat;
};

#endif // MAINWINDOW_H
