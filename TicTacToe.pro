TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += src/main.cpp \
    src/board.cpp \
    src/game.cpp

LIBS += -lncurses

HEADERS += \
    src/board.h \
    src/game.h
