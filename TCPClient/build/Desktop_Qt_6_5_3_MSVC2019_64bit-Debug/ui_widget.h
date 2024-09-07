/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QTextEdit *editRev;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit_IP;
    QLabel *label_2;
    QLineEdit *editPort;
    QVBoxLayout *verticalLayout;
    QPushButton *btnConncet;
    QPushButton *btnDiscon;
    QHBoxLayout *horizontalLayout;
    QTextEdit *editSend;
    QPushButton *btnSend;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(439, 524);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        editRev = new QTextEdit(Widget);
        editRev->setObjectName("editRev");

        verticalLayout_2->addWidget(editRev);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(20);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalLayout_2->setContentsMargins(10, 10, 10, 10);
        label = new QLabel(Widget);
        label->setObjectName("label");

        horizontalLayout_2->addWidget(label);

        lineEdit_IP = new QLineEdit(Widget);
        lineEdit_IP->setObjectName("lineEdit_IP");
        lineEdit_IP->setMinimumSize(QSize(80, 0));

        horizontalLayout_2->addWidget(lineEdit_IP);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");

        horizontalLayout_2->addWidget(label_2);

        editPort = new QLineEdit(Widget);
        editPort->setObjectName("editPort");
        editPort->setMinimumSize(QSize(37, 0));

        horizontalLayout_2->addWidget(editPort);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        btnConncet = new QPushButton(Widget);
        btnConncet->setObjectName("btnConncet");

        verticalLayout->addWidget(btnConncet);

        btnDiscon = new QPushButton(Widget);
        btnDiscon->setObjectName("btnDiscon");

        verticalLayout->addWidget(btnDiscon);


        horizontalLayout_2->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        editSend = new QTextEdit(Widget);
        editSend->setObjectName("editSend");

        horizontalLayout->addWidget(editSend);

        btnSend = new QPushButton(Widget);
        btnSend->setObjectName("btnSend");
        btnSend->setMinimumSize(QSize(50, 60));

        horizontalLayout->addWidget(btnSend);


        verticalLayout_2->addLayout(horizontalLayout);

        verticalLayout_2->setStretch(0, 5);
        verticalLayout_2->setStretch(1, 1);
        verticalLayout_2->setStretch(2, 1);

        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\347\275\221\347\273\234\350\260\203\350\257\225\345\212\251\346\211\213\345\256\242\346\210\267\347\253\257", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\347\253\257IP", nullptr));
        lineEdit_IP->setText(QCoreApplication::translate("Widget", "172.26.144.1", nullptr));
        label_2->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\347\253\257\347\253\257\345\217\243", nullptr));
        editPort->setText(QCoreApplication::translate("Widget", "8888", nullptr));
        btnConncet->setText(QCoreApplication::translate("Widget", "\350\277\236\346\216\245", nullptr));
        btnDiscon->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200", nullptr));
        btnSend->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
