/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.11
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QLabel *label;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QComboBox *comboBox_3;
    QLabel *resultLabel;
    QLabel *nameLabel;
    QLabel *balanceLabel;
    QLabel *statusLabel;
    QLabel *inDateLabel;
    QLabel *outDateLabel;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(922, 517);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(692, 200, 141, 35));
        QFont font;
        font.setPointSize(12);
        pushButton->setFont(font);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(-1, -1, 661, 511));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(690, 60, 91, 31));
        pushButton_3->setFont(font);
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(690, 100, 101, 71));
        pushButton_2->setFont(font);
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));
        pushButton_5->setGeometry(QRect(690, 20, 201, 31));
        pushButton_5->setFont(font);
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));
        pushButton_6->setGeometry(QRect(790, 60, 101, 31));
        pushButton_6->setFont(font);
        comboBox = new QComboBox(centralwidget);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(830, 200, 71, 35));
        comboBox->setFont(font);
        comboBox_2 = new QComboBox(centralwidget);
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->addItem(QString());
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(800, 140, 101, 35));
        comboBox_2->setFont(font);
        comboBox_3 = new QComboBox(centralwidget);
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->addItem(QString());
        comboBox_3->setObjectName(QString::fromUtf8("comboBox_3"));
        comboBox_3->setGeometry(QRect(800, 100, 101, 35));
        comboBox_3->setFont(font);
        resultLabel = new QLabel(centralwidget);
        resultLabel->setObjectName(QString::fromUtf8("resultLabel"));
        resultLabel->setGeometry(QRect(690, 250, 211, 61));
        QFont font1;
        font1.setPointSize(14);
        resultLabel->setFont(font1);
        resultLabel->setStyleSheet(QString::fromUtf8(".QLabel{\n"
"background:blue;\n"
"color:white;\n"
"border-radius:5px;\n"
"}"));
        nameLabel = new QLabel(centralwidget);
        nameLabel->setObjectName(QString::fromUtf8("nameLabel"));
        nameLabel->setGeometry(QRect(690, 320, 211, 31));
        nameLabel->setFont(font1);
        nameLabel->setStyleSheet(QString::fromUtf8("#resultLabel {\n"
"background:blue;\n"
"color:white;\n"
"border-radius:5px;\n"
"}"));
        balanceLabel = new QLabel(centralwidget);
        balanceLabel->setObjectName(QString::fromUtf8("balanceLabel"));
        balanceLabel->setGeometry(QRect(690, 350, 211, 31));
        balanceLabel->setFont(font1);
        balanceLabel->setStyleSheet(QString::fromUtf8("#resultLabel {\n"
"background:blue;\n"
"color:white;\n"
"border-radius:5px;\n"
"}"));
        statusLabel = new QLabel(centralwidget);
        statusLabel->setObjectName(QString::fromUtf8("statusLabel"));
        statusLabel->setGeometry(QRect(690, 380, 211, 31));
        statusLabel->setFont(font1);
        statusLabel->setStyleSheet(QString::fromUtf8("#resultLabel {\n"
"background:blue;\n"
"color:white;\n"
"border-radius:5px;\n"
"}"));
        inDateLabel = new QLabel(centralwidget);
        inDateLabel->setObjectName(QString::fromUtf8("inDateLabel"));
        inDateLabel->setGeometry(QRect(690, 410, 211, 31));
        inDateLabel->setFont(font1);
        inDateLabel->setStyleSheet(QString::fromUtf8("#resultLabel {\n"
"background:blue;\n"
"color:white;\n"
"border-radius:5px;\n"
"}"));
        outDateLabel = new QLabel(centralwidget);
        outDateLabel->setObjectName(QString::fromUtf8("outDateLabel"));
        outDateLabel->setGeometry(QRect(690, 440, 211, 31));
        outDateLabel->setFont(font1);
        outDateLabel->setStyleSheet(QString::fromUtf8("#resultLabel {\n"
"background:blue;\n"
"color:white;\n"
"border-radius:5px;\n"
"}"));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Camera", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "\350\257\206\345\210\253", nullptr));
        label->setText(QString());
        pushButton_3->setText(QApplication::translate("MainWindow", "Light", nullptr));
        pushButton_2->setText(QApplication::translate("MainWindow", "Video", nullptr));
        pushButton_5->setText(QApplication::translate("MainWindow", "\350\267\257\345\276\204", nullptr));
        pushButton_6->setText(QApplication::translate("MainWindow", "Local", nullptr));
        comboBox->setItemText(0, QApplication::translate("MainWindow", ".png", nullptr));
        comboBox->setItemText(1, QApplication::translate("MainWindow", ".jpg", nullptr));
        comboBox->setItemText(2, QApplication::translate("MainWindow", ".jpeg", nullptr));

        comboBox_2->setItemText(0, QApplication::translate("MainWindow", ".mp4", nullptr));
        comboBox_2->setItemText(1, QApplication::translate("MainWindow", ".avi", nullptr));
        comboBox_2->setItemText(2, QApplication::translate("MainWindow", ".mov", nullptr));

        comboBox_3->setItemText(0, QApplication::translate("MainWindow", "default FPS", nullptr));
        comboBox_3->setItemText(1, QApplication::translate("MainWindow", "60 FPS", nullptr));
        comboBox_3->setItemText(2, QApplication::translate("MainWindow", "30 FPS", nullptr));

        resultLabel->setText(QApplication::translate("MainWindow", "\347\273\223\346\236\234\357\274\232", nullptr));
        nameLabel->setText(QApplication::translate("MainWindow", "\350\275\246\344\270\273\357\274\232", nullptr));
        balanceLabel->setText(QApplication::translate("MainWindow", "\344\275\231\351\242\235\357\274\232", nullptr));
        statusLabel->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\357\274\232", nullptr));
        inDateLabel->setText(QApplication::translate("MainWindow", "\345\205\245\345\272\223\346\227\266\351\227\264\357\274\232", nullptr));
        outDateLabel->setText(QApplication::translate("MainWindow", "\345\207\272\345\272\223\346\227\266\351\227\264\357\274\232", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
