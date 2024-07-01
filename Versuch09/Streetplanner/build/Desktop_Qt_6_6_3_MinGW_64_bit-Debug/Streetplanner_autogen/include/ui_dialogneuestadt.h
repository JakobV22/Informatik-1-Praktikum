/********************************************************************************
** Form generated from reading UI file 'dialogneuestadt.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGNEUESTADT_H
#define UI_DIALOGNEUESTADT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogNeueStadt
{
public:
    QFormLayout *formLayout;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_yCoord;
    QLineEdit *lineEdit_xCoord;
    QLineEdit *lineEdit_name_stadt;

    void setupUi(QDialog *DialogNeueStadt)
    {
        if (DialogNeueStadt->objectName().isEmpty())
            DialogNeueStadt->setObjectName("DialogNeueStadt");
        DialogNeueStadt->resize(400, 300);
        formLayout = new QFormLayout(DialogNeueStadt);
        formLayout->setObjectName("formLayout");
        buttonBox = new QDialogButtonBox(DialogNeueStadt);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(0, QFormLayout::LabelRole, buttonBox);

        lineEdit_yCoord = new QLineEdit(DialogNeueStadt);
        lineEdit_yCoord->setObjectName("lineEdit_yCoord");

        formLayout->setWidget(4, QFormLayout::LabelRole, lineEdit_yCoord);

        lineEdit_xCoord = new QLineEdit(DialogNeueStadt);
        lineEdit_xCoord->setObjectName("lineEdit_xCoord");

        formLayout->setWidget(3, QFormLayout::LabelRole, lineEdit_xCoord);

        lineEdit_name_stadt = new QLineEdit(DialogNeueStadt);
        lineEdit_name_stadt->setObjectName("lineEdit_name_stadt");

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEdit_name_stadt);


        retranslateUi(DialogNeueStadt);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogNeueStadt, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogNeueStadt, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogNeueStadt);
    } // setupUi

    void retranslateUi(QDialog *DialogNeueStadt)
    {
        DialogNeueStadt->setWindowTitle(QCoreApplication::translate("DialogNeueStadt", "Dialog", nullptr));
        lineEdit_yCoord->setPlaceholderText(QCoreApplication::translate("DialogNeueStadt", "Y-Koordinate", nullptr));
        lineEdit_xCoord->setPlaceholderText(QCoreApplication::translate("DialogNeueStadt", "X-Koordinate", nullptr));
        lineEdit_name_stadt->setPlaceholderText(QCoreApplication::translate("DialogNeueStadt", "Name der Stadt", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogNeueStadt: public Ui_DialogNeueStadt {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGNEUESTADT_H
