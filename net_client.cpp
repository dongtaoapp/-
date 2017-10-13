#include "net_client.h"
#include "define.h"
#include <QHostAddress>
#include <QHostInfo>
#include <QMessageBox>
#include <QtCore>
#include <QSettings>
#include "Windows.h"
net_client::net_client(QObject *parent) :
    QObject(parent)
{
    /***********查看教师机是否在线*************/
   udpsocket=new QUdpSocket;
   udpsocket->bind(QHostAddress::AnyIPv4, 1066, QUdpSocket::ReuseAddressHint);
   QHostAddress mcast_addr("224.0.0.17");
  udpsocket->joinMulticastGroup(mcast_addr);//这句是关键，加入组播地址

  connect(udpsocket,SIGNAL(readyRead()),this,SLOT(onUdpSocket()));



/*****************************/
  net_client_socket=new QTcpSocket();
  connect(net_client_socket,SIGNAL(readyRead()),this,SLOT(recv_msg()));
  connect(net_client_socket,SIGNAL(connected()),this,SLOT(onconnected()));
  connect(net_client_socket,SIGNAL(disconnected()),this,SLOT(ondisconnected()));
  connect(net_client_socket,SIGNAL(error(QAbstractSocket::SocketError)),this,SLOT(error(QAbstractSocket::SocketError)));
}

net_client::~net_client()
{
   net_client_socket->abort();
   net_client_socket->deleteLater();

   udpsocket->deleteLater();

    this->deleteLater();
   qDebug()<<__FUNCTION__;

}

void net_client::onUdpSocket()
{
    QSettings *readconfig=new QSettings(APPPATH,QSettings::IniFormat);
    readconfig->value("Client/ServerIP").toString();
    connect_to_server(readconfig->value("Client/ServerIP").toString(),666666);
    delete readconfig;
}


void net_client::connect_to_server(QString ip, qint16 port)
{
    QHostAddress address(ip);
    net_client_socket->connectToHost(address,port);
}

void net_client::onconnected()
{
    emit signal_socket_state(net_client_state::CONNECTED);
}
void net_client::ondisconnected()
{
    emit DISSCONNECTED();
    net_client_socket->abort();
}

void net_client::send_msg(QByteArray &msg)
{
  net_client_socket->write(msg);
}
/** 接收信息*/
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
            if(object.value("cmd").toString()==QString("NULL"))
            {
                if(data=="CLIENTCONNECTEDSUCCESS")
                {
                    net_client_socket->write(TellServerDeskID());
                    QMessageBox::information(NULL,QStringLiteral("连接提示"),QStringLiteral("连接教师机成功"),QMessageBox::Yes);
                    emit CONNECTEDSUCCESS();
                    return;
                }
            }
         }
         if(type==QString("talk"))
         {
//            bool cmd=object.value("cmd").toBool();
            emit ALLTeachTalk(object.value("cmd").toBool());
         }
    }
    else
    {
        qDebug()<<__FUNCTION__<<simp_json_error.errorString();
    }
}
/***********连接错误信息***********/
void net_client::error(QAbstractSocket::SocketError errorstring)
{
    Q_UNUSED(errorstring);
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
   QMessageBox::information(NULL,QStringLiteral("信息提示"),QStringLiteral("连接教师机失败"),QMessageBox::Yes);
}

void net_client::shutdown()
{
    qDebug()<<__FUNCTION__;
# if 0
    system("shutdown -s -t 0");
#endif
}
