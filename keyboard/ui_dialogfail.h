/********************************************************************************
** Form generated from reading UI file 'dialogfail.ui'
**
** Created: Tue May 5 08:11:01 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGFAIL_H
#define UI_DIALOGFAIL_H

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

class Ui_DialogFail
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogFail)
    {
        if (DialogFail->objectName().isEmpty())
            DialogFail->setObjectName(QString::fromUtf8("DialogFail"));
        DialogFail->setWindowModality(Qt::ApplicationModal);
        DialogFail->resize(400, 300);
        DialogFail->setModal(true);
        verticalLayout = new QVBoxLayout(DialogFail);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DialogFail);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(72);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(DialogFail);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogFail);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogFail, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogFail, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogFail);
    } // setupUi

    void retranslateUi(QDialog *DialogFail)
    {
        DialogFail->setWindowTitle(QApplication::translate("DialogFail", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogFail", "FAIL", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogFail: public Ui_DialogFail {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGFAIL_H
