# Add more folders to ship with the application, here

# Additional import path used to resolve QML modules in Creator's code model
QML_IMPORT_PATH =

QT+= declarative
symbian:TARGET.UID3 = 0xE00C40B5

# Smart Installer package's UID
# This UID is from the protected range and therefore the package will
# fail to install if self-signed. By default qmake uses the unprotected
# range value if unprotected UID is defined for the application and
# 0x2002CCCF value if protected UID is given to the application
#symbian:DEPLOYMENT.installer_header = 0x2002CCCF

# Allow network access on Symbian
symbian:TARGET.CAPABILITY += NetworkServices

# If your application uses the Qt Mobility libraries, uncomment the following
# lines and add the respective components to the MOBILITY variable.
CONFIG += mobility
MOBILITY += systeminfo

# The .cpp file which was generated for your project. Feel free to hack it.
SOURCES += main.cpp \
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


OTHER_FILES += \
    qml/MainPage.qml \
    qml/main.qml \
    chessclock.desktop \
    chessclock.svg \
    chessclock.png \
    qtc_packaging/debian_harmattan/rules \
    qtc_packaging/debian_harmattan/README \
    qtc_packaging/debian_harmattan/copyright \
    qtc_packaging/debian_harmattan/control \
    qtc_packaging/debian_harmattan/compat \
    qtc_packaging/debian_harmattan/changelog \
    qml/ClocksPage.qml \
    qml/AboutPage.qml

RESOURCES += \
    res.qrc \
    chessclock.qrc

# Please do not modify the following two lines. Required for deployment.
include(deployment.pri)
qtcAddDeployment()

# enable booster
CONFIG += qdeclarative-boostable
QMAKE_CXXFLAGS += -fPIC -fvisibility=hidden -fvisibility-inlines-hidden
QMAKE_LFLAGS += -pie -rdynamic

unix:!symbian:!maemo5 {
    target.path = /opt/chessclock/bin
    INSTALLS += target
}
