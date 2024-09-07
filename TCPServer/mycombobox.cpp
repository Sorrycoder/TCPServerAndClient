#include "mycombobox.h"

#include <QMouseEvent>



MycomboBox::MycomboBox(QWidget *parent):QComboBox(parent)
{

}

void MycomboBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button()==Qt::LeftButton){
        emit on_comboBox_clicked();
    }
    QComboBox::mousePressEvent(event);//调用基类 QComboBox 的 mousePressEvent 方法，确保 QComboBox 的默认行为仍然生效。
}
