/********************************************************************************
** Form generated from reading UI file 'dodajpsadialog.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DODAJPSADIALOG_H
#define UI_DODAJPSADIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DodajPsaDialog
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *lineEditId;
    QLabel *label_7;
    QLineEdit *lineEditImie;
    QLabel *label_3;
    QLineEdit *lineEditWiek;
    QLabel *label_4;
    QLineEdit *lineEditRasa;
    QLabel *label_5;
    QLineEdit *lineEditRodzaj;

    void setupUi(QDialog *DodajPsaDialog)
    {
        if (DodajPsaDialog->objectName().isEmpty())
            DodajPsaDialog->setObjectName(QStringLiteral("DodajPsaDialog"));
        DodajPsaDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(DodajPsaDialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 230, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(DodajPsaDialog);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 10, 351, 211));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::SpanningRole, label);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        lineEditId = new QLineEdit(formLayoutWidget);
        lineEditId->setObjectName(QStringLiteral("lineEditId"));

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditId);

        label_7 = new QLabel(formLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        lineEditImie = new QLineEdit(formLayoutWidget);
        lineEditImie->setObjectName(QStringLiteral("lineEditImie"));

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditImie);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_3);

        lineEditWiek = new QLineEdit(formLayoutWidget);
        lineEditWiek->setObjectName(QStringLiteral("lineEditWiek"));

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditWiek);

        label_4 = new QLabel(formLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        formLayout->setWidget(5, QFormLayout::LabelRole, label_4);

        lineEditRasa = new QLineEdit(formLayoutWidget);
        lineEditRasa->setObjectName(QStringLiteral("lineEditRasa"));

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditRasa);

        label_5 = new QLabel(formLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        formLayout->setWidget(6, QFormLayout::LabelRole, label_5);

        lineEditRodzaj = new QLineEdit(formLayoutWidget);
        lineEditRodzaj->setObjectName(QStringLiteral("lineEditRodzaj"));

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEditRodzaj);


        retranslateUi(DodajPsaDialog);

        QMetaObject::connectSlotsByName(DodajPsaDialog);
    } // setupUi

    void retranslateUi(QDialog *DodajPsaDialog)
    {
        DodajPsaDialog->setWindowTitle(QApplication::translate("DodajPsaDialog", "Dialog", 0));
        label->setText(QApplication::translate("DodajPsaDialog", "<html><head/><body><p align=\"center\"><span style=\" font-size:14pt; font-weight:600; color:#8525d0;\">Formularz Dodaj Psa</span></p></body></html>", 0));
        label_2->setText(QApplication::translate("DodajPsaDialog", "Numer ID:                             ", 0));
        label_7->setText(QApplication::translate("DodajPsaDialog", "Imie :                           ", 0));
        label_3->setText(QApplication::translate("DodajPsaDialog", "Wiek:", 0));
        label_4->setText(QApplication::translate("DodajPsaDialog", "Rasa:", 0));
        label_5->setText(QApplication::translate("DodajPsaDialog", "Rodzaj:", 0));
    } // retranslateUi

};

namespace Ui {
    class DodajPsaDialog: public Ui_DodajPsaDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DODAJPSADIALOG_H
