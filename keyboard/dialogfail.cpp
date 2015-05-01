#include "dialogfail.h"
#include "ui_dialogfail.h"

DialogFail::DialogFail(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogFail)
{
    ui->setupUi(this);
}

DialogFail::~DialogFail()
{
    delete ui;
}
