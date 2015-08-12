#-------------------------------------------------
#
# Project created by QtCreator 2015-07-22T15:52:35
#
#-------------------------------------------------

QT       += core gui multimedia androidextras

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Werewolves_v0_2
TEMPLATE = app


SOURCES += main.cpp\
        werewolves.cpp \
    characterscreen.cpp \
    nightscreen.cpp \
    dayscreen.cpp \
    characters.cpp \
    characterbutton.cpp \
    startscreen.cpp \
    gamevariables.cpp \
    morningscreen.cpp \
    settingsscreen.cpp \
    infoscreen.cpp \
    charinfoscreen.cpp \
    gameinfoscreen.cpp \
    infobutton.cpp \
    settimerbutton.cpp \
    resetdialog.cpp

HEADERS  += werewolves.h \
    characterscreen.h \
    nightscreen.h \
    dayscreen.h \
    characters.h \
    characterbutton.h \
    startscreen.h \
    gamevariables.h \
    morningscreen.h \
    settingsscreen.h \
    infoscreen.h \
    charinfoscreen.h \
    gameinfoscreen.h \
    infobutton.h \
    settimerbutton.h \
    resetdialog.h

FORMS    += werewolves.ui

RESOURCES += \
    images.qrc \
    stylesheet.qrc \
    fonts.qrc \
    sounds.qrc \
    icons.qrc

DISTFILES +=
