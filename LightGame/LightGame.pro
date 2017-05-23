TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra

LIBS           += -lsfml-graphics -lsfml-window -lsfml-system


SOURCES += main.cpp \
    robot.cpp \
    action.cpp \
    program.cpp \
    level.cpp \
    player.cpp \
    grid.cpp \
    hexagon.cpp \
    primaryprog.cpp \
    secondaryprog.cpp \
    execsecprog.cpp \
    Menu.cpp \
    Application.cpp

HEADERS += \
    robot.h \
    action.h \
    program.h \
    level.h \
    player.h \
    grid.h \
    hexagon.h \
    primaryprog.h \
    secondaryprog.h \
    execsecprog.h \
    Menu.h \
    Application.h
