/********************************************************************************
** Form generated from reading UI file 'ip_url.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IP_URL_H
#define UI_IP_URL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Ip_url
{
public:
    QLineEdit *lineEdit;
    QLabel *label;
    QPushButton *pushButton;

    void setupUi(QDialog *Ip_url)
    {
        if (Ip_url->objectName().isEmpty())
            Ip_url->setObjectName(QString::fromUtf8("Ip_url"));
        Ip_url->resize(344, 129);
        lineEdit = new QLineEdit(Ip_url);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(110, 30, 211, 31));
        label = new QLabel(Ip_url);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 30, 71, 31));
        QFont font;
        font.setPointSize(20);
        label->setFont(font);
        pushButton = new QPushButton(Ip_url);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(240, 90, 80, 24));

        retranslateUi(Ip_url);

        QMetaObject::connectSlotsByName(Ip_url);
    } // setupUi

    void retranslateUi(QDialog *Ip_url)
    {
        Ip_url->setWindowTitle(QApplication::translate("Ip_url", "Ip url", nullptr));
        label->setText(QApplication::translate("Ip_url", "Ip url: ", nullptr));
        pushButton->setText(QApplication::translate("Ip_url", "Ok", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Ip_url: public Ui_Ip_url {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IP_URL_H
