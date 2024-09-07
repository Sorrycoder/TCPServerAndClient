#include "widget.h"
#include "ui_widget.h"

#include <QMessageBox>
#include <QNetworkInterface>
#include<QTcpSocket>
#include<QList>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    ui->btnStopListen->setEnabled(false);
    ui->btnOverListen->setEnabled(false);
    ui->btnSend->setEnabled(false);
    server=new QTcpServer(this);

    //点击comboBox的时候，刷新内容
    connect(ui->comboBoxChild,&MycomboBox::on_comboBox_clicked,this,&Widget::mComboBox_refresh);

    connect(server,&QTcpServer::newConnection,this,&Widget::on_newClient_connect);

    //获取所有的IP地址刷新到ui里，更方便
    QList<QHostAddress> addresss=QNetworkInterface::allAddresses();
    for(QHostAddress temp:addresss){
        //遍历获得的IP地址，设置只需要ipv4的满足
        if(temp.protocol()==QAbstractSocket::IPv4Protocol){
            ui->comboBoxAddr->addItem(temp.toString());
        }
    }



}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_newClient_connect()
{

    if(server->hasPendingConnections()){

        QTcpSocket *connection=server->nextPendingConnection();
        qDebug()<<"client addr:"<<connection->peerAddress().toString()<<"port:"<<connection->peerPort();
        ui->editRev->insertPlainText("客户端地址:"+connection->peerAddress().toString()+
                                     " 客户端端口号:"+QString::number(connection->peerPort())+"\n");

        //信号到来时触发readyread，进行读取数据
        connect(connection,&QTcpSocket::readyRead,this,&Widget::on_readyReadHandle);




        connect(connection,&QTcpSocket::stateChanged,this,&Widget::mstateChanged);

        //每当一个新的连接进入，自动加入comboBox，设置为当前项
        ui->comboBoxChild->addItem(QString::number(connection->peerPort()));
        ui->comboBoxChild->setCurrentText(QString::number(connection->peerPort()));

        if(!ui->btnSend->isEnabled()){
            ui->btnSend->setEnabled(true);
        }
    }

}

void Widget::on_readyReadHandle()
{
    //这行代码使用 qobject_cast 将 QObject 指针转换为 QTcpSocket 指针。
    //sender() 函数返回发出信号的对象，这里假设该信号是由 QTcpSocket 发出的。qobject_cast 确保类型安全。
    QTcpSocket *temsocket=qobject_cast<QTcpSocket *>(sender());//获得发出信号的对象，转成QTcpSocket
    QByteArray revData=temsocket->readAll();//读取QTcpSocket信号的信息
    ui->editRev->insertPlainText("客户端："+revData);//更新到ui
    ui->editRev->moveCursor(QTextCursor::End);
    ui->editRev->ensureCursorVisible();
}



void Widget::mComboBox_refresh()//把已连接的TCPsocket的端口号刷新到自己定义的comboBox上
{
    ui->comboBoxChild->clear();//每次添加前先去掉旧的，防止重复
    QList<QTcpSocket*> tcpSocketClients= server->findChildren<QTcpSocket*>();//获取已连接的 QTcpSocket 对象

    for(QTcpSocket* temp:tcpSocketClients){
        if(temp!=nullptr)//
            //if(temp->peerPort()!=0)//如果关掉客户端，还是会作为child存在QList里，这样写comboBox里确实没0，不代表可以去掉child里的0，在单独发的时候发不出去，最好不存在0
            ui->comboBoxChild->addItem(QString::number( temp->peerPort()));//遍历，将已连接的端口号显示在comboBox上
    }
    ui->comboBoxChild->addItem("all");//再加一个all
}

void Widget::mstateChanged(QAbstractSocket::SocketState socketState)
{
    int tmpIndex;
    qDebug()<<"clientStatue:"<<socketState;
    QTcpSocket *temsocket=qobject_cast<QTcpSocket *>(sender());
    switch(socketState){
    case QAbstractSocket::UnconnectedState:
        ui->editRev->insertPlainText("客户端断开!\n");
        //断开的时候自动删掉port
        tmpIndex=ui->comboBoxChild->findText(QString::number( temsocket->peerPort()));
        ui->comboBoxChild->removeItem(tmpIndex);

        temsocket->deleteLater();//释放，在list里不存在，防止干扰
        if(ui->comboBoxChild->count()==1)//如果没有一个连接
            ui->btnSend->setEnabled(false);
        break;
    case QAbstractSocket::ConnectingState:
    case QAbstractSocket::ConnectedState:
        //这里没用
        ui->editRev->insertPlainText("客户端接入!");
        break;
    }
}


void Widget::on_btnStartListen_clicked()
{

    int port=ui->lineEditPort->text().toInt();

    if(!server->listen(QHostAddress(ui->comboBoxAddr->currentText()),port)){//端口号设置为界面的
        QMessageBox msgBox;
        msgBox.setWindowTitle("监听失败");
        msgBox.setText("端口号被占用.");
        msgBox.exec();
        return;
    }

    //到这里表示如果监听成功
    ui->btnStartListen->setEnabled(false);
    ui->btnStopListen->setEnabled(true);
    ui->btnOverListen->setEnabled(true);

    ui->comboBoxProt->setEnabled(false);
    ui->comboBoxAddr->setEnabled(false);
    ui->lineEditPort->setEnabled(false);



}


//为了精准控制信息发给谁，先定义一个comboBox显示端口，原comboBox无点击设置的功能，自己定义一个，重写按键，按下mousepress，发出一个on_comboBox_clicked信号
//发出信号又可以触发一个新的槽函数mComboBox_refresh，把以连接的TCPsocket的端口号刷新到comboBox上，
//当选择comboBox上某个index即端口号时，把所选择的index传给全局变量childIndex，当childIndex为all，遍历给所有发，否则根据index只给特定的发
void Widget::on_btnSend_clicked()
{
    //qDebug()<<childIndex;


    //每当有connect接入时，都会成为server的child，找出放到列表里
    QList<QTcpSocket*> tcpSocketClients= server->findChildren<QTcpSocket*>();
    if(tcpSocketClients.isEmpty()){

        QMessageBox msgBox;
        msgBox.setWindowTitle("发送失败");
        msgBox.setText("当前无连接");
        msgBox.exec();
        ui->btnSend->setEnabled(false);
        return;
    }
    if(ui->comboBoxChild->currentText()!="all"){
        //child和comboBox的索因可能不一致，用comboBox的当前文本判断，哪个客户端的端口号和ui上一致，给谁发
        QString currentName=ui->comboBoxChild->currentText();
        for(QTcpSocket* tmp:tcpSocketClients){//
            if(QString::number(tmp->peerPort())==currentName){
                tmp->write("服务端："+ui->editSend->toPlainText().toUtf8()+"\n");
            }
        }
        //tcpSocketClients[childIndex]->write(ui->editSend->toPlainText().toUtf8()+"\n");//不通过child，会不一致
    }else{
        for(QTcpSocket* temp:tcpSocketClients){
            temp->write(ui->editSend->toPlainText().toUtf8()+"\n");
        }
    }
}


// void Widget::on_comboBoxChild_activated(int index)
// {
//     //childIndex=index;//表示这个combobox哪一个激活，送给childIndex，让其他地方用
//     //也没用了，不用childIndex
// }


void Widget::on_btnStopListen_clicked()//停止监听，server关闭
{
    QList<QTcpSocket*> tcpSocketClients= server->findChildren<QTcpSocket*>();
    for(QTcpSocket* temp:tcpSocketClients){
        temp->close();
    }
    server->close();
    ui->btnStartListen->setEnabled(true);
    ui->btnStopListen->setEnabled(false);
    ui->btnOverListen->setEnabled(false);

    ui->comboBoxProt->setEnabled(true);
    ui->comboBoxAddr->setEnabled(true);
    ui->lineEditPort->setEnabled(true);
}


void Widget::on_btnOverListen_clicked()//断开
{
    on_btnStopListen_clicked();
    server->deleteLater();
    this->close();
}

