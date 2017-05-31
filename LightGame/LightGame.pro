TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS += -std=c++11 -pedantic -Wall -Wextra

LIBS           += -lsfml-graphics -lsfml-window -lsfml-system


SOURCES += main.cpp \
    Menu.cpp \
    Application.cpp \
    Action.cpp \
    Execsecprog.cpp \
    Grid.cpp \
    Hexagon.cpp \
    Level.cpp \
    Player.cpp \
    Primaryprog.cpp \
    Program.cpp \
    Robot.cpp \
    Secondaryprog.cpp

HEADERS += \
    Menu.h \
    Application.h \
    Player.h \
    Level.h \
    Hexagon.h \
    Grid.h \
    Execsecprog.h \
    Action.h \
    Primaryprog.h \
    Program.h \
    Robot.h \
    Secondaryprog.h
