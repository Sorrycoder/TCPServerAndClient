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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "mycombobox.h"

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QPlainTextEdit *editRev;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QLabel *label;
    QComboBox *comboBoxProt;
    QLabel *label_2;
    QComboBox *comboBoxAddr;
    QLabel *label_3;
    QLineEdit *lineEditPort;
    QSpacerItem *horizontalSpacer_2;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnStartListen;
    QPushButton *btnStopListen;
    QPushButton *btnOverListen;
    MycomboBox *comboBoxChild;
    QHBoxLayout *horizontalLayout_3;
    QPlainTextEdit *editSend;
    QPushButton *btnSend;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(606, 475);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        editRev = new QPlainTextEdit(Widget);
        editRev->setObjectName("editRev");

        verticalLayout->addWidget(editRev);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label = new QLabel(Widget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(11);
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBoxProt = new QComboBox(Widget);
        comboBoxProt->addItem(QString());
        comboBoxProt->addItem(QString());
        comboBoxProt->setObjectName("comboBoxProt");

        horizontalLayout->addWidget(comboBoxProt);

        label_2 = new QLabel(Widget);
        label_2->setObjectName("label_2");
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        comboBoxAddr = new QComboBox(Widget);
        comboBoxAddr->setObjectName("comboBoxAddr");

        horizontalLayout->addWidget(comboBoxAddr);

        label_3 = new QLabel(Widget);
        label_3->setObjectName("label_3");
        label_3->setFont(font);

        horizontalLayout->addWidget(label_3);

        lineEditPort = new QLineEdit(Widget);
        lineEditPort->setObjectName("lineEditPort");

        horizontalLayout->addWidget(lineEditPort);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        horizontalLayout->setStretch(2, 1);
        horizontalLayout->setStretch(4, 2);
        horizontalLayout->setStretch(6, 1);

        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnStartListen = new QPushButton(Widget);
        btnStartListen->setObjectName("btnStartListen");
        btnStartListen->setEnabled(true);

        horizontalLayout_2->addWidget(btnStartListen);

        btnStopListen = new QPushButton(Widget);
        btnStopListen->setObjectName("btnStopListen");
        btnStopListen->setEnabled(false);

        horizontalLayout_2->addWidget(btnStopListen);

        btnOverListen = new QPushButton(Widget);
        btnOverListen->setObjectName("btnOverListen");
        btnOverListen->setEnabled(false);

        horizontalLayout_2->addWidget(btnOverListen);


        verticalLayout->addLayout(horizontalLayout_2);

        comboBoxChild = new MycomboBox(Widget);
        comboBoxChild->setObjectName("comboBoxChild");

        verticalLayout->addWidget(comboBoxChild);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        editSend = new QPlainTextEdit(Widget);
        editSend->setObjectName("editSend");

        horizontalLayout_3->addWidget(editSend);

        btnSend = new QPushButton(Widget);
        btnSend->setObjectName("btnSend");
        btnSend->setMinimumSize(QSize(50, 80));

        horizontalLayout_3->addWidget(btnSend);


        verticalLayout->addLayout(horizontalLayout_3);

        verticalLayout->setStretch(0, 7);
        verticalLayout->setStretch(1, 1);
        verticalLayout->setStretch(2, 1);
        verticalLayout->setStretch(4, 2);

        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "\347\275\221\347\273\234\350\260\203\350\257\225\345\212\251\346\211\213\346\234\215\345\212\241\347\253\257", nullptr));
        label->setText(QCoreApplication::translate("Widget", "\351\200\232\344\277\241\345\215\217\350\256\256", nullptr));
        comboBoxProt->setItemText(0, QCoreApplication::translate("Widget", "TCP", nullptr));
        comboBoxProt->setItemText(1, QCoreApplication::translate("Widget", "UDP", nullptr));

        label_2->setText(QCoreApplication::translate("Widget", "\346\234\215\345\212\241\345\231\250IP\345\234\260\345\235\200", nullptr));
        label_3->setText(QCoreApplication::translate("Widget", "\347\253\257\345\217\243\345\217\267", nullptr));
        lineEditPort->setText(QCoreApplication::translate("Widget", "8888", nullptr));
        btnStartListen->setText(QCoreApplication::translate("Widget", "\345\274\200\345\247\213\347\233\221\345\220\254", nullptr));
        btnStopListen->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242\347\233\221\345\220\254", nullptr));
        btnOverListen->setText(QCoreApplication::translate("Widget", "\346\226\255\345\274\200", nullptr));
        btnSend->setText(QCoreApplication::translate("Widget", "\345\217\221\351\200\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
