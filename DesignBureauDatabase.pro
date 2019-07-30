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
    allInfoNewRecordDialog.cpp \
    authenticationForm.cpp \
    contractDetailsDialog.cpp \
    customerNewRecordDialog.cpp \
    deviceNewRecordDialog.cpp \
    employeeNewRecordDialog.cpp \
    positionNewRecordDialog.cpp \
    teamMemberNewRecordDialog.cpp

HEADERS  += mainwindow.h \
    allInfoNewRecordDialog.h \
    authenticationForm.h \
    contractDetailsDialog.h \
    customerNewRecordDialog.h \
    deviceNewRecordDialog.h \
    employeeNewRecordDialog.h \
    positionNewRecordDialog.h \
    teamMemberNewRecordDialog.h

FORMS    += mainwindow.ui \
    allInfoNewRecordDialog.ui \
    authenticationForm.ui \
    contractDetailsDialog.ui \
    customerNewRecordDialog.ui \
    deviceNewRecordDialog.ui \
    employeeNewRecordDialog.ui \
    positionNewRecordDialog.ui \
    teamMemberNewRecordDialog.ui

RESOURCES += \
    resourse.qrc

DISTFILES += \
    .gitignore
