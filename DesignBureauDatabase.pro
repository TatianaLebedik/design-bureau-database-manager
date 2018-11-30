#-------------------------------------------------
#
# Project created by QtCreator 2018-11-27T18:59:56
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = DesignBureauDatabase
QTPLUGIN += qsqlmysql
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    authenticationform.cpp \
    allinfonewrecorddialog.cpp \
    customernewrecorddialog.cpp \
    devicenewrecorddialog.cpp \
    teammembernewrecorddialog.cpp \
    employeenewrecorddialog.cpp \
    positionnewrecorddialog.cpp

HEADERS  += mainwindow.h \
    authenticationform.h \
    allinfonewrecorddialog.h \
    customernewrecorddialog.h \
    devicenewrecorddialog.h \
    teammembernewrecorddialog.h \
    employeenewrecorddialog.h \
    positionnewrecorddialog.h

FORMS    += mainwindow.ui \
    authenticationform.ui \
    allinfonewrecorddialog.ui \
    customernewrecorddialog.ui \
    devicenewrecorddialog.ui \
    teammembernewrecorddialog.ui \
    employeenewrecorddialog.ui \
    positionnewrecorddialog.ui
