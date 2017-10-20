#include "net_client.h"
#include "define.h"
#include <QHostAddress>
#include <QHostInfo>
#include <QMessageBox>
#include <QtCore>
#include <QSettings>

#include "Windows.h"

/*
 *
 *
 * socket = new QUdpSocket(this);
    if(socket->bind(QHostAddress::AnyIPv4, 250000, QUdpSocket::ShareAddress))
    {
        //        //QHostAddress("224.1.1.3"), 250000

        qDebug()<<socket->errorString();
        //设置回环
        socket->setSocketOption(QAbstractSocket::MulticastLoopbackOption, 0);
        socket->joinMulticastGroup(QHostAddress("224.1.1.3"));//加入组播地址
    }
 */



QHostAddress mcast_addr("224.0.0.17");
net_client::net_client(QObject *parent) :
    QObject(parent)
{
//    /***********查看教师机是否在线*************/
//   udpsocket=new QUdpSocket;
//   if(udpsocket->bind(QHostAddress::AnyIPv4, 1066,QUdpSocket::ShareAddress))
//   {
//         udpsocket->joinMulticastGroup(mcast_addr);//这句是关键，加入组播地址
//   }
//   connect(udpsocket,SIGNAL(readyRead()),this,SLOT(onUdpSocket()));

/*****************************/
  net_client_socket=new QTcpSocket();
  connect(net_client_socket,SIGNAL(readyRead()),this,SLOT(recv_msg()));
  connect(net_client_socket,SIGNAL(disconnected()),this,SLOT(ondisconnected()));
  connect(net_client_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(error(QAbstractSocket::SocketError)));
}

net_client::~net_client()
{
   net_client_socket->abort();
   net_client_socket->deleteLater();
//   udpsocket->deleteLater();
   this->deleteLater();
}
/*
void net_client::onUdpSocket()
{


      QByteArray aa=udpsocket->readAll();

      qDebug()<<__FUNCTION__<<aa;
//    if(net_client_socket->state()==QAbstractSocket::HostLookupState||QAbstractSocket::ConnectedState||QAbstractSocket::ConnectingState)
//    {
//        qDebug()<<__FUNCTION__<<QStringLiteral("正在尝试连接.........");
//        return;
//    }
//    if(net_client_socket->state()==QAbstractSocket::UnconnectedState)
//    {
//        qDebug()<<__FUNCTION__<<QStringLiteral("正在重新连接...........");
//        QSettings *readconfig=new QSettings(APPPATH,QSettings::IniFormat);
//        QString localhostName=readconfig->value("Client/ServerIP").toString();
//        QHostInfo info=QHostInfo::fromName(localhostName);
//        foreach(QHostAddress address,info.addresses())
//        {
//          if(address.protocol()==QAbstractSocket::IPv4Protocol)
//              {
//                qDebug()<<__FUNCTION__<<address.toString();
//                connect_to_server(address.toString(),666666);
//              }
//        }
//        delete readconfig;
//    }
}
*/

void net_client::connect_to_server(QString ip, qint16 port)
{
    QHostAddress address(ip);
    net_client_socket->connectToHost(address,port);
}

void net_client::onconnected()
{
//    emit signal_socket_state(net_client_state::CONNECTED);
}

void net_client::ondisconnected()
{
//    emit DISSCONNECTED();
//    net_client_socket->close();
}

void net_client::send_msg(QByteArray &msg)
{
  net_client_socket->write(msg);
}
void net_client::recv_msg()
{
  QByteArray recvbytes=net_client_socket->readAll();

  if(recvbytes.isEmpty())
  {
      return;
  }
  manager_msg(recvbytes);
}

QByteArray net_client::TellServerDeskID()
{
    QString data;
    QString DeskID;
    QSettings *readconfig=new QSettings(APPPATH,QSettings::IniFormat);
    DeskID=readconfig->value("System_Param/deskID").toString();
    delete readconfig;
    foreach(QHostAddress address,QHostInfo::fromName(QHostInfo::localHostName()).addresses())
    {
         if(address.protocol() == QAbstractSocket::IPv4Protocol)
         data=DeskID+QString(":")+ address.toString();
    }
    jobject.insert("Type",QString("string"));
    jobject.insert("cmd",QString("DeskID"));
    jobject.insert("data",data);
    jdocument.setObject(jobject);
    QByteArray str=jdocument.toJson(QJsonDocument::Compact);
    return str;

}

/***********解析教师机的json字符串 并发出相关的信号**********/

void net_client::manager_msg(QByteArray &recv)
{
    if(recv.isEmpty())
    {
      return ;
    }
    QJsonParseError simp_json_error;

    QJsonDocument jdocument =QJsonDocument::fromJson(recv,&simp_json_error);

    if(simp_json_error.error==QJsonParseError::NoError)
    {
        QJsonObject object=jdocument.object();
        if(object.isEmpty())
        {
            return;
        }
         QString type=object.value("Type").toString();
         QString cmd=object.value("cmd").toString();
         QString data=object.value("data").toString();
         if(type==QString("Synchronocus"))
         {
             if(cmd==QString("control"))
             {
                emit startAllTeach(object.value("data").toBool());
                return;
             }
             if(cmd==QString("action"))
             {
                emit AllTeachActionBtn(data);
                return;
             }
             if(cmd==QString("Tab"))
             {
                 int Tab=object.value("data").toInt();
                 emit AllTeachActionTab(Tab);
                 return;
             }
             if(cmd==QString("actionDiffItem"))
             {
                 emit AllTeachActionDiffItem(data);
                   return;
             }
             if(cmd==QString("actionDiffItemDelete"))
             {
                 emit AllTeachActionDiffItemDelete(data);
                   return;
             }
             if(cmd==QString("LoadSound"))
             {
                 emit AllTeachActionDiffItemlOAD();
                   return;
             }

         }
         if(type==QString("flash"))
         {
            if(cmd==QString("LOCALFlash"))
            {
                emit ALLTeachLocalFlash(data);
                  return;
            }
            if(cmd==QString("LOCALCase"))
            {
                emit ALLTeachLocalCase(data);
                  return;
            }
         }
         if(type==QString("WORK"))
         {
             if(cmd==QString("play"))
             {
                emit ALLTeachPlay();
                return;
             }
             if(cmd==QString("auscultation"))//--------听诊
             {
                emit ALLTeachAuscultation();
                   return;
             }
             if(cmd==QString("phonophoresis"))//扩音听诊
             {
                emit ALLTeachPhonophoresis();
                return;
             }
         }
         if(type==QString("closePC"))
         {        
            shutdown();
             return;
         }
         if(type==QString("string"))
         {
             if(cmd=="CLIENTCONNECTEDSUCCESS")
             {
                net_client_socket->write(TellServerDeskID());
                if(data.section(":",2,2)==QString("Synchronous"))
                {
                    startAllTeach(true);
                }
                emit CONNECTEDSUCCESS();
                emit ALLTeacherPatter(data.section(":",0,1));
                return;
              }
         }
         if(type==QString("talk"))
         {
            emit ALLTeachTalk(object.value("cmd").toBool());
         }
         if(type==QString("Patter"))
         {
             emit ALLTeacherPatter(cmd);
         }
    }
    else
    {
        qDebug()<<__FUNCTION__<<simp_json_error.errorString();
    }
}



void net_client::error(QAbstractSocket::SocketError errorstring)
{
    Q_UNUSED(errorstring);
    //net_client_socket->close();
    emit DISSCONNECTED();
#if 0
   if(errorstring==QAbstractSocket::ConnectionRefusedError)
   {
      emit signal_socket_state(net_client_state::CONECTEDREFUSE);
   }
   else if(errorstring==QAbstractSocket::SocketAccessError)
   {
       emit signal_socket_state(net_client_state::SOCKETACCESSERROR);
   }
   else
   {
       emit signal_socket_state(net_client_state::UNKNOWNERROR);
   }
#endif
//   QMessageBox::information(NULL,QStringLiteral("信息提示"),QStringLiteral("连接教师机失败"),QMessageBox::Yes);
}

void net_client::shutdown()
{
    qDebug()<<__FUNCTION__;
# if 0
    system("shutdown -s -t 0");
#endif
}
