#include "qmanager.h"
#include <qDebug>

#include "define.h"
#include <qDebug>
#include <QMessageBox>
#include <QtCore>
#include <QSettings>
#include <QHostInfo>
#include <QProcess>
#include <QAbstractSocket>
QManager::QManager()
{
   ConnectedToTeacher();
   listenBroadcast = new QListenBroadcast(this);
   TipBox=new QMessageBox();
   TipBox->setWindowTitle(QStringLiteral("��Ϣ��ʾ"));
   connect(&m_client,SIGNAL(CONNECTEDSUCCESS()),this,SLOT(managerListen()));
   connect(&m_client,SIGNAL(DISSCONNECTED()),this,SLOT(DisConnectedFromTeacher()));
   connect(&m_client,SIGNAL(DISSCONNECTED()),this,SIGNAL(dissconnecteed()));

   connect(listenBroadcast,SIGNAL(ConnectedTeacher()),this,SLOT(BroadcastRecvMsg()));
   //---------------�Խ��źŲ�
   connect(this,SIGNAL(StartListen()),&m_listen,SLOT(start_system_audio()));
   connect(&m_client,SIGNAL(ALLTeachTalk(bool)),this,SLOT(ControlTalk(bool)));
   connect(this,SIGNAL(StarTalk()),&m_speak,SLOT(start_audio_to_system()));
   connect(this,SIGNAL(StopTalk()),&m_speak,SLOT(stop_voice_in()));


   //---------------ͬ����ѧ�źŲ�
   connect(&m_client,SIGNAL(startAllTeach(bool)),this,SIGNAL(startAllteacher(bool)));
   connect(&m_client,SIGNAL(AllTeachActionTab(int )),this,SIGNAL(AllTeachActionTab(int )));
   connect(&m_client,SIGNAL(AllTeachActionBtn(QString &)),this,SIGNAL(AllTeachActionBtn(QString &)));
   connect(&m_client,SIGNAL(AllTeachActionDiffItem(QString&)),this,SIGNAL(AllTeachActionDiffItem(QString&)));
   connect(&m_client,SIGNAL(AllTeachActionDiffItemDelete(QString&)),this,SIGNAL(AllTeachActionDiffItemDelete(QString&)));
   connect(&m_client,SIGNAL(AllTeachActionDiffItemlOAD()),this,SIGNAL(ALLTeachActionLoad()));
   connect(&m_client,SIGNAL(ALLTeachLocalFlash(QString &)),this,SIGNAL(ALLTeachLocalFlash(QString&)));
   connect(&m_client,SIGNAL(ALLTeachLocalCase(QString&)),this,SIGNAL(ALLTeachLocalCase(QString &)));
   connect(&m_client,SIGNAL(ALLTeachPlay()),this,SIGNAL(ALLTeachPlay()));
   connect(&m_client,SIGNAL(ALLTeachPhonophoresis()),this,SIGNAL(ALLTeachPhonophoresis()));
   connect(&m_client,SIGNAL(ALLTeachAuscultation()),this,SIGNAL(ALLTeachAuscultation()));
   connect(&m_client,SIGNAL(ALLTeacherPatter(QString)),this,SLOT(ALLTeacherPatter(QString)));
}

void QManager::BroadcastRecvMsg()
{
    QAbstractSocket::SocketState connectedState=m_client.ConnectedState();
    if(connectedState==QAbstractSocket::HostLookupState
            ||connectedState==QAbstractSocket::ConnectingState
            ||connectedState==QAbstractSocket::ConnectedState)
    {
//        qDebug()<<__FUNCTION__<<QStringLiteral("��������");
        return;
    }
    if(connectedState==QAbstractSocket::UnconnectedState)
    {
        ConnectedToTeacher();
//        qDebug()<<__FUNCTION__<<QStringLiteral("������������");

    }
}
void QManager::ConnectedToTeacher()
{
    QSettings *readconfig=new QSettings(APPPATH,QSettings::IniFormat);
    QString localhostName=readconfig->value("Client/ServerIP").toString();
    QHostInfo info=QHostInfo::fromName(localhostName);
    foreach(QHostAddress address,info.addresses())
    {
      if(address.protocol()==QAbstractSocket::IPv4Protocol)
          {
            m_client.connect_to_server(address.toString(),666666);
          }
    }
    delete readconfig;
}
void QManager::managerListen()
{
    TipBox->close();
    TipBox->setText(QStringLiteral("��ʦ�����ӳɹ�"));
    TipBox->exec();
    emit StartListen();
}
void QManager::DisConnectedFromTeacher()
{
    TipBox->close();
    TipBox->setText(QStringLiteral("��ʦ������ʧ��"));
    TipBox->exec();
}
void QManager::ControlTalk(bool cmd)
{
    qDebug()<<__FUNCTION__<<cmd;
    if(cmd)
    {
        emit StarTalk();
    }
    if(!cmd)
    {
        emit StopTalk();
    }
    emit TalkState(cmd);
}
void QManager::RequestTalk()
{
    QJsonDocument jdocument;
    QJsonObject jobject;

    QSettings *readconfig=new QSettings(APPPATH,QSettings::IniFormat);
    jobject.insert("Type",QString("string"));
    jobject.insert("cmd",QString("REQUESTTALK"));
    jobject.insert("data",readconfig->value("System_Param/deskID").toString());
    jdocument.setObject(jobject);
    QByteArray sendbyte=jdocument.toJson(QJsonDocument::Compact);
    m_client.send_msg(sendbyte);
    delete readconfig;
}
void QManager::ALLTeacherPatter(QString patter)
{


    QString HeartAuscultateType=patter.section(":",0,0);
    QString LoudSoundType=patter.section(":",1,1);
    QSettings *writeconfig=new QSettings(APPPATH,QSettings::IniFormat);
    if(writeconfig->value("System_Param/HeartAuscultateType").toInt()!=HeartAuscultateType.toInt()
            ||writeconfig->value("System_Param/LoudSoundType").toInt()!=LoudSoundType.toInt())
    {
        writeconfig->setValue("System_Param/HeartAuscultateType",HeartAuscultateType);
        writeconfig->setValue("System_Param/LoudSoundType",LoudSoundType);
        delete writeconfig;
        TipBox->close();
        TipBox->setText(QStringLiteral("�������������ģʽ���޸�,��������"));
        TipBox->exec();
        qApp->quit();
        QProcess::startDetached(qApp->applicationFilePath(), QStringList());

    }
    else
    {
        qDebug()<<__FUNCTION__<<QStringLiteral("�������� ģ������ģʽû�иı�");
    }
}
