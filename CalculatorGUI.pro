#-------------------------------------------------
#
# Project created by QtCreator 2019-05-13T16:02:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CalculatorGUI
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
        mainwindow.cpp

HEADERS += \
        ../Desktop/College/Semester 2 Classes/CS 2560/BigNumbersLibrary/BigNumbersLib.h \
        mainwindow.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../Desktop/release/ -lBigNumbersLibrary
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../Desktop/debug/ -lBigNumbersLibrary
else:unix: LIBS += -L$$PWD/../Desktop/ -lBigNumbersLibrary

INCLUDEPATH += $$PWD/../Desktop
DEPENDPATH += $$PWD/../Desktop

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Desktop/release/libBigNumbersLibrary.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Desktop/debug/libBigNumbersLibrary.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../Desktop/release/BigNumbersLibrary.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../Desktop/debug/BigNumbersLibrary.lib
else:unix: PRE_TARGETDEPS += $$PWD/../Desktop/libBigNumbersLibrary.a
