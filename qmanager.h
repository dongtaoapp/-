#ifndef QMANAGER_H
#define QMANAGER_H

#include <QObject>
#include <QJsonArray>
#include <QJsonObject>
#include <QJsonDocument>
#include <QMessageBox>
#include "net_client.h"
#include "qlistenbroadcast.h"
#include "listen.h"
#include "speak.h"
class QManager : public QObject
{
    Q_OBJECT
public:
    QManager();
    ~QManager(){;}

    void RequestTalk();
    void ConnectedToTeacher();
public slots:
    void managerListen();
    void DisConnectedFromTeacher();
    void ControlTalk(bool cmd);
    void ALLTeacherPatter(QString patter);

    void BroadcastRecvMsg();
signals:
    void startAllteacher(bool);
    void AllTeachActionTab(int Tab);
    void AllTeachActionBtn(QString &);
    void AllTeachActionDiffItem(QString &);
    void AllTeachActionDiffItemDelete(QString &);
    void ALLTeachActionLoad();
    void ALLTeachLocalFlash(QString &);
    void ALLTeachLocalCase(QString &);
    void ALLTeachPlay();
    void ALLTeachPhonophoresis();
    void ALLTeachAuscultation();
    void dissconnecteed();

    void StartListen();

    void StarTalk();
    void StopTalk();

    void TalkState(bool);
private:
    net_client m_client;
    listen m_listen;
    speak m_speak;
    QMessageBox *TipBox;

    QListenBroadcast *listenBroadcast;
};

#endif // QMANAGER_H
