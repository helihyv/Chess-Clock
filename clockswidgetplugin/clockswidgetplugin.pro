 TEMPLATE = lib
 CONFIG += qt plugin
 QT += declarative
 CONFIG += mobility
 MOBILITY += systeminfo

 DESTDIR = lib
 OBJECTS_DIR = tmp
 MOC_DIR = tmp

HEADERS += \
    classes/wrappedclockswidget.h \
    classes/clockswidget.h \
    classes/chessclockwidget.h \
    classes/chessclock.h \
    classes/clockswidgetplugin.h

SOURCES += \
    classes/wrappedclockswidget.cpp \
    classes/clockswidget.cpp \
    classes/chessclockwidget.cpp \
    classes/chessclock.cpp \
    classes/clockswidgetplugin.cpp

OTHER_FILES += \
    qmldir

unix:!symbian:!maemo5 {
    target.path = /opt/clockswidgetplugin/lib
    INSTALLS += target
}
