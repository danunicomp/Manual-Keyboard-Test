#ifndef SUDODIALOG_H
#define SUDODIALOG_H

#include <QDialog>

namespace Ui {
class SudoDialog;
}

class SudoDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit SudoDialog(QWidget *parent = 0);
    ~SudoDialog();
    
private:
    Ui::SudoDialog *ui;
};

#endif // SUDODIALOG_H
