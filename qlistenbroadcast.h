#ifndef QLISTENBROADCAST_H
#define QLISTENBROADCAST_H
#include <QObject>
#include <QUdpSocket>
class QListenBroadcast : public QObject
{
    Q_OBJECT
public:
    QListenBroadcast(QObject *parent=0);
    ~QListenBroadcast(){;}
signals:
    void ConnectedTeacher();
public slots:
    void recvMsg();
public:
    QUdpSocket *listenBrocast;
};

#endif // QLISTENBROADCAST_H
