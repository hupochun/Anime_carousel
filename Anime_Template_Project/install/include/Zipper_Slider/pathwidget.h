#ifndef PATHWIDGET_H
#define PATHWIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPainterPath>
#include <QTimer>
#include <QMouseEvent>


class PathWidget : public QWidget
{
    Q_OBJECT

public:
    explicit PathWidget(QWidget *parent = nullptr);
    void setOffset(qreal offset);

    void Draw_Straight_Path_Square(QPainter &painter, const QPainterPath &path);
    void Draw_Curve_Path_Square(QPainter &painter, const QPainterPath &path);
    void Draw_Rectangle(QPainter &painter);
protected:
    void paintEvent(QPaintEvent *event);

    void mousePressEvent(QMouseEvent* event);         // 鼠标按下事件
    void mouseMoveEvent(QMouseEvent* event);          // 鼠标移动事件


private:
    qreal y1 = 310; //终点

    qreal xx = 150; //终点偏移
    qreal yy = 300;


    qreal xx3 = 600;
    qreal yy3 = 600;

    qreal xxx3 = 600;
    qreal yyy3 = 600;



    QTimer m_timer; // 定时器

    QPoint m_dragStartPosition;                       // 鼠标按下时的全局位置
    QPoint m_startWindowPosition;                     // 窗口初始位置
    QPoint m_lastMovePosition;

    QPoint m_totalMoveDistance;

};

#endif // PATHWIDGET_H
