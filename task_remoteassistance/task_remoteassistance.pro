QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = task_remoteassistance
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget



include(Help/help.pri)

HEADERS += \
    assistancecontrol.h \
    assistancewindow.h


SOURCES += \
    assistancecontrol.cpp \
    assistancewindow.cpp \
    main.cpp \




DISTFILES +=

RESOURCES += \
    resouce.qrc
