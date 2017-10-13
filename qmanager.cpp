#include "qmanager.h"
#include <qDebug>

#include "define.h"
#include <qDebug>
#include <QMessageBox>
#include <QtCore>
#include <QSettings>
QManager::QManager()
{
   QSettings *readconfig=new QSettings(APPPATH,QSettings::IniFormat);
   readconfig->value("Client/ServerIP").toString();
   m_client.connect_to_server(readconfig->value("Client/ServerIP").toString(),666666);
   delete readconfig;
   connect(&m_client,SIGNAL(CONNECTEDSUCCESS()),this,SLOT(managerListen()));
   connect(&m_client,SIGNAL(DISSCONNECTED()),this,SIGNAL(dissconnecteed()));

   //---------------对讲信号槽
   connect(this,SIGNAL(StartListen()),&m_listen,SLOT(start_system_audio()));

   connect(&m_client,SIGNAL(ALLTeachTalk(bool)),this,SLOT(ControlTalk(bool)));
   connect(this,SIGNAL(StarTalk()),&m_speak,SLOT(start_audio_to_system()));
   connect(this,SIGNAL(StopTalk()),&m_speak,SLOT(stop_voice_in()));
   //---------------同步教学信号槽
//   connect(&m_client,SIGNAL(ALLTeachTalk(bool)),this,SLOT(ControlTalk(bool)));
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
}
QManager::~QManager()
{

}

void QManager::managerListen()
{
    emit StartListen();
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
