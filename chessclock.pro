#-------------------------------------------------
#
# Project created by QtCreator 2010-08-13T20:15:03
#
#-------------------------------------------------

QT       += core gui

TARGET = chessclock
TEMPLATE = app


SOURCES += main.cpp\
        chessclockwindow.cpp \
    classes/turninformation.cpp

HEADERS  += chessclockwindow.h \
    classes/turninformation.h

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xeea9c6c5
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}
