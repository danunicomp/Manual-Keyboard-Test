#include "debugwindow.h"
#include "ui_debugwindow.h"

#include "cls_unicode.h"

DebugWindow::DebugWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DebugWindow)
{
    ui->setupUi(this);
}

DebugWindow::~DebugWindow()
{
    delete ui;
}

void DebugWindow::on_btnGetScancodes_clicked()
{
    cls_UniCode Keyboard;
}

