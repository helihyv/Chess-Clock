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
    classes/timecontrol/fischerclock.cpp \
    classes/timecontrol/fischerafterclock.cpp \
    classes/timecontrol/fischeraftertimecontrol.cpp \
    classes/timecontrol/delayclock.cpp \
    classes/timecontrol/delaytimecontrol.cpp \
    classes/timecontrol/delayafterclock.cpp \
    classes/timecontrol/delayaftertimecontrol.cpp \
    classes/timecontrol/hourglassclock.cpp \
    classes/timecontrol/hourglasstimecontrol.cpp \
    classes/screenlitkeeper.cpp

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
    classes/timecontrol/fischerclock.h \
    classes/timecontrol/fischerafterclock.h \
    classes/timecontrol/fischeraftertimecontrol.h \
    classes/timecontrol/delayclock.h \
    classes/timecontrol/delaytimecontrol.h \
    classes/timecontrol/delayafterclock.h \
    classes/timecontrol/delayaftertimecontrol.h \
    classes/timecontrol/hourglasstimecontrol.h \
    classes/timecontrol/hourglassclock.h \
    classes/screenlitkeeper.h

CONFIG += mobility
MOBILITY += systeminfo 

symbian {
    TARGET.UID3 = 0xeea9c6c5
    # TARGET.CAPABILITY += 
    TARGET.EPOCSTACKSIZE = 0x14000
    TARGET.EPOCHEAPSIZE = 0x020000 0x800000
}

RESOURCES += \
    chessclock.qrc

target.path = /usr/local/bin
INSTALLS += target

OTHER_FILES += \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    qtc_packaging/debian_fremantle/rules \
    qtc_packaging/debian_fremantle/README \
    qtc_packaging/debian_fremantle/copyright \
    qtc_packaging/debian_fremantle/control \
    qtc_packaging/debian_fremantle/compat \
    qtc_packaging/debian_fremantle/changelog

unix:!symbian:!maemo5 {
    desktopfile.files = $${TARGET}.desktop
    desktopfile.path = /usr/share/applications
    INSTALLS += desktopfile
}
