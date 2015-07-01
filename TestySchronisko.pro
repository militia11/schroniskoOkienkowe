#-------------------------------------------------
#
# Project created by QtCreator 2015-06-25T09:07:48
#
#-------------------------------------------------

QT       += testlib

QT       -= gui

TARGET = tst_schroniskotesty
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app

SOURCES += ProgramGlowny/pies.cpp \
           ProgramGlowny/przydzielpsatransakcja.cpp \
           ProgramGlowny/transakcja.cpp \
           ProgramGlowny/klient.cpp \
           ProgramGlowny/modelrejestr.cpp \
           ProgramGlowny/wydaniepsa.cpp \
           ProgramGlowny/modelrejestr.cpp \
           ProgramGlowny/modelklienci.cpp \
           ProgramGlowny/modelpsy.cpp \


HEADERS += ProgramGlowny/pies.h \
           ProgramGlowny/listapsow.h \
           ProgramGlowny/transakcja.h \
           ProgramGlowny/klient.h \
           ProgramGlowny/modelrejestr.cpp \
           ProgramGlowny/wydaniepsa.cpp \
           ProgramGlowny/modelklienci.h \
           ProgramGlowny/modelpsy.h \
           ProgramGlowny/modelrejestr.h

SOURCES += tst_schroniskotesty.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
