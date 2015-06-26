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
           ProgramGlowny/listapsow.cpp \
           ProgramGlowny/przydzielpsatransakcja.cpp \
           ProgramGlowny/transakcja.cpp \
           ProgramGlowny/klient.cpp \
           ProgramGlowny/rejestr.cpp \
           ProgramGlowny/wydaniepsa.cpp \
           ProgramGlowny/listaklientow.h

HEADERS += ProgramGlowny/pies.h \
           ProgramGlowny/listapsow.h \
           ProgramGlowny/transakcja.h \
           ProgramGlowny/klient.h \
           ProgramGlowny/rejestr.cpp \
           ProgramGlowny/wydaniepsa.cpp \
           ProgramGlowny/listaklientow.cpp

SOURCES += tst_schroniskotesty.cpp
DEFINES += SRCDIR=\\\"$$PWD/\\\"
