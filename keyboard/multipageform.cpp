#include "multipageform.h"
#include "ui_multipageform.h"

MultiPageForm::MultiPageForm(QWidget *parent) :
    MultiPageWidget(parent),
    ui(new Ui::MultiPageForm)
{
    ui->setupUi(this);
}

MultiPageForm::~MultiPageForm()
{
    delete ui;
}
