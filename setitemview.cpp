#include "setitemview.h"

#include "ui_setitemview.h"

#include "define.h"
#include <qDebug>
#include <QDir>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QMessageBox>
#include <QProcess>
#include <QStringList>
SetItemView::SetItemView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SetItemView)
{
    ui->setupUi(this);
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);

    this->setWindowTitle(QStringLiteral("系统设置选项"));
    Apppath=QCoreApplication::applicationDirPath();
//    pag1_radiobtn=-1;
//    pag2_radiobtn=-1;
    ui->stackedWidget->setCurrentIndex(2);
    configInit = new QSettings(APPPATH, QSettings::IniFormat);
    SerialPortInit();
    this->Init();
    connect(this,SIGNAL(changPag(int)),ui->stackedWidget,SLOT(setCurrentIndex(int)));
//    connect(ui->btn1,SIGNAL(clicked(bool)),this,SLOT(onBtn1()));
//    connect(ui->btn2,SIGNAL(clicked(bool)),this,SLOT(onBtn2()));
    connect(ui->btn3,SIGNAL(clicked(bool)),this,SLOT(onBtn3()));
    connect(ui->btn4,SIGNAL(clicked(bool)),this,SLOT(onBtn4()));
    connect(ui->cancelBtn,SIGNAL(clicked(bool)),this,SLOT(oncancelBtn()));
    connect(ui->okBtn,SIGNAL(clicked(bool)),this,SLOT(onOkbtn()));
}

SetItemView::~SetItemView()
{
    delete ui;
    delete configInit;
    qDebug()<<__FUNCTION__;
}

void SetItemView::SerialPortInit()
{
    int i=0;
    foreach (const QSerialPortInfo &info, QSerialPortInfo::availablePorts())
    {
        ui->comBoxComPort->insertItem(i,info.portName());
        ui->comBoxComPort->setFocusPolicy(Qt::NoFocus);
        i++;
    }
}

void SetItemView::onBtn3()
{
    btnInit();
    ui->btn3->setStyleSheet(QString("QPushButton{color:#4aabe9;background-color:#f6f7fc}"));
    emit changPag(2);
}
void SetItemView::onBtn4()
{
    btnInit();
    ui->btn4->setStyleSheet(QString("QPushButton{color:#4aabe9;background-color:#f6f7fc}"));
    emit changPag(3);
}
void SetItemView::btnInit()
{
    ui->btn3->setStyleSheet(QString("QPushButton{color:;background-color:}"));
    ui->btn4->setStyleSheet(QString("QPushButton{color:;background-color:}"));
}
void SetItemView::Init()
{
    deskID=configInit->value("System_Param/deskID").toString();
    WebIP=configInit->value("System_Param/WebIP").toString();
    Comm=configInit->value("System_Param/Comm").toString();
    ServerIP=configInit->value("Client/ServerIP").toString();


    ui->studentID->setText(deskID);
    ui->web_ip->setText(WebIP);
    ui->comBoxComPort->setCurrentText(Comm);
    ui->trachIP->setText(ServerIP);
}

/******写入配置文件*******/
void SetItemView::onOkbtn()
{
        deskID=configInit->value("System_Param/deskID").toString();
        WebIP=configInit->value("System_Param/WebIP").toString();
        Comm=configInit->value("System_Param/Comm").toString();
        ServerIP=configInit->value("Client/ServerIP").toString();
        if(deskID==ui->studentID->text()
                &&WebIP==ui->web_ip->text()
                &&Comm==ui->comBoxComPort->currentText()
                &&ServerIP==ui->trachIP->text())
        {
            this->close();
        }
        else
        {
            QMessageBox::StandardButton rb=QMessageBox::information(NULL,
                                                                    QStringLiteral("修改提示"),QStringLiteral("确定修改,程序将重启"),
                                                                    QMessageBox::Yes,QMessageBox::No);
            if(rb==QMessageBox::Yes)
            {
                configInit->setValue("System_Param/deskID",ui->studentID->text());
                configInit->setValue("System_Param/WebIP",ui->web_ip->text());
                configInit->setValue("System_Param/Comm",ui->comBoxComPort->currentText());
                configInit->setValue("Client/ServerIP",ui->trachIP->text());
                qApp->quit();
                QProcess::startDetached(qApp->applicationFilePath(), QStringList());
            }
            if(rb==QMessageBox::No)
            {
                ui->studentID->setText(deskID);
                ui->web_ip->setText(WebIP);
                ui->comBoxComPort->setCurrentText(Comm);
                ui->trachIP->setText(ServerIP);
                this->close();
                return;
            }
        }
}

void SetItemView::oncancelBtn()
{
    btnInit();
    ui->studentID->setText(deskID);
    ui->web_ip->setText(WebIP);
    ui->comBoxComPort->setCurrentText(Comm);
    ui->trachIP->setText(ServerIP);
    this->close();
}
void SetItemView::closeEvent(QCloseEvent *)
{
    btnInit();
    ui->studentID->setText(deskID);
    ui->web_ip->setText(WebIP);
    ui->comBoxComPort->setCurrentText(Comm);
    ui->trachIP->setText(ServerIP);
}
