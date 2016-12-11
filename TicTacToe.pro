TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    board.cpp \
    game.cpp

LIBS += -lncurses

HEADERS += \
    board.h \
    game.h
