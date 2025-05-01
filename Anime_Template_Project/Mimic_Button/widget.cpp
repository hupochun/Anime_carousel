#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    this->resize(1111, 1111);

    xxxx1 = new Depressed_Button(":/new/prefix1/img/twitter.png", this);
    connect(xxxx1, &Depressed_Button::Animation_Trigger_State, this, &Widget::Animation_1);
    xxxx1->move(255, 455);
    xxxx1->show();

    xxxx2 = new Depressed_Button(":/new/prefix1/img/微信.png", this);
    connect(xxxx2, &Depressed_Button::Animation_Trigger_State, this, &Widget::Animation_2);
    xxxx2->move(655, 455);
    xxxx2->show();

    animation1 = new QPropertyAnimation(this, "MH");
    animation1->setDuration(200);
    animation1->setStartValue(m_MH);
    animation1->setEndValue(0);

    animation2 = new QPropertyAnimation(this, "KJ");
    animation2->setDuration(200);
    animation2->setStartValue(m_KJ);
    animation2->setEndValue(0);

    animation3 = new QPropertyAnimation(this, "MH1");
    animation3->setDuration(200);
    animation3->setStartValue(m_MH1);
    animation3->setEndValue(0);

    animation4 = new QPropertyAnimation(this, "KJ1");
    animation4->setDuration(200);
    animation4->setStartValue(m_KJ1);
    animation4->setEndValue(0);
}

Widget::~Widget() {}

void Widget::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setBrush(QColor(239, 239, 239, 255));
    painter.setPen(Qt::NoPen);
    painter.drawRoundedRect(0, 0, width(), height(), 30, 30);

    QImage blur_image(QSize(xxxx1->width() * 3, xxxx1->height() * 3), QImage::Format_ARGB32);
    blur_image.fill(QColor(0, 0, 0, 0));
    QPainter image_painter(&blur_image);
    image_painter.setRenderHint(QPainter::Antialiasing);
    image_painter.setPen(Qt::NoPen);
    image_painter.setBrush(QColor(255, 255, 255, 255));
    image_painter.drawRoundedRect(QRect(QPoint(xxxx1->width() - m_KJ, xxxx1->height() - m_KJ), QSize(xxxx1->width(), xxxx1->height())), 35, 35);
    image_painter.setBrush(QColor(114, 114, 114, 85));
    image_painter.drawRoundedRect(QRect(QPoint(xxxx1->width() + m_KJ, xxxx1->height() + m_KJ), QSize(xxxx1->width(), xxxx1->height())), 35, 35);
    image_painter.end();
    painter.drawImage(QRect(xxxx1->geometry().x() - xxxx1->width(), xxxx1->geometry().y() - xxxx1->height(), xxxx1->width() * 3, xxxx1->height() * 3), blur_image);

    QImage blur_image1(QSize(xxxx2->width() * 3, xxxx2->height() * 3), QImage::Format_ARGB32);
    blur_image1.fill(QColor(0, 0, 0, 0));
    QPainter image_painter1(&blur_image1);
    image_painter1.setRenderHint(QPainter::Antialiasing);
    image_painter1.setPen(Qt::NoPen);
    image_painter1.setBrush(QColor(255, 255, 255, 255));
    image_painter1.drawRoundedRect(QRect(QPoint(xxxx2->width() - m_KJ1, xxxx2->height() - m_KJ1), QSize(xxxx2->width(), xxxx2->height())), 35, 35);
    image_painter1.setBrush(QColor(114, 114, 114, 85));
    image_painter1.drawRoundedRect(QRect(QPoint(xxxx2->width() + m_KJ1, xxxx2->height() + m_KJ1), QSize(xxxx2->width(), xxxx2->height())), 35, 35);
    image_painter1.end();
    painter.drawImage(QRect(xxxx2->geometry().x() - xxxx2->width(), xxxx2->geometry().y() - xxxx2->height(), xxxx2->width() * 3, xxxx2->height() * 3), blur_image1);
}

void Widget::Animation_1(bool x)
{
    if (x)
    {
        animation1->setDirection(QAbstractAnimation::Forward);
        animation1->start();
        animation2->setDirection(QAbstractAnimation::Forward);
        animation2->start();
    }
    else
    {
        animation1->setDirection(QAbstractAnimation::Backward);
        animation1->start();
        animation2->setDirection(QAbstractAnimation::Backward);
        animation2->start();
    }
}

void Widget::Animation_2(bool x)
{
    if (x)
    {
        animation3->setDirection(QAbstractAnimation::Forward);
        animation3->start();
        animation4->setDirection(QAbstractAnimation::Forward);
        animation4->start();
    }
    else
    {
        animation3->setDirection(QAbstractAnimation::Backward);
        animation3->start();
        animation4->setDirection(QAbstractAnimation::Backward);
        animation4->start();
    }
}

int Widget::MH() const
{
    return m_MH;
}

void Widget::setMH(int newMH)
{
    if (m_MH == newMH)
        return;
    m_MH = newMH;
    emit MHChanged();
    update();
}

int Widget::KJ() const
{
    return m_KJ;
}

void Widget::setKJ(int newKJ)
{
    if (m_KJ == newKJ)
        return;
    m_KJ = newKJ;
    emit KJChanged();
    update();
}

int Widget::MH1() const
{
    return m_MH1;
}

void Widget::setMH1(int newMH1)
{
    m_MH1 = newMH1;
    update();
}

int Widget::KJ1() const
{
    return m_KJ1;
}

void Widget::setKJ1(int newKJ1)
{
    m_KJ1 = newKJ1;
    update();
}
