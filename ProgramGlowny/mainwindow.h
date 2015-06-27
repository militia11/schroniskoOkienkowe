#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCloseEvent>
#include <QTableView>
#include "modelrejestr.h"
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

private slots:
    void dodajPsa();

private:
    Ui::MainWindow *ui;
    ModelRejestr *modelRejestr;
    QTableView *widokRejestr;
};

#endif // MAINWINDOW_H
