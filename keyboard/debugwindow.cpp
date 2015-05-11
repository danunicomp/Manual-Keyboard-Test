#include "debugwindow.h"
#include "ui_debugwindow.h"
#include <QString>

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
    int code;
    QString s;
    QString hexadecimal;
    cls_UniCode Keyboard;

    ui->btnGetScancodes->setEnabled(false);
    ui->btnDebugExit->setEnabled(false);
    ui->txbOutput->append("Begin pressing keys");
    QApplication::processEvents();

    while (code != -1) {
        code = Keyboard.GetUnicodeInt();

        s = QString::number(code);

        hexadecimal.setNum(code,16);

        ui->txbOutput->append(hexadecimal);
    } // end getting scancodes

    ui->txbOutput->append("Test ended");
    ui->btnGetScancodes->setEnabled(true);
    ui->btnDebugExit->setEnabled(true);
    QApplication::processEvents();
}


void DebugWindow::on_btnDebugExit_clicked()
{
    this->close();
}
