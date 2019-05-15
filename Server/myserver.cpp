#include "myserver.h"
#include <sstream>
#include <QDebug>
#include <QObject>
#include <QUdpSocket>
#include <iostream>
#include <number.h>
#include <QDataStream>
#include "windows.h"
using namespace std;

myserver::myserver(QObject *parent) :
    QObject(parent)
{
    socket = new QUdpSocket(this);
    socketRecive = new QUdpSocket(this);
    socketRecive->bind(QHostAddress::LocalHost, 5555);
    connect(socketRecive, SIGNAL(readyRead()), this, SLOT(sockReady()));
}

void myserver::sockReady()
{
    while(socketRecive->hasPendingDatagrams())
    {
        QByteArray Data;
        double ar = 0;
        double ai = 0;
        double br = 0;
        double bi = 0;
        double cr = 0;
        double ci = 0;
        double xr = 0;
        double xi = 0;
        Data.resize(socketRecive->pendingDatagramSize());
        QHostAddress adress;
        quint16 senderPort;
        socketRecive->readDatagram(Data.data(), Data.size(), &adress, &senderPort);
        QDataStream in(&Data, QIODevice::ReadOnly);
        in >> ar >> ai >> br >> bi >> cr >> ci >> xr >> xi;
        a =  TComplex(ar,ai);
        b =  TComplex(br,bi);
        c =  TComplex(cr,ci);
        x =  TComplex(xr,xi);
        send();
    }
}
void myserver::send()
{
    number *rs = new number[2];
    polinom.a = a;
    polinom.b = b;
    polinom.c = c;
    cout << polinom << endl;
    int n = polinom.roots(rs);
    res = polinom.value(x);
    cout << "1 root: " << rs[0] << endl << "2 root: " << rs[1] << endl;
    cout << "Value: " << res << endl;
    QByteArray data;
    data.resize(socket->pendingDatagramSize());
    QDataStream out(&data, QIODevice::WriteOnly);
    double a1, b1, c1, d1, e1, f1;
    a1 = rs[0].re;
    b1 = rs[0].im;
    c1 = rs[1].re;
    d1 = rs[1].im;
    e1 = res.re;
    f1 = res.im;
    out << qreal(a1);
    out << qreal(b1);
    out << qreal(c1);
    out << qreal(d1);
    out << qreal(e1);
    out << qreal(f1);
    socket->writeDatagram(data, QHostAddress::LocalHost, 5554);
}

void myserver::sockDisc()
{
    qDebug() << "Disconnect";
    socket->deleteLater();
}
