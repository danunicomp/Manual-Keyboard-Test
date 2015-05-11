#ifndef REALMAINWINDOW_H
#define REALMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class RealMainWindow;
}

class RealMainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit RealMainWindow(QWidget *parent = 0);
    ~RealMainWindow();
    
private slots:
    void on_btnOpenWorkingTest_clicked();

    void on_btnDebug_clicked();

    void on_btn122QuickTest_clicked();

private:
    Ui::RealMainWindow *ui;
};

#endif // REALMAINWINDOW_H
