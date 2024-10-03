#-------------------------------------------------
#
# Project created by QtCreator 2017-09-15T03:25:43
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = kd_tree_dibujo
TEMPLATE = app


SOURCES += main.cpp\
        dialog.cpp

HEADERS  += dialog.h \
    nodo.h

FORMS    += dialog.ui

DISTFILES += \
    country_capitals.csv \
    archivo.csv \
    crime50k.csv \
    crime20k.csv
