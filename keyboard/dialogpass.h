#ifndef DIALOGPASS_H
#define DIALOGPASS_H

#include <QDialog>

namespace Ui {
class DialogPass;
}

class DialogPass : public QDialog
{
    Q_OBJECT
    
public:
    explicit DialogPass(QWidget *parent = 0);
    ~DialogPass();
    
private:
    Ui::DialogPass *ui;
};

#endif // DIALOGPASS_H
