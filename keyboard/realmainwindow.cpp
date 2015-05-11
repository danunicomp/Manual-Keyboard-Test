#include <QDesktopWidget>

#include "realmainwindow.h"
#include "ui_realmainwindow.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "debugwindow.h"

#include "kb_quick122.h"
#include "ui_kb_quick122.h"

RealMainWindow::RealMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::RealMainWindow)
{
    ui->setupUi(this);
    //Put the dialog in the screen center
     const QRect screen = QApplication::desktop()->screenGeometry();
     this->move( screen.center() - this->rect().center() );

}

RealMainWindow::~RealMainWindow()
{
    delete ui;
}

void RealMainWindow::on_btnOpenWorkingTest_clicked()
{
   this->close();
    MainWindow *kt = new MainWindow;
    kt->show();

}

void RealMainWindow::on_btnDebug_clicked()
{
    DebugWindow dw;
    dw.show();
    dw.exec();
}

void RealMainWindow::on_btn122QuickTest_clicked()
{
    kb_Quick122 qt;
    qt.show();
    qt.exec();
    // kb_Quick122.show();
}
