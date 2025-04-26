#ifndef DAEN_NO_KADO_H
#define DAEN_NO_KADO_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QVector>
#include <QPixmap>
#include <QResizeEvent>
#include <QTimer>
#include "latticed_circle_button.h"

class Daen_no_Kado : public QWidget
{
    Q_OBJECT
    Q_PROPERTY(qreal Progress_Bar_X READ Progress_Bar_X WRITE setProgress_Bar_X FINAL)
    Q_PROPERTY(qreal Progress_Bar_Width READ Progress_Bar_Width WRITE setProgress_Bar_Width FINAL)
    Q_PROPERTY(qreal Expand_Collapse_Height READ Expand_Collapse_Height WRITE setExpand_Collapse_Height FINAL)
    Q_PROPERTY(int Expand_Collapse_Opacity READ Expand_Collapse_Opacity WRITE setExpand_Collapse_Opacity FINAL)

public:
    explicit Daen_no_Kado(QWidget* parent = nullptr);
    void Get_Image();
    void Kiso_Deta_Kouchiku();
    void Gazou_wo_nabebae_ru();
    void Byouga_Ryouiki(qreal& Gazou_Zen_XJiku, qreal& Gazou_Go_XJiku, QPixmap& Ehon);
    void draw_text();
    void Draw_Progress_Bar();
    qreal calculateRectRotation(qreal& xLeft);
    qreal Keisan_suru_shukusetsu_no_takasa(qreal& xLeft);
    void animations();
    
    QPropertyAnimation* animation;
    QPropertyAnimation* animation2;
    QPropertyAnimation* animation3;
    QPropertyAnimation* animation4;
    int zoom_rate = 10;

    Latticed_Circle_Button* button;
    Latticed_Circle_Button* button2;

    QTimer timerA;
    QTimer timerB;

    void Card_Move_Left_Behavior();
    void Card_Move_Right_Behavior();

public:
    qreal Progress_Bar_X() const;
    void setProgress_Bar_X(qreal newProgress_Bar_X);
    qreal Progress_Bar_Width() const;
    void setProgress_Bar_Width(qreal newProgress_Bar_Width);
    qreal Expand_Collapse_Height() const;
    void setExpand_Collapse_Height(qreal newExpand_Collapse_Height);
    int Expand_Collapse_Opacity() const;
    void setExpand_Collapse_Opacity(int newExpand_Collapse_Opacity);

public slots:
    void Move_Left();
    void Move_Right();
    void koushin_suru();
    void Progress_Bar_Data_Update();

protected:
    void paintEvent(QPaintEvent* event);
    void resizeEvent(QResizeEvent* event);
    void mousePressEvent(QMouseEvent* event);
    void mouseMoveEvent(QMouseEvent* event);
    void mouseReleaseEvent(QMouseEvent* event);
    bool event(QEvent* e);
    void wheelEvent(QWheelEvent* event);

private:
    QVector<QPixmap> Gazou_Shuu;
    QVector<QPair<qreal, qreal>> Kado_Suu;

    qreal kankaku;
    qreal Kari_no_kankaku;
    qreal Left_Limit_Margin;
    qreal Right_Limit_Margin;
    qreal Substitute_Required_Spacing;

    bool Ima_no_joutai = true;
    bool Execution_Direction = false;

    QRect recta;
    qreal maxRadians = 0.5;
    qreal maxRadians2 = 28.0;

    qreal leftBound = 0.0;
    qreal Ratio_Position = -0.375;

    qreal Time_Step = 15.000;

    QPointF Jouhan_Daen_no_Chuushin;
    double Jouhan_Daen_no_Y_Hankei;
    double Jouhan_Daen_no_X_Hankei;

    QPointF Kahan_Daen_no_Chuushin;
    double Kahan_Daen_no_Y_Hankei;
    double Kahan_Daen_no_X_Hankei;

    bool mousePressed = false;
    int startX = 0;
    int accumulatedDistance = 0;

    qreal m_Progress_Bar_X = 0;
    qreal m_Progress_Bar_Width = 0;
    qreal Progress_Bar_Step = 1;
    bool Is_Execution_Step_Width = true;
    bool Is_Execution_Step_X = false;

    qreal m_Expand_Collapse_Height;
    int m_Expand_Collapse_Opacity = 255;
};

#endif // DAEN_NO_KADO_H
