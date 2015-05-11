/********************************************************************************
** Form generated from reading UI file 'debugwindow.ui'
**
** Created: Mon May 11 09:41:58 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEBUGWINDOW_H
#define UI_DEBUGWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QPushButton>
#include <QtGui/QTextBrowser>

QT_BEGIN_NAMESPACE

class Ui_DebugWindow
{
public:
    QGroupBox *groupBox;
    QTextBrowser *txbOutput;
    QPushButton *btnGetScancodes;
    QPushButton *btnDebugExit;

    void setupUi(QDialog *DebugWindow)
    {
        if (DebugWindow->objectName().isEmpty())
            DebugWindow->setObjectName(QString::fromUtf8("DebugWindow"));
        DebugWindow->resize(640, 480);
        DebugWindow->setMinimumSize(QSize(640, 480));
        DebugWindow->setMaximumSize(QSize(640, 480));
        DebugWindow->setModal(true);
        groupBox = new QGroupBox(DebugWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 60, 601, 401));
        txbOutput = new QTextBrowser(groupBox);
        txbOutput->setObjectName(QString::fromUtf8("txbOutput"));
        txbOutput->setGeometry(QRect(30, 30, 261, 351));
        btnGetScancodes = new QPushButton(groupBox);
        btnGetScancodes->setObjectName(QString::fromUtf8("btnGetScancodes"));
        btnGetScancodes->setGeometry(QRect(320, 40, 83, 25));
        btnDebugExit = new QPushButton(groupBox);
        btnDebugExit->setObjectName(QString::fromUtf8("btnDebugExit"));
        btnDebugExit->setGeometry(QRect(500, 360, 83, 25));

        retranslateUi(DebugWindow);

        QMetaObject::connectSlotsByName(DebugWindow);
    } // setupUi

    void retranslateUi(QDialog *DebugWindow)
    {
        DebugWindow->setWindowTitle(QApplication::translate("DebugWindow", "Debug Keyboard", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("DebugWindow", "GroupBox", 0, QApplication::UnicodeUTF8));
        btnGetScancodes->setText(QApplication::translate("DebugWindow", "Test Keys", 0, QApplication::UnicodeUTF8));
        btnDebugExit->setText(QApplication::translate("DebugWindow", "Close", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DebugWindow: public Ui_DebugWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEBUGWINDOW_H
