/********************************************************************************
** Form generated from reading UI file 'disk_scheduling.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISK_SCHEDULING_H
#define UI_DISK_SCHEDULING_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_disk_schedulingClass
{
public:
    QWidget *centralWidget;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QLineEdit *lineEdit;
    QLabel *label;
    QTableWidget *tableWidget_2;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QPushButton *pushButton_8;
    QLineEdit *lineEdit_2;
    QLabel *label_10;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *disk_schedulingClass)
    {
        if (disk_schedulingClass->objectName().isEmpty())
            disk_schedulingClass->setObjectName(QStringLiteral("disk_schedulingClass"));
        disk_schedulingClass->resize(680, 485);
        centralWidget = new QWidget(disk_schedulingClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tableWidget = new QTableWidget(centralWidget);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(150, 40, 191, 411));
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(360, 360, 141, 41));
        pushButton_2 = new QPushButton(centralWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(510, 360, 141, 41));
        pushButton_3 = new QPushButton(centralWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(360, 410, 141, 41));
        pushButton_4 = new QPushButton(centralWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(510, 410, 141, 41));
        pushButton_5 = new QPushButton(centralWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));
        pushButton_5->setGeometry(QRect(530, 60, 61, 28));
        radioButton = new QRadioButton(centralWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setGeometry(QRect(400, 225, 93, 28));
        radioButton_2 = new QRadioButton(centralWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));
        radioButton_2->setGeometry(QRect(520, 225, 93, 28));
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(410, 55, 101, 31));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(360, 185, 111, 31));
        tableWidget_2 = new QTableWidget(centralWidget);
        tableWidget_2->setObjectName(QStringLiteral("tableWidget_2"));
        tableWidget_2->setGeometry(QRect(20, 40, 111, 411));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(360, 285, 101, 16));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(370, 325, 72, 15));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(360, 25, 101, 16));
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 20, 72, 15));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(190, 20, 72, 15));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(460, 285, 71, 16));
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(360, 115, 111, 16));
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(480, 115, 72, 15));
        pushButton_8 = new QPushButton(centralWidget);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));
        pushButton_8->setGeometry(QRect(530, 145, 71, 28));
        lineEdit_2 = new QLineEdit(centralWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(410, 145, 101, 31));
        label_10 = new QLabel(centralWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(480, 190, 81, 21));
        pushButton_6 = new QPushButton(centralWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));
        pushButton_6->setGeometry(QRect(530, 20, 131, 31));
        pushButton_7 = new QPushButton(centralWidget);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(600, 60, 61, 28));
        disk_schedulingClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(disk_schedulingClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        disk_schedulingClass->setStatusBar(statusBar);

        retranslateUi(disk_schedulingClass);

        QMetaObject::connectSlotsByName(disk_schedulingClass);
    } // setupUi

    void retranslateUi(QMainWindow *disk_schedulingClass)
    {
        disk_schedulingClass->setWindowTitle(QApplication::translate("disk_schedulingClass", "disk_scheduling", 0));
        pushButton->setText(QApplication::translate("disk_schedulingClass", "\345\205\210\346\235\245\345\205\210\346\234\215\345\212\241(FCFS)", 0));
        pushButton_2->setText(QApplication::translate("disk_schedulingClass", "\346\234\200\347\237\255\345\257\273\351\201\223\346\227\266\351\227\264\344\274\230\345\205\210", 0));
        pushButton_3->setText(QApplication::translate("disk_schedulingClass", "\346\211\253\346\217\217\347\256\227\346\263\225(SCAN)", 0));
        pushButton_4->setText(QApplication::translate("disk_schedulingClass", "\345\276\252\347\216\257\347\256\227\346\263\225(CSCAN)", 0));
        pushButton_5->setText(QApplication::translate("disk_schedulingClass", "\346\217\222\345\205\245", 0));
        radioButton->setText(QApplication::translate("disk_schedulingClass", "\344\273\216\351\207\214\345\210\260\345\244\226", 0));
        radioButton_2->setText(QApplication::translate("disk_schedulingClass", "\344\273\216\345\244\226\345\210\260\351\207\214", 0));
        label->setText(QApplication::translate("disk_schedulingClass", "\347\243\201\345\244\264\345\275\223\345\211\215\346\226\271\345\220\221:", 0));
        label_2->setText(QApplication::translate("disk_schedulingClass", "\345\271\263\345\235\207\345\257\273\351\201\223\346\225\260:", 0));
        label_3->setText(QApplication::translate("disk_schedulingClass", "\350\260\203\345\272\246\347\256\227\346\263\225:", 0));
        label_4->setText(QApplication::translate("disk_schedulingClass", "\346\217\222\345\205\245\350\256\277\351\227\256\345\272\217\345\210\227:", 0));
        label_5->setText(QApplication::translate("disk_schedulingClass", "\350\256\277\351\227\256\351\241\272\345\272\217", 0));
        label_6->setText(QApplication::translate("disk_schedulingClass", "\350\260\203\345\272\246\347\273\223\346\236\234", 0));
        label_7->setText(QString());
        label_8->setText(QApplication::translate("disk_schedulingClass", "\346\234\200\345\205\210\350\256\277\351\227\256\347\243\201\351\201\223\357\274\232", 0));
        label_9->setText(QString());
        pushButton_8->setText(QApplication::translate("disk_schedulingClass", "\346\233\264\346\224\271", 0));
        label_10->setText(QString());
        pushButton_6->setText(QApplication::translate("disk_schedulingClass", "\351\232\217\346\234\272\347\224\237\346\210\220", 0));
        pushButton_7->setText(QApplication::translate("disk_schedulingClass", "\346\270\205\347\251\272", 0));
    } // retranslateUi

};

namespace Ui {
    class disk_schedulingClass: public Ui_disk_schedulingClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISK_SCHEDULING_H
