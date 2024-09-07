#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpServer>
#include<QHostAddress>
#include<QTcpSocket>
#include"mycombobox.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
    //int childIndex=0;


public:
    QTcpServer *server;

public slots:
    void on_newClient_connect();

    void on_readyReadHandle();


    void mstateChanged(QAbstractSocket::SocketState socketState);

    void mComboBox_refresh();
private slots:
    void on_btnStartListen_clicked();



    void on_btnSend_clicked();
    //void on_comboBoxChild_activated(int index);
    void on_btnStopListen_clicked();
    void on_btnOverListen_clicked();
};
#endif // WIDGET_H
