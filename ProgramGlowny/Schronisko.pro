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
    listapsow.cpp \
    pies.cpp \
    przydzielpsatransakcja.cpp \
    transakcja.cpp \
    wydaniepsa.cpp \
    rejestr.cpp \
    listaklientow.cpp

HEADERS  += mainwindow.h \
    klient.h \
    listapsow.h \
    pies.h \
    przydzielpsatransakcja.h \
    transakcja.h \
    wydaniepsa.h \
    rejestr.h \
    listaklientow.h

FORMS    += mainwindow.ui
