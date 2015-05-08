#include <QDesktopWidget>

#include "realmainwindow.h"
#include "ui_realmainwindow.h"

#include "mainwindow.h"
#include "ui_mainwindow.h"

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
