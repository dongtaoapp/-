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
         CouseWare,//课件套餐
         Case,//病例套餐
        Diff//鉴别听诊套餐
    };//套餐类型
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

      void CouseWareTreeWidgetInit(QByteArray &Data);//自定义课件
      void DiffTreeWidgetInit(QByteArray &data);//鉴别听诊
      void DiffSoundLoadInit(QByteArray &Data);//load鉴别听诊声音
      void downLoadSoundFile(QByteArray &Data);//下载自定义声音


      void CourseWareTab();
      void CaseTab();
      void DiffTab();
      void onTabchange(int index);
      void flashAction (QString cmd,QString data);
      void loadflash(QString &flashpath);//加载flash
      void setPathshow(QString &path);
      void onPlaybtn();
      void ontalkbtn();

      void ChangeTalkBtnState(bool State);

      void onTabBtnClicked(int index);//tab控件点击事件


      void OnFlashItemData(QCoursewareInfo &info);//获得Tree   本地Item data
      void OnwebItemData(userCourseware &info);//获得 Ttee  自定义Item data
      void OnCaseItemData(stardardCase &Case);//获取 Tree 病例Item data
      void OnDiffSoundData(diffSound &diffsound);
      void doSearchWork(QString &str);



      void CompareItem1(diffSound &data);
      void CompareItem2(diffSound &data);

      //初始化声音控制
      void InitSoundControl();
      //扩音听诊
      void OnSoundPlay();
      void play();
      //串口读取到数据的处理
      void readyReadSlot();
      //模拟听诊
      void OnSoundSimular();
      //触诊训练
      void PalpationTraining(QString &text,int index);

      //开始鉴别听诊
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
    QAxWidget *flash_widget;//加载flahs控件
    QWebEngineView *web_PPt;//加载web ppt控件


    QStackedWidget *stacked_tree;
    QCompareView *compareview;
    QTouchTrainView *touchTrain;

    QSetSystemView *systemView;

    qFlashTreeBase baseTree;//心肺课件树形图

    QString CurriculumID;
    QManager m_manager;
    QString m_flashpath;
    bool m_play,is_soundPlay,is_allTeach,is_listen;
    int xOffset,yOffset;
    int comboID,CurrentBtnIndex;//当前那个Tab存在套餐
    m_ftp_manager webmanager;
    QPalpationpracticeTip *TipBox;
    QString webIP;
    bool isloadflash;
    bool Synchronous;//同步教学状态标识
protected:
    QSerialPort*            m_pSerialPort;      //串口插件
    int                     m_nState;           //状态: 0:暂停;1:播发课件;2:模拟听诊;3:扩音听诊
    QSoundControl*          m_pSoundControl;    //声音控制类
    QByteArray              m_comReadArray;     //串口读取数据缓存
    QMutex                  m_cComReadMutex;
    UINT                    m_nDelayHandle;
    QByteArray              m_DiffsoundInfo[2];
    HWND hCurWnd;
};

#endif // QTRAINMAINWINDOW_H
