#ifndef KB_122_TEST_H
#define KB_122_TEST_H

#include <QMainWindow>
#include <QtCore>
#include <QtGui/QPushButton>

namespace Ui {
class kb_122_Test;
}

class kb_122_Test : public QMainWindow
{
    Q_OBJECT

public:
    explicit kb_122_Test(QWidget *parent = 0);
    ~kb_122_Test();

private slots:
    void on_btnClose_clicked();

    void on_btnStartTest_clicked();

private:
    Ui::kb_122_Test *ui;
    void DoTest2015 (void);
    void DefineKeyboard(void);
    QVector<QPushButton *> buttons;
};

#endif // kb_122_Test_H
