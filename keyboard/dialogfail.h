#ifndef DIALOGFAIL_H
#define DIALOGFAIL_H

#include <QDialog>

namespace Ui {
class DialogFail;
}

class DialogFail : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogFail(QWidget *parent = 0);
    ~DialogFail();
    
private:
    Ui::DialogFail *ui;
};

#endif // DIALOGFAIL_H
