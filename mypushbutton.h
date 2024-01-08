#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QUdpSocket>

class MyPushButton : public QWidget
{
    Q_OBJECT
public:
    explicit MyPushButton(QWidget *parent = nullptr);
    virtual ~MyPushButton();

    void readPendingDatagram();

private:
    QPushButton *button;
    QLabel *label;

    QUdpSocket *sendUdpSocket;
    QUdpSocket *recvUdpSocket;

    void on_button_pushed();

signals:

};

#endif // MYPUSHBUTTON_H
