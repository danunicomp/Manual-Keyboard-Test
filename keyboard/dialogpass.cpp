#include "dialogpass.h"
#include "ui_dialogpass.h"

DialogPass::DialogPass(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPass)
{
    ui->setupUi(this);
}

DialogPass::~DialogPass()
{
    delete ui;
}
