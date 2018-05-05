#-------------------------------------------------
#
# Project created by QtCreator 2018-04-28T08:12:11
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = 254
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    help.cpp \
    qcustomplot.cpp \
    plot.cpp \
    table.cpp

HEADERS  += mainwindow.h \
    help.h \
    qcustomplot.h \
    plot.h \
    table.h

FORMS    += mainwindow.ui \
    help.ui \
    plot.ui \
    table.ui
