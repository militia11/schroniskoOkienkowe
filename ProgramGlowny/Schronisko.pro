#-------------------------------------------------
#
# Project created by QtCreator 2015-06-26T17:25:15
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Schronisko
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    klient.cpp \
    pies.cpp \
    przydzielpsatransakcja.cpp \
    transakcja.cpp \
    wydaniepsa.cpp \
    rejestr.cpp \
    modelrejestr.cpp \
    modelpsy.cpp \
    modelklienci.cpp \
    dodajpsadialog.cpp

HEADERS  += mainwindow.h \
    klient.h \
    pies.h \
    przydzielpsatransakcja.h \
    transakcja.h \
    wydaniepsa.h \
    rejestr.h \
    modelrejestr.h \
    modelpsy.h \
    modelklienci.h \
    dodajpsadialog.h

FORMS    += mainwindow.ui \
    dodajpsadialog.ui
