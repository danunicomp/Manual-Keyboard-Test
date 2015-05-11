#include "keyboardselect.h"
#include "ui_keyboardselect.h"

KeyboardSelect::KeyboardSelect(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::KeyboardSelect)
{
    ui->setupUi(this);
}

KeyboardSelect::~KeyboardSelect()
{
    delete ui;
}
