TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    cls_unicode.cpp \
    mainwindow.cpp \
    newkeyboard.cpp \
    temp.cpp

RESOURCES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    cls_unicode.h \
    mainwindow.h \
    newkeyboard.h

FORMS += \
    mainwindow.ui
