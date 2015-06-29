/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionDodajPsa;
    QAction *actionZamknij;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuPlik_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(400, 300);
        actionDodajPsa = new QAction(MainWindow);
        actionDodajPsa->setObjectName(QStringLiteral("actionDodajPsa"));
        actionZamknij = new QAction(MainWindow);
        actionZamknij->setObjectName(QStringLiteral("actionZamknij"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 400, 25));
        menuPlik = new QMenu(menuBar);
        menuPlik->setObjectName(QStringLiteral("menuPlik"));
        menuPlik_2 = new QMenu(menuBar);
        menuPlik_2->setObjectName(QStringLiteral("menuPlik_2"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuPlik_2->menuAction());
        menuBar->addAction(menuPlik->menuAction());
        menuPlik->addAction(actionDodajPsa);
        menuPlik_2->addAction(actionZamknij);
        mainToolBar->addAction(actionDodajPsa);
        mainToolBar->addSeparator();

        retranslateUi(MainWindow);
        QObject::connect(actionZamknij, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        actionDodajPsa->setText(QApplication::translate("MainWindow", "Dodaj Psa", 0));
#ifndef QT_NO_TOOLTIP
        actionDodajPsa->setToolTip(QApplication::translate("MainWindow", "dodanie Psa do listy Psow", 0));
#endif // QT_NO_TOOLTIP
        actionZamknij->setText(QApplication::translate("MainWindow", "Zamknij", 0));
#ifndef QT_NO_TOOLTIP
        actionZamknij->setToolTip(QApplication::translate("MainWindow", "Wyj\305\233cie do systemu", 0));
#endif // QT_NO_TOOLTIP
        menuPlik->setTitle(QApplication::translate("MainWindow", "Schronisko", 0));
        menuPlik_2->setTitle(QApplication::translate("MainWindow", "Plik", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
