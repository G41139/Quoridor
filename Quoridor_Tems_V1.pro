QT       += core gui
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TEMPLATE = app

QMAKE_CXXFLAGS += -std=c++11 \
                    -pedantic-errors
SOURCES += main.cpp \
    player.cpp \
    piece.cpp \
    board.cpp \
    game.cpp \
    observergame.cpp \
    sujetDObservation.cpp \
    mainwindow.cpp

HEADERS += \
    player.h \
    piece.h \
    side.h \
    board.h \
    direction.h \
    alignement.h \
    game.h \
    observergame.h \
    sujetDObservation.h \
    observateur.h \
    mainwindow.h

FORMS += \
    mainwindow.ui

