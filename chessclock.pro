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
    classes/turninformation.cpp \
    classes/chessclock.cpp \
    classes/chessclockwidget.cpp \
    classes/clockswidget.cpp \
    classes/welcomescreenwidget.cpp \
    classes/timecontrol/basicdialog.cpp \
    classes/timecontrol/notimecontrol.cpp \
    classes/startwidget.cpp \
    classes/timecontrol/fischertimecontrol.cpp \
    classes/timecontrol/fischerclock.cpp

HEADERS  += chessclockwindow.h \
    classes/turninformation.h \
    classes/chessclock.h \
    classes/chessclockwidget.h \
    classes/clockswidget.h \
    classes/welcomescreenwidget.h \
    classes/timecontrol.h \
    classes/timecontrol/basicdialog.h \
    classes/timecontrol/notimecontrol.h \
    classes/startwidget.h \
    classes/timecontrol/fischertimecontrol.h \
    classes/timecontrol/fischerclock.h

CONFIG += mobility
MOBILITY = 

symbian {
    TARGET.UID3 = 0xeea9c6c5
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

RESOURCES += \
    chessclock.qrc
