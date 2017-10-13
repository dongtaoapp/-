#ifndef QTRAINMAINWINDOW_H
#define QTRAINMAINWINDOW_H

#include <QWidget>
#include <QMouseEvent>
#include "main_tab.h"
#include "qcompareview.h"
#include "qchosecurriculumview.h"
#include "qtouchtrainview.h"
#include "qsetsystemview.h"
#include "qmanager.h"
#include "myswitchbutton.h"
#include "qflashtree.h"
#include "m_ftp_manager.h"
#include <QLabel>
#include <QPushButton>
#include <QAxWidget>
#include <QStackedWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QPropertyAnimation>
#include <QMenu>
#include <QtSerialPort/QSerialPort>
#include "qsoundcontrol.h"
#include "qgettreecontentfromweb.h"
#include "qpalpationpracticetip.h"
#include <QTreeWidget>
#include <QWebEngineView>
#include <QMessageBox>
#include <QSettings>
class m_searchLineEdit :public QWidget
{
    Q_OBJECT
public:
    m_searchLineEdit (QWidget *parent=Q_NULLPTR);
    ~m_searchLineEdit();
private slots:
    void    onSearch();
signals:
    void search(QString &searchMsg);
private:
   QPushButton *pSearchButton ;
   QLineEdit *m_pSearchLineEdit;
   QHBoxLayout *pSearchLayout;

   bool issearch;
};


namespace Ui {
class QTrainMainWindow;
}

class QTrainMainWindow : public QWidget
{
    Q_OBJECT

public:
    enum ComboType{
         CouseWare,//�μ��ײ�
         Case,//�����ײ�
        Diff//���������ײ�
    };//�ײ�����
    explicit QTrainMainWindow(QWidget *parent = 0);
    ~QTrainMainWindow();
    void windowInit();
    void loadqss();

    void ChangeTabStyleSheet(int index);
protected:
    void mousePressEvent (QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent * event);
    void paintEvent(QPaintEvent *event);
    void timerEvent(QTimerEvent *event);
protected:
     void InitComm();

public slots:


      void  GetDiffData();
      void  GetCustomWare();
      void  m_show();

      void CouseWareTreeWidgetInit(QByteArray &Data);//�Զ���μ�
      void DiffTreeWidgetInit(QByteArray &data);//��������
      void DiffSoundLoadInit(QByteArray &Data);//load������������
      void downLoadSoundFile(QByteArray &Data);//�����Զ�������


      void CourseWareTab();
      void CaseTab();
      void DiffTab();
      void onTabchange(int index);
      void flashAction (QString cmd,QString data);
      void loadflash(QString &flashpath);//����flash
      void setPathshow(QString &path);
      void onPlaybtn();
      void ontalkbtn();

      void ChangeTalkBtnState(bool State);

      void onTabBtnClicked(int index);//tab�ؼ�����¼�


      void OnFlashItemData(QCoursewareInfo &info);//���Tree   ����Item data
      void OnwebItemData(userCourseware &info);//��� Ttee  �Զ���Item data
      void OnCaseItemData(stardardCase &Case);//��ȡ Tree ����Item data
      void OnDiffSoundData(diffSound &diffsound);
      void doSearchWork(QString &str);



      void CompareItem1(diffSound &data);
      void CompareItem2(diffSound &data);

      //��ʼ����������
      void InitSoundControl();
      //��������
      void OnSoundPlay();
      void play();
      //���ڶ�ȡ�����ݵĴ���
      void readyReadSlot();
      //ģ������
      void OnSoundSimular();
      //����ѵ��
      void PalpationTraining(QString &text,int index);

      //��ʼ��������
      void  StartCompareSound(diffSound &data1,diffSound &data2);

      void AllTeachInit(bool cmd);
      void AllTeachActionTab(int Tab);
      void AllTeachActionBtn(QString &action);
      void ALLTeachActionDiffItem(QString &ID);
      void ALLTeachActionDiffItemDelete(QString &index);
      void ALLTeachActionLOAD();
      void ALLTeachLocalFlash(QString &FlashName);

      void ALLTeachCase(QString &ID);
      void dissconnectedFromTeachComputer();
private:
    Ui::QTrainMainWindow *ui;
    QLabel *top_label;
    QLabel *m_title_label;
    QLabel *m_log_label;
    QLabel *play_label;
    QLabel *listen_label;
    QLabel *speak_label;
    QLabel *talk_label;
    QLabel *search_label;
    QLabel *local_label;
    QLabel *path_label;
    QLabel *bottom_label;
    QLabel *touchTrainLabel;

    QPushButton *m_close_btn;
    QPushButton *m_min_btn;
    QPushButton *sysTemBtn;
    QPushButton *play_btn;
    QPushButton *listen_btn;
    QPushButton *speak_btn;
    QPushButton *talk_btn;
    QPushButton *touchTrainBtn;

    SwitchButton *comboBtn;

    main_tab *m_tab;
    m_searchLineEdit *searchEdit;
    QAxWidget *flash_widget;//����flahs�ؼ�
    QWebEngineView *web_PPt;//����web ppt�ؼ�


    QStackedWidget *stacked_tree;
    QCompareView *compareview;
    QTouchTrainView *touchTrain;

    QSetSystemView *systemView;

    qFlashTreeBase baseTree;//�ķομ�����ͼ

    QString CurriculumID;
    QManager m_manager;
    QString m_flashpath;
    bool m_play,is_soundPlay,is_allTeach,is_listen;
    int xOffset,yOffset;
    int comboID,CurrentBtnIndex;//��ǰ�Ǹ�Tab�����ײ�
    m_ftp_manager webmanager;
    QPalpationpracticeTip *TipBox;
    QString webIP;
    bool isloadflash;
    bool Synchronous;//ͬ����ѧ״̬��ʶ
protected:
    QSerialPort*            m_pSerialPort;      //���ڲ��
    int                     m_nState;           //״̬: 0:��ͣ;1:�����μ�;2:ģ������;3:��������
    QSoundControl*          m_pSoundControl;    //����������
    QByteArray              m_comReadArray;     //���ڶ�ȡ���ݻ���
    QMutex                  m_cComReadMutex;
    UINT                    m_nDelayHandle;
    QByteArray              m_DiffsoundInfo[2];
    HWND hCurWnd;
};

#endif // QTRAINMAINWINDOW_H
