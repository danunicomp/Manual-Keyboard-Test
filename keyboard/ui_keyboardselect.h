/********************************************************************************
** Form generated from reading UI file 'keyboardselect.ui'
**
** Created: Mon May 11 08:40:10 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_KEYBOARDSELECT_H
#define UI_KEYBOARDSELECT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_KeyboardSelect
{
public:

    void setupUi(QDialog *KeyboardSelect)
    {
        if (KeyboardSelect->objectName().isEmpty())
            KeyboardSelect->setObjectName(QString::fromUtf8("KeyboardSelect"));
        KeyboardSelect->resize(640, 480);

        retranslateUi(KeyboardSelect);

        QMetaObject::connectSlotsByName(KeyboardSelect);
    } // setupUi

    void retranslateUi(QDialog *KeyboardSelect)
    {
        KeyboardSelect->setWindowTitle(QApplication::translate("KeyboardSelect", "Dialog", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class KeyboardSelect: public Ui_KeyboardSelect {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_KEYBOARDSELECT_H
