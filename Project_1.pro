#-------------------------------------------------
#
# Project created by QtCreator 2021-06-09T15:55:19
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Project_1
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

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    volumecontrol.cpp \
    about.cpp \
    maps.cpp \
    interiorlights.cpp \
    lightbrightness.cpp

HEADERS += \
        mainwindow.h \
    volumecontrol.h \
    about.h \
    maps.h \
    interiorlights.h \
    lightbrightness.h

FORMS += \
        mainwindow.ui \
    volumecontrol.ui \
    about.ui \
    maps.ui \
    interiorlights.ui \
    lightbrightness.ui

# Added: Spanish Tutorial "Raspberry Pi 4 C++ WiringPi QtCreator GPIO 01" by HeTPro
LIBS += -L/usr/local/lib -lwiringPi


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
