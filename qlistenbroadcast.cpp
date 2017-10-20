#include "qlistenbroadcast.h"
#include <QByteArray>
QListenBroadcast::QListenBroadcast(QObject *parent):
    QObject(parent)
{
    listenBrocast=new QUdpSocket(this);
    listenBrocast->bind(1066,QUdpSocket::ShareAddress);
    connect(listenBrocast,SIGNAL(readyRead()),this,SLOT(recvMsg()));
}

void QListenBroadcast::recvMsg()
{
   QByteArray data;
   while(listenBrocast->hasPendingDatagrams())
   {
       if(listenBrocast->pendingDatagramSize()==-1)
       {
           return;
       }
       data.resize(listenBrocast->pendingDatagramSize());
       listenBrocast->readDatagram(data.data(),data.size());
   }
   if(data==QByteArray("CONNECT_TEACHER"))
   {
       emit ConnectedTeacher();
   }
}
