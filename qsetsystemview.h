#ifndef QSETSYSTEMVIEW_H
#define QSETSYSTEMVIEW_H

#include <QWidget>
#include <QDialog>
#include <QListWidgetItem>
#include <setitemview.h>
#include "aboutform.h"
/*****************主界面右上角系统设置界面*********************/
namespace Ui {
class QSetSystemView;
}

class QSetSystemView : public QDialog
{
    Q_OBJECT

public:
    explicit QSetSystemView(QWidget *parent = 0);
    ~QSetSystemView();
    void ViewInit();
protected:
   void paintEvent(QPaintEvent *event);
public slots:
    void onMYItemclicked(QListWidgetItem *item);
signals:

private:
    Ui::QSetSystemView *ui;
    QListWidgetItem *exitItem;
    QListWidgetItem *setItem;
    QListWidgetItem *aboutTtem;
    SetItemView *setView;
    AboutForm *about;
};

#endif // QSETSYSTEMVIEW_H
