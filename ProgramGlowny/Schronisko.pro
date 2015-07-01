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
    modelrejestr.cpp \
    modelpsy.cpp \
    modelklienci.cpp \
    dodajpsadialog.cpp \
    dodajpsatransakcja.cpp \
    usunpsatransakcja.cpp \
    delegatdanych.cpp \
    wydajpsadialog.cpp \
    dodajklientadialog.cpp \
    dodajklientatransakcja.cpp

HEADERS  += mainwindow.h \
    klient.h \
    pies.h \
    przydzielpsatransakcja.h \
    transakcja.h \
    wydaniepsa.h \
    modelrejestr.h \
    modelpsy.h \
    modelklienci.h \
    dodajpsadialog.h \
    dodajpsatransakcja.h \
    usunpsatransakcja.h \
    delegatdanych.h \
    wydajpsadialog.h \
    dodajklientadialog.h \
    dodajklientatransakcja.h

FORMS    += mainwindow.ui \
    dodajpsadialog.ui \
    wydajpsadialog.ui \
    dodajklientadialog.ui
