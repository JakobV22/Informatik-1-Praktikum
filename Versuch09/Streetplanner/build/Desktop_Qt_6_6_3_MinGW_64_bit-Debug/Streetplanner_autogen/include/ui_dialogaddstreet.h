/********************************************************************************
** Form generated from reading UI file 'dialogaddstreet.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADDSTREET_H
#define UI_DIALOGADDSTREET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_DialogAddStreet
{
public:
    QFormLayout *formLayout;
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit_street_city1;
    QLineEdit *lineEdit_street_city2;
    QLabel *label;

    void setupUi(QDialog *DialogAddStreet)
    {
        if (DialogAddStreet->objectName().isEmpty())
            DialogAddStreet->setObjectName("DialogAddStreet");
        DialogAddStreet->resize(400, 300);
        formLayout = new QFormLayout(DialogAddStreet);
        formLayout->setObjectName("formLayout");
        buttonBox = new QDialogButtonBox(DialogAddStreet);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(0, QFormLayout::LabelRole, buttonBox);

        lineEdit_street_city1 = new QLineEdit(DialogAddStreet);
        lineEdit_street_city1->setObjectName("lineEdit_street_city1");

        formLayout->setWidget(2, QFormLayout::LabelRole, lineEdit_street_city1);

        lineEdit_street_city2 = new QLineEdit(DialogAddStreet);
        lineEdit_street_city2->setObjectName("lineEdit_street_city2");

        formLayout->setWidget(3, QFormLayout::LabelRole, lineEdit_street_city2);

        label = new QLabel(DialogAddStreet);
        label->setObjectName("label");

        formLayout->setWidget(1, QFormLayout::LabelRole, label);


        retranslateUi(DialogAddStreet);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogAddStreet, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogAddStreet, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogAddStreet);
    } // setupUi

    void retranslateUi(QDialog *DialogAddStreet)
    {
        DialogAddStreet->setWindowTitle(QCoreApplication::translate("DialogAddStreet", "Dialog", nullptr));
        lineEdit_street_city1->setText(QString());
        lineEdit_street_city1->setPlaceholderText(QCoreApplication::translate("DialogAddStreet", "City 1", nullptr));
        lineEdit_street_city2->setPlaceholderText(QCoreApplication::translate("DialogAddStreet", "City 2", nullptr));
        label->setText(QCoreApplication::translate("DialogAddStreet", "Add Street between City 1 and City 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogAddStreet: public Ui_DialogAddStreet {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDSTREET_H
