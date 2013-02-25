# The name of your app
TARGET = ChessClock

# The .desktop file
desktop.files = EkaSailfishTesti.desktop

# Please do not modify the following line.
include(sailfishapplication/sailfishapplication.pri)

QT+= declarative


VERSION = 2.0.2


# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
CONFIG += mobility
MOBILITY += systeminfo

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
    classes/chessclock.cpp \
    classes/chessclockwidget.cpp \
    classes/clockswidget.cpp \
    classes/timecontrol/fischerclock.cpp \
    classes/timecontrol/fischerafterclock.cpp \
    classes/timecontrol/delayclock.cpp \
    classes/timecontrol/delayafterclock.cpp \
    classes/timecontrol/hourglassclock.cpp \
    classes/wrappedclockswidget.cpp \
    classes/settings.cpp \
    classes/turninformation.cpp \
    sailfishapplication/sailfishapplication.cpp

HEADERS  += \
    classes/turninformation.h \
    classes/chessclock.h \
    classes/chessclockwidget.h \
    classes/clockswidget.h \
    classes/timecontrol/fischerclock.h \
    classes/timecontrol/fischerafterclock.h \
    classes/timecontrol/delayclock.h \
    classes/timecontrol/delayafterclock.h \
    classes/timecontrol/hourglassclock.h \
    classes/wrappedclockswidget.h \
    classes/settings.h \
    sailfishapplication/sailfishapplication.h


OTHER_FILES += \
    qml/MainPage.qml \
    qml/main.qml \
    chessclock.desktop \
    chessclock.png \
    qml/ClocksPage.qml \
    qml/AboutPage.qml \
    qml/NewGameDialogPage.qml \
    chessclock_splashscreen.png \
    rpm/EkaSailfishTesti.yaml



RESOURCES += \
    res.qrc \
    chessclock.qrc

#splash.files = chessclock_splashscreen.png
#splash.path = /opt/chessclock/images
#INSTALLS += splash




## enable booster
#CONFIG += qdeclarative-boostable
#QMAKE_CXXFLAGS += -fPIC -fvisibility=hidden -fvisibility-inlines-hidden
#QMAKE_LFLAGS += -pie -rdynamic

#unix:!symbian:!maemo5 {
#    target.path = /opt/chessclock/bin
#    INSTALLS += target


#}








