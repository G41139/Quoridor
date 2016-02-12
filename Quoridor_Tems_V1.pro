TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    piece.cpp \
    pawn.cpp \
    board.cpp \
    game.cpp

HEADERS += \
    player.h \
    piece.h \
    pawn.h \
    side.h \
    board.h \
    direction.h \
    game.h

