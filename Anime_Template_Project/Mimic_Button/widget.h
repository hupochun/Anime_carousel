#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPropertyAnimation>
#include <QPainter>
#include <QMouseEvent>
#include "depressed_button.h"

class Widget : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(int MH READ MH WRITE setMH NOTIFY MHChanged FINAL)
    Q_PROPERTY(int KJ READ KJ WRITE setKJ NOTIFY KJChanged FINAL)
    Q_PROPERTY(int MH1 READ MH1 WRITE setMH1 FINAL)
    Q_PROPERTY(int KJ1 READ KJ1 WRITE setKJ1 FINAL)

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

    int MH() const;
    void setMH(int newMH);

    int KJ() const;
    void setKJ(int newKJ);

    int MH1() const;
    void setMH1(int newMH1);

    int KJ1() const;
    void setKJ1(int newKJ1);

public slots:
    void Animation_1(bool x);
    void Animation_2(bool x);

signals:
    void MHChanged();
    void KJChanged();

protected:
    void paintEvent(QPaintEvent* event) override;

private:
    Depressed_Button* xxxx1;
    Depressed_Button* xxxx2;
    QPropertyAnimation* animation1;
    QPropertyAnimation* animation2;
    QPropertyAnimation* animation3;
    QPropertyAnimation* animation4;

    int m_MH = 155;
    int m_KJ = 30;
    int m_MH1 = 155;
    int m_KJ1 = 30;
};

#endif // WIDGET_H
