TEMPLATE = app

QT += qml quick widgets

SOURCES += main.cpp \
    cls_unicode.cpp \
    mainwindow.cpp \
    newkeyboard.cpp \
    temp.cpp \
    signalHandler.cpp \
    cls_unicompcode.cpp \
    startkeypressthread.cpp \
    clsreadwsefile.cpp

RESOURCES +=

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    cls_unicode.h \
    mainwindow.h \
    newkeyboard.h \
    signalHandler.h \
    cls_unicompcode.h \
    startkeypressthread.h \
    clsreadwsefile.h

FORMS += \
    mainwindow.ui

OTHER_FILES += \
    test.wse \
    functionkeys.wse
