#ifndef NEWKEYBOARD_H
#define NEWKEYBOARD_H

#include <QMainWindow>
#include <QApplication>
#include <QtGui/QPushButton>
#include "ui_mainwindow.h"

class NewKeyboard : public QMainWindow
{
  Q_OBJECT
public:
  explicit NewKeyboard(QWidget *parent = 0);
  QVector<QPushButton *> buttons;
  QVector<int> position;
  void KbLoad122 (void);
signals:
  
public slots:

private:
   Ui::MainWindow *ui;

};


#endif // NEWKEYBOARD_H
