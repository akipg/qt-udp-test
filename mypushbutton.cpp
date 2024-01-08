#include "mypushbutton.h"

MyPushButton::MyPushButton(QWidget *parent)
    : QWidget{parent}
{
    sendUdpSocket = new  QUdpSocket(this);
    recvUdpSocket = new  QUdpSocket(this);

    recvUdpSocket->bind(1234, QUdpSocket::DefaultForPlatform);
    connect(recvUdpSocket, &QUdpSocket::readyRead, this, &MyPushButton::readPendingDatagram);

    button = new QPushButton("Hello", parent);
    connect(button, &QPushButton::clicked, this, &MyPushButton::on_button_pushed);
    button->move(100, 200);
    button->show();


    label = new QLabel(parent);
    label->move(100, 250);
    label->setText("hey!");
    label->show();


}


MyPushButton::~MyPushButton()
{
    delete button;
}

void MyPushButton::readPendingDatagram()
{
    label->setText("received!!");
}

void MyPushButton::on_button_pushed()
{
    label->setText("pushed!");
    QByteArray datagram;
    QDataStream msg(&datagram, QIODevice::WriteOnly);
    msg << "1234567";

//    auto ret = sendUdpSocket->writeDatagram(datagram, QHostAddress::LocalHost, 1234);
//    auto ret = sendUdpSocket->writeDatagram(datagram, QHostAddress("127.0.0.1"), 1234);
    auto ret = sendUdpSocket->writeDatagram(datagram, QHostAddress("10.0.2.2"), 1234);
    label->setText(QString::number(ret));
}
