#ifndef MYSERVER_H
#define MYSERVER_H
#include <QTcpServer>
#include <QUdpSocket>
#include "complex.h"
#include "polinom.h"
class myserver: public QObject
{
    Q_OBJECT
private :
    TPolinom polinom;
    void send();
public:
    explicit myserver(QObject *parent = 0);
    number a, b, c, x, res;
    QUdpSocket *socket;
    QUdpSocket *socketRecive;
public slots:
    void sockReady();
    void sockDisc();
};
#endif // MYSERVER_H
