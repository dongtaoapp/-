#include "qpalpationpracticetip.h"
#include "ui_qpalpationpracticetip.h"
#include <QPainter>
QPalpationpracticeTip::QPalpationpracticeTip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QPalpationpracticeTip)
{
    ui->setupUi(this);
    this->setFixedSize(478,99);
    this->setObjectName("QPalpationpracticeTip");
    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowCloseButtonHint;
    setWindowFlags(flags);
    m_movie=new QMovie(QCoreApplication::applicationDirPath()+QString("/data/AbdominalPalpation.gif"));
    ui->Gif_label->setMovie(m_movie);

}

QPalpationpracticeTip::~QPalpationpracticeTip()
{
    delete m_movie;
    delete ui;
}
void QPalpationpracticeTip::SetTitle(QString &Title)
{
    this->setWindowTitle(Title);
}
void QPalpationpracticeTip::m_exec()
{
    m_movie->start();
    this->exec();
}
void QPalpationpracticeTip::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    QStyleOption opt;
    opt.init(this);
    QPainter p(this);
    style()->drawPrimitive(QStyle::PE_Widget, &opt, &p, this);
}
