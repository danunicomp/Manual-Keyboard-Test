/********************************************************************************
** Form generated from reading UI file 'dialogpass.ui'
**
** Created: Tue May 5 08:11:01 2015
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGPASS_H
#define UI_DIALOGPASS_H

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

class Ui_DialogPass
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogPass)
    {
        if (DialogPass->objectName().isEmpty())
            DialogPass->setObjectName(QString::fromUtf8("DialogPass"));
        DialogPass->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(DialogPass);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        label = new QLabel(DialogPass);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setPointSize(72);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        buttonBox = new QDialogButtonBox(DialogPass);
        buttonBox->setObjectName(QString::fromUtf8("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(DialogPass);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogPass, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogPass, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogPass);
    } // setupUi

    void retranslateUi(QDialog *DialogPass)
    {
        DialogPass->setWindowTitle(QApplication::translate("DialogPass", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("DialogPass", "PASS", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class DialogPass: public Ui_DialogPass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGPASS_H
