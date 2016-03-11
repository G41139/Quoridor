TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    piece.cpp \
    board.cpp \
    game.cpp \
    observergame.cpp \
    sujetDObservation.cpp

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
    observateur.h

