TEMPLATE = app
VERSION = 2.0.15.4.30
QT += qml quick widgets

SOURCES += main.cpp \
    cls_unicode.cpp \
    mainwindow.cpp \
    newkeyboard.cpp \
    temp.cpp \
    signalHandler.cpp \
    cls_unicompcode.cpp \
    startkeypressthread.cpp \
    cls_readwsefile.cpp \
    sudodialog.cpp \
    dialogpass.cpp \
    dialogfail.cpp

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
    cls_readwsefile.h \
    sudodialog.h \
    dialogpass.h \
    dialogfail.h

FORMS += \
    mainwindow.ui \
    sudodialog.ui \
    GType.ui \
    dialogpass.ui \
    dialogfail.ui

OTHER_FILES += \
    test.wse \
    functionkeys.wse \
    _testkeyboard.wse \
    scnacodes.xml
