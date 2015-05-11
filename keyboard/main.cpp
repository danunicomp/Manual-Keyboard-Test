#include <QApplication>
//#include <QQmlApplicationEngine>

#include <iostream>
#include <vector>
#include <cstdlib>

#include <qtimer.h>
#include <unistd.h> // getuid
#include <stdio.h> // printf

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "sudodialog.h"
#include "cls_unicode.h"

#include "realmainwindow.h"
#include "ui_realmainwindow.h"

int main(int argc, char *argv[])
{

//QApplication::instance()->setSetuidAllowed(true);

    //std::vector<int> buffer;

  //  cls_UniCode Keyboard;

    QApplication app(argc, argv);

    //QQmlApplicationEngine engine;
   // engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    // *** CHECK IF IN SUDO
    if ( geteuid() ) {SudoDialog *sw = new SudoDialog; sw->show();}
    else {
        RealMainWindow *rm = new RealMainWindow; rm->show();
    }

    return app.exec();
}
