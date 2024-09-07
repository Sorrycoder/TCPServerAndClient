#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include<QTcpSocket>
#include <QTimer>
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

private slots:
    void on_btnConncet_clicked();
    void mRead_Data_From_Server();

    void on_btnSend_clicked();

    void on_btnDiscon_clicked();





private:
    Ui::Widget *ui;

    QTcpSocket *client;

    QTimer *time;

    void mInsertTextByColor(Qt::GlobalColor color,QString str);

};
#endif // WIDGET_H
