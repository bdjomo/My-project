#-------------------------------------------------
#
# Project created by QtCreator 2016-02-19T20:04:26
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = BuchhaltungRechnung
TEMPLATE = app


SOURCES += main.cpp\
        clogin.cpp \
    crechnunginfo.cpp \
    adminintration.cpp \
    crechnungeninformationen.cpp \
    userinfo.cpp \
    employeeinfo.cpp \
    roleinfo.cpp \
    produktinfo.cpp \
    rechnungerstellen.cpp

HEADERS  += clogin.h \
    crechnunginfo.h \
    adminintration.h \
    crechnungeninformationen.h \
    userinfo.h \
    employeeinfo.h \
    roleinfo.h \
    produktinfo.h \
    rechnungerstellen.h

FORMS    += clogin.ui \
    crechnunginfo.ui \
    adminintration.ui \
    crechnungeninformationen.ui \
    userinfo.ui \
    employeeinfo.ui \
    roleinfo.ui \
    produktinfo.ui \
    rechnungerstellen.ui
