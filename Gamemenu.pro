#-------------------------------------------------
#
# Project created by QtCreator 2015-03-21T11:37:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Gamemenu
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    player.cpp \
    games.cpp \
    wow.cpp \
    characters.cpp \
    d3.cpp \
    sc2.cpp \
    hs.cpp \
    wdchar.cpp \
    shochar.cpp \
    hschar.cpp \
    createplayer.cpp \
    shop.cpp \
    account.cpp \
    explore.cpp \
    characterwindow.cpp \
    check.cpp \
    balancecheck.cpp \
    gamecheck.cpp \
    signin.cpp

HEADERS  += mainwindow.h \
    player.h \
    games.h \
    wow.h \
    characters.h \
    d3.h \
    sc2.h \
    hs.h \
    wdchar.h \
    shochar.h \
    hschar.h \
    createplayer.h \
    shop.h \
    account.h \
    explore.h \
    characterwindow.h \
    check.h \
    balancecheck.h \
    gamecheck.h \
    signin.h

FORMS    += mainwindow.ui \
    createplayer.ui \
    shop.ui \
    account.ui \
    explore.ui \
    characterwindow.ui \
    signin.ui

RESOURCES += \
    Resources.qrc

OTHER_FILES += \
    about.txt
