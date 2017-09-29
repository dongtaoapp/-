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
   connect(&m_client,SIGNAL(startAllTeach(bool)),this,SIGNAL(startAllteacher(bool)));
   connect(&m_client,SIGNAL(AllTeachAction(QString &)),this,SIGNAL(AllTeachAction(QString &)));
   connect(&m_client,SIGNAL(AllTeachActionDiffItem(QString&)),this,SIGNAL(AllTeachActionDiffItem(QString&)));
   connect(&m_client,SIGNAL(AllTeachActionDiffItemDelete(QString&)),this,SIGNAL(AllTeachActionDiffItemDelete(QString&)));
    connect(&m_client,SIGNAL(AllTeachActionDiffItemlOAD()),this,SIGNAL(ALLTeachActionLoad()));
}
QManager::~QManager()
{
    qDebug()<<__FUNCTION__;

}

void QManager::managerListen()
{
    m_listen.funbind(25000);
    m_listen.start_system_audio();
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
