/********************************************************************************
** Form generated from reading UI file 'sudodialog.ui'
**
** Created: Tue Apr 28 14:04:07 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUDODIALOG_H
#define UI_SUDODIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SudoDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *SudoDialog)
    {
        if (SudoDialog->objectName().isEmpty())
            SudoDialog->setObjectName(QString::fromUtf8("SudoDialog"));
        SudoDialog->resize(399, 226);
        verticalLayout_2 = new QVBoxLayout(SudoDialog);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(SudoDialog);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(31);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        label->setWordWrap(true);

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(SudoDialog);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(SudoDialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), SudoDialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), SudoDialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(SudoDialog);
    } // setupUi

    void retranslateUi(QDialog *SudoDialog)
    {
        SudoDialog->setWindowTitle(QApplication::translate("SudoDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("SudoDialog", "THIS MUST BE RAN AS SUDO", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class SudoDialog: public Ui_SudoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUDODIALOG_H
