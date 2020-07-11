#-------------------------------------------------
#
# Project created by QtCreator 2019-09-05T04:42:32
#
#-------------------------------------------------

QT       += core gui \
         multimedia


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Snakefin
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        brick.cpp \
        bug.cpp \
        button.cpp \
        fruit.cpp \
        gameconsole.cpp \
        hh.cpp \
        main.cpp \
        score.cpp \
        snake.cpp \
        snakebodypart.cpp \
        snaket.cpp \
        star.cpp \
        wall.cpp

HEADERS += \
    brick.h \
    bug.h \
    button.h \
    fruit.h \
    gameconsole.h \
    hh.h \
    score.h \
    snake.h \
    snakebodypart.h \
    snaket.h \
    star.h \
    wall.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

INCLUDEPATH += /usr/local/include/qgis

#include <QtGui/QApplication>
#include "mainwindow.h"
#include <qgsvectorlayer.h>
#include <qgsapplication.h>
#include <qgsproviderregistry.h>
#include <qgssinglesymbolrenderer.h>
#include <qgsmaplayerregistry.h>
#include <qgsvectorlayer.h>
#include <qgsmapcanvas.h>
#include <qgraphicspixmapitem.h>

