#-------------------------------------------------
#
# Project created by QtCreator 2014-07-05T17:08:49
#
#-------------------------------------------------

QT       += core network widgets


TARGET = client
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    client.cpp \
    mainwindow.cpp \
    commandparser.cpp \
    tests/commandparsertest.cpp

HEADERS += \
    client.h \
    mainwindow.h \
    commandparser.h \
    clientdelegate.h \
    tests/commandparsertest.h

FORMS += \
    mainwindow.ui


build_tests {
  TARGET = test
  DEFINES += TEST
  QT += testlib
}
