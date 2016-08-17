TEMPLATE = app

QT += qml quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

SOURCES += main.cpp \
    CPositioner.cpp

RESOURCES += qml.qrc
CONFIG += c++11
# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    CPositioner.hpp
