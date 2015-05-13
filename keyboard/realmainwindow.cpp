#include <QDesktopWidget>

#include "realmainwindow.h"
#include "ui_realmainwindow.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "debugwindow.h"

#include "kb_122_test.h"
#include "ui_kb_122_test.h"

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

    this->close();
     kb_122_Test *kt = new kb_122_Test;
     kt->show();

    // kb_Quick122.show();
}
