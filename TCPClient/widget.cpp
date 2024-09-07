#include "widget.h"
#include "ui_widget.h"
#include<QNetworkInterface>
#include <QTimer>
#include <qmessagebox.h>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->btnDiscon->setEnabled(false);
    ui->btnSend->setEnabled(false);
    client=new QTcpSocket(this);

    connect(client,&QTcpSocket::readyRead,this,&Widget::mRead_Data_From_Server);


}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_btnConncet_clicked()
{
    disconnect(client, &QTcpSocket::connected, this, nullptr);
    client->connectToHost(ui->lineEdit_IP->text(),ui->editPort->text().toInt());
    time=new QTimer(this);
    time->setSingleShot(true);
    time->setInterval(5000);


    connect(time,&QTimer::timeout,this,[=](){//超时
        ui->editRev->insertPlainText("连接超时："+client->errorString());
        client->abort();//取消
        this->setEnabled(true);
    });

    connect(client,&QTcpSocket::connected,this,[=](){//连接成功
        time->stop();
        this->setEnabled(true);
        ui->editRev->append("连接成功\n");
        ui->btnSend->setEnabled(true);
        ui->btnConncet->setEnabled(false);
        ui->editPort->setEnabled(false);
        ui->lineEdit_IP->setEnabled(false);
        ui->btnDiscon->setEnabled(true);


    });

    connect(client,&QTcpSocket::errorOccurred,this,[=](QAbstractSocket::SocketError error){
        qDebug()<<"错误"<<error;
        ui->editRev->insertPlainText("连接出问题了："+client->errorString());
        this->setEnabled(true);
        on_btnDiscon_clicked();
    });
    this->setEnabled(false);
    time->start();
}

void Widget::mRead_Data_From_Server()
{
    ui->editRev->moveCursor(QTextCursor::End);//插入光标结尾
    ui->editRev->ensureCursorVisible();
    mInsertTextByColor(Qt::black,client->readAll());

}


void Widget::on_btnSend_clicked()
{
    QByteArray sendData=ui->editSend->toPlainText().toUtf8()+"\n";
    client->write(sendData);
    mInsertTextByColor(Qt::red,"客户端："+sendData);

}


void Widget::on_btnDiscon_clicked()
{
    client->disconnectFromHost();
    client->close();
    ui->editRev->append("断开连接\n");
    ui->btnSend->setEnabled(false);
    ui->btnConncet->setEnabled(true);
    ui->editPort->setEnabled(true);
    ui->lineEdit_IP->setEnabled(true);
    ui->btnDiscon->setEnabled(false);

}


void Widget::mInsertTextByColor(Qt::GlobalColor color,QString str)//在editRev上光标处插入文本，设置文本格式
{
    //获取在editRev上的文本光标
    QTextCursor cursor= ui->editRev->textCursor();

    //获取设置文本的格式，设置前景色即文字颜色为color色
    QTextCharFormat format;
    format.setForeground(QBrush(QColor(color)));

    //光标处插入的文字设置颜色为弄好的格式
    cursor.setCharFormat(format);

    cursor.insertText(str);
}




