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
    mainwindow.cpp \
    gamegui.cpp

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
    mainwindow.h \
    gamegui.h

FORMS += \
    mainwindow.ui \
    gamegui.ui

DISTFILES += \
    images/WallV.png \
    images/wallHpng.png \
    images/pawn4.png \
    images/pawn3.png \
    images/pawn2.png \
    images/pawn1.png \
    images/Empty.png \
    images/wallH.png \
    images/EmptyWall.png

