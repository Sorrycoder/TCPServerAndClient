#ifndef MYCOMBOBOX_H
#define MYCOMBOBOX_H

#include <QComboBox>
#include <QWidget>

class MycomboBox : public QComboBox
{
    Q_OBJECT
public:
    MycomboBox(QWidget *parent);

protected:


    // QWidget interface
protected:
    virtual void mousePressEvent(QMouseEvent *event) override;
signals:
    void on_comboBox_clicked();
};



#endif // MYCOMBOBOX_H
