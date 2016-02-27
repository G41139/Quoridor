TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    player.cpp \
    piece.cpp \
    board.cpp

HEADERS += \
    player.h \
    piece.h \
    side.h \
    board.h \
    direction.h \
    alignement.h

