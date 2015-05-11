#ifndef KEYBOARDSELECT_H
#define KEYBOARDSELECT_H

#include <QDialog>

namespace Ui {
class KeyboardSelect;
}

class KeyboardSelect : public QDialog
{
    Q_OBJECT
    
public:
    explicit KeyboardSelect(QWidget *parent = 0);
    ~KeyboardSelect();
    
private:
    Ui::KeyboardSelect *ui;
};

#endif // KEYBOARDSELECT_H
