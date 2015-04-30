#include "sudodialog.h"
#include "ui_sudodialog.h"

SudoDialog::SudoDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SudoDialog)
{
    ui->setupUi(this);
}

SudoDialog::~SudoDialog()
{
    delete ui;
}
