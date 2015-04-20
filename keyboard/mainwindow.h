#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include <QtGui/QPushButton>


namespace Ui {
class MainWindow;

}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();


private slots:
    void DoTest(void);
    void RealTest(void);
    void on_btnStop_clicked();
    void on_GetUnicodes_clicked();
    void on_btnCycle_clicked();

private:
    Ui::MainWindow *ui;

    int test;

    bool CheckForBreak(int);
    void KbLoad122 (void);
    void ShowKeyboard(void);
    void DeclareKeys (void);
    QVector<QPushButton *> buttons;
      QVector<int> position;
      QVector<std::string> ExpectedMakeUnicode;
      QVector<std::string> ExpectedBreakUnicode;

 std::string VectorToString(std::vector<int> CurVector);

};

#endif // MAINWINDOW_H