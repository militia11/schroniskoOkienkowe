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
    QAction *actionUsunPsa;
    QAction *actionRejestrWydan;
    QAction *actionListaPsy;
    QAction *actionListaKlientow;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menuPlik;
    QMenu *menuPlik_2;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(896, 643);
        actionDodajPsa = new QAction(MainWindow);
        actionDodajPsa->setObjectName(QStringLiteral("actionDodajPsa"));
        actionZamknij = new QAction(MainWindow);
        actionZamknij->setObjectName(QStringLiteral("actionZamknij"));
        actionUsunPsa = new QAction(MainWindow);
        actionUsunPsa->setObjectName(QStringLiteral("actionUsunPsa"));
        actionRejestrWydan = new QAction(MainWindow);
        actionRejestrWydan->setObjectName(QStringLiteral("actionRejestrWydan"));
        actionRejestrWydan->setCheckable(true);
        actionListaPsy = new QAction(MainWindow);
        actionListaPsy->setObjectName(QStringLiteral("actionListaPsy"));
        actionListaPsy->setCheckable(true);
        actionListaKlientow = new QAction(MainWindow);
        actionListaKlientow->setObjectName(QStringLiteral("actionListaKlientow"));
        actionListaKlientow->setCheckable(true);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 896, 25));
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
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QStringLiteral("toolBar"));
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menuBar->addAction(menuPlik_2->menuAction());
        menuBar->addAction(menuPlik->menuAction());
        menuPlik->addAction(actionDodajPsa);
        menuPlik->addAction(actionUsunPsa);
        menuPlik_2->addAction(actionZamknij);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRejestrWydan);
        mainToolBar->addAction(actionListaPsy);
        mainToolBar->addAction(actionListaKlientow);
        toolBar->addAction(actionDodajPsa);
        toolBar->addAction(actionUsunPsa);

        retranslateUi(MainWindow);
        QObject::connect(actionZamknij, SIGNAL(triggered()), MainWindow, SLOT(close()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Schronisko  v1.0", 0));
        actionDodajPsa->setText(QApplication::translate("MainWindow", "Dodaj Psa", 0));
#ifndef QT_NO_TOOLTIP
        actionDodajPsa->setToolTip(QApplication::translate("MainWindow", "dodanie Psa do listy Psow (Ctrl + N)", 0));
#endif // QT_NO_TOOLTIP
        actionDodajPsa->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", 0));
        actionZamknij->setText(QApplication::translate("MainWindow", "Zamknij", 0));
#ifndef QT_NO_TOOLTIP
        actionZamknij->setToolTip(QApplication::translate("MainWindow", "Wyj\305\233cie do systemu", 0));
#endif // QT_NO_TOOLTIP
        actionUsunPsa->setText(QApplication::translate("MainWindow", "Usu\305\204 Psa", 0));
#ifndef QT_NO_TOOLTIP
        actionUsunPsa->setToolTip(QApplication::translate("MainWindow", "Usu\305\204 bezpowrotnie psa ( Ctrl + X )", 0));
#endif // QT_NO_TOOLTIP
        actionUsunPsa->setShortcut(QApplication::translate("MainWindow", "Ctrl+X", 0));
        actionRejestrWydan->setText(QApplication::translate("MainWindow", "RejestrWyda\305\204", 0));
#ifndef QT_NO_TOOLTIP
        actionRejestrWydan->setToolTip(QApplication::translate("MainWindow", "Poka\305\274 Rejestr Wyda\305\204 (Ctrl + W)", 0));
#endif // QT_NO_TOOLTIP
        actionRejestrWydan->setShortcut(QApplication::translate("MainWindow", "Ctrl+W", 0));
        actionListaPsy->setText(QApplication::translate("MainWindow", "Lista Ps\303\263w", 0));
#ifndef QT_NO_TOOLTIP
        actionListaPsy->setToolTip(QApplication::translate("MainWindow", "Poka\305\274 List\304\231 Ps\303\263w (Ctrl + P)", 0));
#endif // QT_NO_TOOLTIP
        actionListaPsy->setShortcut(QApplication::translate("MainWindow", "Ctrl+P", 0));
        actionListaKlientow->setText(QApplication::translate("MainWindow", "Lista Klient\303\263w", 0));
#ifndef QT_NO_TOOLTIP
        actionListaKlientow->setToolTip(QApplication::translate("MainWindow", "Poka\305\274 Liste Klient\303\263w (Ctrl + K)", 0));
#endif // QT_NO_TOOLTIP
        actionListaKlientow->setShortcut(QApplication::translate("MainWindow", "Ctrl+K", 0));
        menuPlik->setTitle(QApplication::translate("MainWindow", "Schronisko", 0));
        menuPlik_2->setTitle(QApplication::translate("MainWindow", "Plik", 0));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
