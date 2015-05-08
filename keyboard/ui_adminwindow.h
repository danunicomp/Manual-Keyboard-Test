/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created: Thu May 7 12:28:21 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuNew_KB;
    QStatusBar *statusbar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QString::fromUtf8("AdminWindow"));
        AdminWindow->resize(640, 480);
        centralwidget = new QWidget(AdminWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        AdminWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(AdminWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 640, 22));
        menuNew_KB = new QMenu(menubar);
        menuNew_KB->setObjectName(QString::fromUtf8("menuNew_KB"));
        AdminWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(AdminWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        AdminWindow->setStatusBar(statusbar);
        toolBar = new QToolBar(AdminWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        AdminWindow->addToolBar(Qt::TopToolBarArea, toolBar);

        menubar->addAction(menuNew_KB->menuAction());

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        menuNew_KB->setTitle(QApplication::translate("AdminWindow", "New KB", 0, QApplication::UnicodeUTF8));
        toolBar->setWindowTitle(QApplication::translate("AdminWindow", "toolBar", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
