#-------------------------------------------------
#
# Project created by QtCreator 2018-03-05T09:46:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardsGame
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG(compilation_test)
{
    DEFINES += MODE_TEST
}

CONFIG(tests_unitaire)
{
    #DEFINES += MODE_TESTS_UNITAIRE
}

SOURCES += \
        main.cpp \
        board.cpp \
    src_Cards/abstractcard.cpp \
    src_Cards/cardaction.cpp \
    src_Cards/cardenergy.cpp \
    src_Cards/cardpokemon.cpp \
    src_Packets/abstractpacket.cpp \
    src_Packets/bencharea.cpp \
    src_Packets/fightarea.cpp \
    src_Packets/packetdeck.cpp \
    src_Packets/packethand.cpp \
    src_Packets/packetrewards.cpp \
    src_Packets/packettrash.cpp \
    gamemanager.cpp \
    player.cpp \
    dlgselectcards.cpp \
    utils.cpp \
    common/database.cpp \
    src_Tests/testsunitaires.cpp \
    src_Actions/abstractaction.cpp \
    src_Actions/actionchangeenemystatus.cpp \
    src_Actions/actionchangeenemystatusrandom.cpp \
    src_Actions/actionremoveenergyattached.cpp \
    src_Actions/actionhealing.cpp \
    src_Actions/actionprotectedagainstdamage.cpp \
    src_Actions/actionmoredamagebyenergy.cpp \
    src_Actions/actioncreationfactory.cpp

HEADERS += \
        board.h \
    src_Cards/abstractcard.h \
    src_Cards/cardaction.h \
    src_Cards/cardenergy.h \
    src_Cards/cardpokemon.h \
    src_Packets/abstractpacket.h \
    src_Packets/bencharea.h \
    src_Packets/fightarea.h \
    src_Packets/packetdeck.h \
    src_Packets/packethand.h \
    src_Packets/packetrewards.h \
    src_Packets/packettrash.h \
    gamemanager.h \
    player.h \
    dlgselectcards.h \
    utils.h \
    common/database.h \
    src_Tests/testsunitaires.h \
    src_Actions/abstractaction.h \
    src_Actions/actionchangeenemystatus.h \
    src_Actions/actionchangeenemystatusrandom.h \
    src_Actions/actionremoveenergyattached.h \
    src_Actions/actionhealing.h \
    src_Actions/actionprotectedagainstdamage.h \
    src_Actions/actionmoredamagebyenergy.h \
    src_Actions/actioncreationfactory.h

FORMS += \
        board.ui \
    dlgselectcards.ui
