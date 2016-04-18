TEMPLATE = app

QT += qml quick positioning
CONFIG += c++11

SOURCES += main.cpp \
    devicelocation.cpp \
    gpsspeeddata.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    devicelocation.h \
    gpsspeeddata.h
