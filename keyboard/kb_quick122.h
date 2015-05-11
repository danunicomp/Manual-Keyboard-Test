#ifndef KB_QUICK122_H
#define KB_QUICK122_H

#include <QDialog>

namespace Ui {
class kb_Quick122;
}

class kb_Quick122 : public QDialog
{
    Q_OBJECT
    
public:
    explicit kb_Quick122(QWidget *parent = 0);
    ~kb_Quick122();
    
private slots:
    void on_btnClose_clicked();

    void on_btnStartTest_clicked();

private:
    Ui::kb_Quick122 *ui;
    void DoTest2015 (void);
    void DefineKeyboard(void);
    QVector<QPushButton *> buttons;
};

#endif // KB_QUICK122_H
